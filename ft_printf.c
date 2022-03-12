/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:09:35 by cbukuba           #+#    #+#             */
/*   Updated: 2022/03/12 18:35:23 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char const *str)
{
	int	i;
	int	sign;
	int	ent;

	i = 0;
	sign = 1;
	ent = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i ++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1 ;
		i ++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		ent = ent * 10 + (str[i] - 48);
		i ++;
	}
	return (ent * sign);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i ++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	j;
	char buf[100];

	i = 0;
	j = 0;

	va_list args;
	va_start(args, str);
	while(str && str[i])
	{
		if (str[i] == '%')
			i ++;
		if (str[i] == 'c')
		{
			buf[j] = (char) va_arg(args, int);
			ft_putchar_fd(buf[j], 1);
			j ++;
			return 0;
		}
		if (str[i] == 'd')
		{
			int p = va_arg(args, int);
			ft_putnbr_fd(p, 1);
		}
		if (str[i] == 's')
		{
			char *s = va_arg(args, char *);
			ft_putstr_fd(s, 1);
		}
		i ++;
	}
	va_end(args);
	return 0;
}

int main()
{
	char p = 'C';
	char *str = "HIgor";
	int  u = -456;
	ft_printf("Je m'appel %s\n ", str);
	return 0;
}
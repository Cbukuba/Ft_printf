/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbukuba <cbukuba@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:09:35 by cbukuba           #+#    #+#             */
/*   Updated: 2022/03/10 13:52:32 by cbukuba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

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
		i ++;
	}
	va_end(args);
	return 0;
}

int main()
{
	char p = 'C';
	char *str = "HIgor";
	ft_printf("Je m'appel %c\n ", p);
	return 0;
}
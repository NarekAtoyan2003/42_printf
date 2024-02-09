/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naatoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:36:15 by naatoyan          #+#    #+#             */
/*   Updated: 2024/02/05 18:17:16 by naatoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_bayz_u(unsigned long nb, char *bayz, int bayz_len)
{
	int		i;
	int		count;
	char	str[10000];

	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = 0;
	while (nb != 0)
	{
		str[i] = bayz[nb % bayz_len];
		nb = nb / bayz_len;
		i++;
	}
	count += i;
	i--;
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
	return (count);
}

int	print(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count = ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr_bayz(va_arg(arg, int), "0123456789", 10);
	else if (c == 'u')
		count = ft_putnbr_bayz(va_arg(arg, unsigned), "0123456789", 10);
	else if (c == 'x')
		count = ft_putnbr_bayz_u(va_arg(arg, unsigned), "0123456789abcdef", 16);
	else if (c == 'X')
		count = ft_putnbr_bayz_u(va_arg(arg, unsigned), "0123456789ABCDEF", 16);
	else if (c == 'p')
	{
		count = ft_putstr("0x");
		count += ft_putnbr_bayz_u
			(va_arg(arg, unsigned long), "0123456789abcdef", 16);
	}
	else if (c == '%')
		count = ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	char	*cspd;
	va_list	arg;

	i = 0;
	count = 0;
	cspd = "cspdiuxX%";
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr(cspd, s[i + 1]))
		{
			count += print(arg, s[++i]);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
/*
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char *p = (char *)ULONG_MAX;

	ft_printf(">>%p<<", ULONG_MAX);
	printf(">>%p<<", p);
}*/

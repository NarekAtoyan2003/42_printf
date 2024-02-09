/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naatoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:14:33 by naatoyan          #+#    #+#             */
/*   Updated: 2024/02/05 18:17:36 by naatoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		i = ft_putstr("(null)");
		return (i);
	}
	i = 0;
	while (s[i])
	{
		i += ft_putchar(s[i]);
	}
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	char			ch;
	unsigned int	i;

	ch = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	ft_putnbr(char *str, char *bayz, long nb, int bayz_len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
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

int	ft_putnbr_bayz(long nb, char *bayz, int bayz_len)
{
	int		count;
	char	str[10000];

	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (LONG_MIN == nb)
	{
		ft_putstr("-9223372036854775808");
		return (20);
	}
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	count += ft_putnbr(str, bayz, nb, bayz_len);
	return (count);
}

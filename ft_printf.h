/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naatoyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:58:10 by naatoyan          #+#    #+#             */
/*   Updated: 2024/02/04 21:57:08 by naatoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_strchr(const	char *s, int c);
int		ft_printf(const char *s, ...);
int		ft_putnbr_bayz_u(unsigned long nb, char *bayz, int bayz_len);
int		ft_putnbr_bayz(long nb, char *bayz, int bayz_len);

#endif

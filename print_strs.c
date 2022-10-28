/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:13:48 by truangsi          #+#    #+#             */
/*   Updated: 2022/10/15 15:13:50 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int		i;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_print_char(va_list vlst)
{
	int	c;

	c = va_arg(vlst, int);
	return (ft_putchar(c));
}

int	ft_print_str(va_list vlst)
{
	char	*c;

	c = va_arg(vlst, char *);
	return (ft_putstr(c));
}

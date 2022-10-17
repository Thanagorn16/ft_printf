/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:32:49 by truangsi          #+#    #+#             */
/*   Updated: 2022/10/16 18:32:50 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long n)
{
	int		ret;
	int		i;
	char	str[12];

	ret = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		ret = ft_putchar('-');
		n = -n;
	}
	while (n > 0)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	ret += i;
	i--;
	while (i >= 0)
		ft_putchar(str[i--]);
	return (ret);
}

int	ft_print_nbr(va_list vlst)
{
	long long	c;

	c = va_arg(vlst, int);
	return (ft_putnbr(c));
}

int	ft_print_unint(va_list vlst)
{
	unsigned int	c;

	c = va_arg(vlst, int);
	return (ft_putnbr(c));
}

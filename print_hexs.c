/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:12:13 by truangsi          #+#    #+#             */
/*   Updated: 2022/10/19 16:12:16 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	make_char(unsigned long long n, int ret, int alpha_pos)
{
	int		remain_num;
	int		i;
	char	str[17];

	remain_num = 0;
	i = 0;
	while (n != 0)
	{
		remain_num = n % 16;
		if (remain_num < 10)
			str[i++] = remain_num + '0';
		else
			str[i++] = remain_num + alpha_pos + '7';
		n /= 16;
	}
	i--;
	while (i >= 0)
		ret += ft_putchar(str[i--]);
	return (ret);
}

int	ft_puthex(unsigned long long n, char spec, char flag)
{
	int	ret;
	int	alpha_pos;

	alpha_pos = 0;
	if (spec == 'x' || spec == 'p')
		alpha_pos = 32;
	ret = 0;
	if (spec == 'p')
		while (ret < 1)
			ret += ft_putstr("0x");
	if (n == 0)
		return (ret += ft_putchar('0'));
	if (flag && spec != 'p')
	{
		if (spec == 'X')
			ret += ft_putstr("0X");
		else
			ret += ft_putstr("0x");
	}
	ret = make_char(n, ret, alpha_pos);
	return (ret);
}

int	ft_print_hex(va_list vlst, char spec, char flag)
{
	long long	n;

	if (spec == 'p')
		n = va_arg(vlst, long long);
	else
		n = va_arg(vlst, unsigned int);
	return (ft_puthex(n, spec, flag));
}

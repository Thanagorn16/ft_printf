/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:43:02 by truangsi          #+#    #+#             */
/*   Updated: 2022/10/12 15:43:03 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int n)
{
	// int	quotient;
	int	remain_num;
	int	i;
	int	ret;
	char	str[12];

	ret = -1;
	while (n != 0)
	{
		remain_num = n % 16;
		// printf("re:%d\n", remain_num);
		if (n < 10)
		{
			str[i++] = remain_num + '0';
			// printf("in:%c\n", str[i]);
		}
		else
		{
			str[i++] = remain_num + '7';
			// printf("[`0]:%c\n", str[0]);
			// printf("in2:%c\n", str[0]);
		}
		n /= 16;
		// printf("%s\n")
	}
	// printf("here:%s\n", str);
	// printf("%d\n", i);
	while (i >= 0)
		ret += ft_putchar(str[i--]);
	return (ret);
}

int	ft_print_hex(va_list vlst)
{
	int	n;

	n = va_arg(vlst, int);
	return (ft_puthex(n));
}

int	check_specifier(va_list vlst, char spec, int save)
{
	int	ret;

	ret = save;
	if (spec == 'c')
		ret += ft_print_char(vlst);
	// printf("\nretbefore:%d\n", ret);
	if (spec == 's')
		ret += ft_print_str(vlst);
	if (spec == 'd')
		ret += ft_print_nbr(vlst);
	if (spec == 'i')
		ret += ft_print_nbr(vlst);
	if (spec == 'u')
		ret += ft_print_unint(vlst);
	if (spec == 'x')
		ret += ft_print_hex(vlst);
	// printf("\nret:%d\n", ret);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int	i;
	int	ret;
	int	save;
	size_t	len;

	i = 0;
	len = 0;
	ret = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			save = ret;
			ret = check_specifier(ptr, format[i + 1], save);
		}
		else if (format[i] != '%' && format[i - 1] != '%')
		{
			// printf("\nhere:%c\n", format[i]);
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(ptr);
	// printf("\nlen:%lu\n", len);
	// printf("ret:%d\n", rt);
	return (ret + len);
}

// int	main(void)
// {
// 	int	e;
// 	int	f;
// 	// char	a = '0';
// 	// int *ptr;
// 	e = printf("%X", 64250);
// 	printf("\n%d\n", e);
// 	puts("------------");
// 	f = ft_printf("%x", 64250);
// 	printf("\n%d\n", f);
// 	// e = printf("%d", 12354);
// 	// printf("\n$%d", e);
// 	// printf("\n%d\n", ft_putnbr(1234));
// 	// e = 10;
// 	// printf("%c\n", e + '7');
// 	// ft_puthex(64250);
// }


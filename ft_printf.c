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
// 	e = printf(" %d ", 81);
// 	printf("\n%d\n", e);
// 	puts("------------");
// 	f = ft_printf(" %d ", 81);
// 	printf("\n%d\n", f);
// 	// e = printf("%d", 12354);
// 	// printf("\n$%d", e);
// 	// printf("\n%d\n", ft_putnbr(1234));
// }


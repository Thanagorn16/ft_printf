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
	if (spec == 's')
		ret += ft_print_str(vlst);
	if (spec == 'd')
		ret += ft_print_nbr(vlst);
	if (spec == 'i')
		ret += ft_print_nbr(vlst);
	if (spec == 'u')
		ret += ft_print_unint(vlst);
	if (spec == 'x' || spec == 'X' || spec == 'p')
		ret += ft_print_hex(vlst, spec);
	if (spec == '%')
		return (ret);
	return (ret - 1);
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
			if (format[i + 1] == '%')
			{
				ft_putchar(format[i]);
				if (format[i] != '%' && format[i] != '\0')
					ft_putchar(format[i]);
			}
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
		ret++;
	}
	va_end(ptr);
	return (ret);
}

// int	main(void)
// {
// 	int	e;
// 	int	f;

// 	e = printf(" %%%% |");
// 	e = printf("\n%d\n", e);
// 	f = ft_printf(" %%%% |");
// 	f = printf("\n%d\n", f);
// 	// e = printf(" %c|", '0' - 256);
// 	// e = printf("\n%d\n", e);
// 	// f = ft_printf(" %c|", '0' - 256);
// 	// f = printf("\n%d\n", f);
// 	// e = printf("%%");
// 	// e = printf("\n%d\n", e);
// 	// f = ft_printf("%%");
// 	// f = printf("\n%d\n", f);
// 	// e = printf("%p", LONG_MIN);
// 	// printf("\n%d\n", e);
// 	// e = printf(" %x ", ptr);
// 	// printf("\n%d\n", e);
// 	// puts("------------");
// 	// f = ft_printf("%p", LONG_MIN);
// 	// printf("\n%d\n", f);
// 	// e = printf("%d", 12354);
// 	// printf("\n$%d", e);
// 	// printf("\n%d\n", ft_putnbr(1234));
// 	// e = 10;
// 	// printf("%c\n", e + '7');
// }

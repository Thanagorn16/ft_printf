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

int	check_specifier(va_list vlst, char spec, int save, char flag)
{
	int	ret;

	ret = save;
	if (spec == 'c')
		ret += ft_print_char(vlst);
	if (spec == 's')
		ret += ft_print_str(vlst);
	if (spec == 'd' || spec == 'i')
		ret += ft_print_nbr(vlst, flag);
	// if (spec == 'i')
	// 	ret += ft_print_nbr(vlst);
	if (spec == 'u')
		ret += ft_print_unint(vlst, flag);
	if (spec == 'x' || spec == 'X' || spec == 'p')
		ret += ft_print_hex(vlst, spec, flag);
	if (spec == '%')
		return (ret);
	return (ret - 1);
}

char	check_flag(char flag)
{
	char	save_flag;

	save_flag = 0;
	if (flag == '#')
		save_flag = flag;
	else if (flag == '+')
		save_flag = flag;
	else if (flag == ' ')
		save_flag = flag;
	return (save_flag);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int	i;
	int	ret;
	int	save;
	char	flag;

	i = 0;
	ret = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] == '#' || format[i] == '+' || format[i] == ' ')
			{
				flag = check_flag(format[i]);
				i++;
			}
			if (flag == ' ')
			{
				while (format[i] != 's' && format[i] != 'd' && format[i] != 'i')
				{
					i++;
					ret += ft_putchar(' ');
				}
			}
			// flag = check_flag(format[i + 1]);
			// if (flag != 0)
			// {
			// 	i++;
			// 	// while (format[i + 1] == flag)
			// 	// 	i++;
			// 	// if (flag == ' ' && format[i + 1] == '+')
			// 	// {
			// 	// 	flag = format[i + 1];
			// 	// 	i++;
			// 	// }
			// }
			save = ret;
			// printf("ret:%d\n", ret);
			ret = check_specifier(ptr, format[i], save, flag);
			if (format[i] == '%')
			{
				ft_putchar(format[i]);
				if (format[i] != '%' && format[i] != '\0')
					ft_putchar(format[i]);
			}
			// i++;
		}
		else
			ft_putchar(format[i]);
		i++;
		ret++;
		// printf("ret:%d\n", ret);
	}
	va_end(ptr);
	return (ret);
}

// int	main(void)
// {
// 	int	e;
// 	int	f;

// 	e = 65123;
// 	f = 65123;
// 	int	a;
// 	// printf("%d\n", a);
// 	// printf("%x\n", e);
// 	e = printf("%x", 10);
// 	printf("\nhere:%d\n", e);
// 	puts("------------");
// 	f = ft_printf("%x", 10);
// 	printf("\nhere:%d\n", f);
// 	// printf("\nhere:%d\n", f);

// 	// ft_printf("%x\n", e);
// 	// f = ft_printf(" %#x ", f);
// 	// printf("\nhere:%d\n", f);
// 	// e = printf(" %%%% |");
// 	// e = printf("\n%d\n", e);
// 	// f = ft_printf(" %%%% |");
// 	// f = printf("\n%d\n", f);
// }

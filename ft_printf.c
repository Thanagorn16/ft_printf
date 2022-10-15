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

int	ft_putstr(char *s)
{
	int	i;
	char	*null;

	null = "(null)";
	if (!s)
	{
		write(1, "(null)", 6);
		return (strlen(null));
	}
		// return (0);
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_print_str(va_list vlst)
{
	int	i;
	char	*c;

	i = 0;
	c = va_arg(vlst, char *);
	return (ft_putstr(c));
}

// int	check_specifier(va_list vlst, char spec, size_t len)
int	check_specifier(va_list vlst, char spec, int save)
{
	int	ret;

	// ret = len - 1;
	ret = save;
	// if (spec == ' ')
	// 	ret--;
	if (spec == 'c')
		ret += ft_print_char(vlst);
	// printf("\nretbefore:%d\n", ret);
	if (spec == 's')
		ret += ft_print_str(vlst);
	// printf("\nret:%d\n", ret);
	// if (len == 0)
	// 	ret++;
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
			// ret = check_specifier(ptr, format[i + 1], len);
			ret = check_specifier(ptr, format[i + 1], save);
			// save = ret;
		}
		// else if (format[i] != '%' && format[i - 1] != '%')
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
	// printf("ret:%d\n", ret);
	return (ret + len);
}

// int	main(void)
// {
// 	int	e;
// 	int	f;
// 	// e = printf("%c", '0');
// 	// printf("\n%d\n", e);
// 	// f = ft_printf("%c", '0');
// 	// printf("\n%d\n", f);
// 	// e = printf(" %c %c %c ", '0', 0, '1');
// 	// printf("\n%d\n", e);
// 	// f = ft_printf(" %c %c %c ", '0', 0, '1');
// 	// printf("\n%d\n", f);
// 	e = printf(" NULL %s NULL ", NULL);
// 	printf("\n%d\n", e);
// 	// e = printf(" %s %s ", "", NULL);
// 	// printf("\n%d\n", e);
// 	f = ft_printf(" NULL %s NULL ", NULL);
// 	printf("\n%d\n", f);
// 	// f = ft_printf(" %s %s ", "", "hello");
// 	// printf("\n%d\n", f);
// }

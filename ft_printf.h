/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:45:48 by truangsi          #+#    #+#             */
/*   Updated: 2022/10/12 15:45:50 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_print_char(va_list vlst);
int		ft_putstr(char *s);
int		ft_print_str(va_list vlst);
int		ft_putnbr(long long n, char flag);
int		ft_print_nbr(va_list vlst, char flag);
int		ft_print_unint(va_list vlst, char flag);
int		make_char(unsigned long long n, int ret, int alpha_pos);
int		ft_puthex(unsigned long long n, char spec, char flag);
int		ft_print_hex(va_list vlst, char spec, char flag);
char	check_flag(char flag);

#endif

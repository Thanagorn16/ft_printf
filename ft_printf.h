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

#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_print_char(va_list vlst);
int	ft_putstr(char *s);
int	ft_print_str(va_list vlst);
int	ft_putnbr(int n);
int	ft_print_nbr(va_list vlst);

#endif

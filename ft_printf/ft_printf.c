/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:15:29 by efournou          #+#    #+#             */
/*   Updated: 2022/06/13 17:17:36 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	ft_print_param(const char *string, int *size, va_list argument,
		int index)
{
	if (string[index + 1] == 'c')
		ft_putchar_nret(va_arg(argument, int), size);
	else if (string[index + 1] == 's')
		ft_putstr_f(va_arg(argument, char *), size);
	else if (string[index + 1] == 'p')
	{
		ft_putstr_f("0x", size);
		ft_print_maj_hexa(va_arg(argument, unsigned long long), size,
			"0123456789abcdef");
	}
	else if ((string[index + 1] == 'd') || (string[index + 1] == 'i'))
		ft_putnbr_f(va_arg(argument, int), size);
	else if (string[index + 1] == 'u')
		ft_put_unsigned_nbr(va_arg(argument, unsigned int), size);
	else if (string[index + 1] == 'x')
		ft_print_maj_hexa(va_arg(argument, unsigned int), size,
			"0123456789abcdef");
	else if (string[index + 1] == 'X')
		ft_print_maj_hexa(va_arg(argument, unsigned int), size,
			"0123456789ABCDEF");
	else if (string[index + 1] == '%')
		ft_putchar_nret('%', size);
}

int	ft_printf(const char *str, ...)
{
	va_list	argument;
	int		index;
	int		size;

	size = 0;
	index = 0;
	va_start(argument, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			ft_print_param(str, &size, argument, index);
			index++;
		}
		else
			ft_putchar_nret(str[index], &size);
		index++;
	}
	va_end(argument);
	return (size);
}

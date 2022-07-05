/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:50:06 by efournou          #+#    #+#             */
/*   Updated: 2022/06/12 23:50:02 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_f(int number, int *size)
{
	long long	long_number;

	long_number = (long long)number;
	if (long_number < 0)
	{
		ft_putchar_nret('-', size);
		long_number *= -1;
	}
	if (long_number >= 10)
	{
		ft_putnbr_f(long_number / 10, size);
		long_number %= 10;
	}
	ft_putchar_nret(long_number + '0', size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:50:06 by efournou          #+#    #+#             */
/*   Updated: 2022/06/13 00:03:08 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr(unsigned int number, int *size)
{
	if (number >= 10)
	{
		ft_put_unsigned_nbr(number / 10, size);
		number %= 10;
	}
	ft_putchar_nret(number + '0', size);
}

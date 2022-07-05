/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_maj_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:15:09 by efournou          #+#    #+#             */
/*   Updated: 2022/06/13 00:00:10 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_maj_hexa(unsigned long long number, int *size, char *base)
{
	if (number >= 16)
		ft_print_maj_hexa(number / 16, size, base);
	ft_putchar_nret(base[number % 16], size);
}

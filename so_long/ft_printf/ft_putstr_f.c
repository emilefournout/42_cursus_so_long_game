/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:46:53 by efournou          #+#    #+#             */
/*   Updated: 2022/06/12 23:59:08 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_f(char *string, int *size)
{
	int	index;

	if (!string)
	{
		ft_putstr_f("(null)", size);
		return ;
	}
	index = 0;
	while (string[index])
	{
		ft_putchar_nret(string[index++], size);
	}
}

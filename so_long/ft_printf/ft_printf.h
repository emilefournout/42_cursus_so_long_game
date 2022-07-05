/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 01:15:48 by efournou          #+#    #+#             */
/*   Updated: 2022/06/12 23:48:52 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_maj_hexa(unsigned long long number, int *size, char *base);
void	ft_putnbr_f(int number, int *size);
void	ft_putstr_f(char *string, int *size);
void	ft_put_unsigned_nbr(unsigned int number, int *size);
void	ft_putchar_nret(char character, int *size);

#endif

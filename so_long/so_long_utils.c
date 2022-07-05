/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:11:38 by efournou          #+#    #+#             */
/*   Updated: 2022/06/24 08:34:53 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	index;

	index = 0;
	while (map[index] != NULL)
	{
		free(map[index]);
		index++;
	}
	free(map);
}

int	exit_success(char **map)
{
	free_map(map);
	exit(0);
}

void	exit_error(char *message, int code_exit, char **map_tab)
{
	if (map_tab != NULL)
		free_map(map_tab);
	ft_printf("%s\n", message);
	exit(code_exit);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (0);
	while (s1[counter] != '\0' && s2[counter] != '\0'
		&& s1[counter] == s2[counter] && counter < n - 1)
		counter++;
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}

void	check_argv(int argc, char **argv)
{
	if (argc < 2)
		exit_error("Error\nNot enought argument", 1, NULL);
	if (argc > 2)
		exit_error("Error\nToo much argument", 1, NULL);
	if (ft_strncmp(argv[1], "/dev/urandom", 12) == 0)
		exit_error("Error\nUrandom file not valid", 1, NULL);
	if (ft_strncmp(argv[1], "/dev/null", 9) == 0)
		exit_error("Error\nNULL file not valid", 1, NULL);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		exit_error("Error\nMap File extension must be .ber", 1, NULL);
}

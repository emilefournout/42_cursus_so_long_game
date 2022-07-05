/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 02:18:21 by efournou          #+#    #+#             */
/*   Updated: 2022/06/28 11:13:27 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	add_stat(char **map_tab, int index, t_stat *stat)
{
	int	position;

	position = 0;
	while (map_tab[index][position] != '\n' && map_tab[index][position] != '\0')
	{
		if (map_tab[index][position] == 'C')
			stat->objectif++;
		if (map_tab[index][position] == 'P')
		{
			stat->player_pos.x = position;
			stat->player_pos.y = index;
		}
		position++;
	}
}

void	check_map_valid_and_add_stat(char **map_tab, int number_line,
		t_stat *stat)
{
	int	index;
	int	lenght_first_line;
	int	size;

	index = 0;
	lenght_first_line = ft_strlen(map_tab[0]);
	while (map_tab[index] != NULL)
	{
		if (index == 0 || index == number_line - 1)
			check_first_and_last_line(map_tab[index], index);
		size = ft_strlen(map_tab[index]);
		if (index > 0 && size != lenght_first_line && index < number_line - 1)
			exit(1);
		else if (index > 0 && size != lenght_first_line - 1
			&& index == number_line - 1)
			exit(1);
		if (map_tab[index][0] != '1' || map_tab[index][lenght_first_line
			- 2] != '1')
			exit_error("Error\nThe map must be surrounded by a wall",
				1, map_tab);
		add_stat(map_tab, index, stat);
		index++;
	}
}

char	**parse_map(char *map_path, int number_line, t_stat *stat)
{
	int		fd;
	char	**map_tab;
	int		index;

	index = 0;
	map_tab = (char **)malloc(sizeof(char *) * (number_line + 1));
	fd = open(map_path, O_RDONLY);
	while (1)
	{
		map_tab[index] = get_next_line(fd);
		if (map_tab[index] == NULL)
			break ;
		index++;
	}
	close(fd);
	check_map_valid_and_add_stat(map_tab, number_line, stat);
	return (map_tab);
}

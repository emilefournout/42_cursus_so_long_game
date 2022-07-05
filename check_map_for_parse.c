/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_for_parse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:27:45 by efournou          #+#    #+#             */
/*   Updated: 2022/06/28 11:09:21 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_first_and_last_line(char *line, int line_number)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] != '1' && line[index] != '\n' && line_number == 0)
			exit_error("Error\nThe map must be surrounded by a wall", 1, NULL);
		else if (line[index] != '1' && line[index] != '\n')
			exit_error("Error\nThe map must be surrounded by a wall", 1, NULL);
		index++;
	}
}

static int	read_and_check_block(int fd, char buffer[1])
{
	int	return_read;

	return_read = read(fd, &buffer[0], 1);
	if ((buffer[0] != '1' && buffer[0] != '\n' && buffer[0] != '0'
			&& buffer[0] != 'E' && buffer[0] != 'P' && buffer[0] != 'C')
		|| return_read == -1)
		exit_error("Error\n Problem parsing the map", 1, NULL);
	return (return_read);
}

int	count_line_and_check(char *map_path)
{
	int			fd;
	int			number_line;
	int			return_read;
	char		buffer[1];
	static int	count_p;

	number_line = 1;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error("Error\nMap file not found", 1, NULL);
	return_read = read_and_check_block(fd, buffer);
	while (return_read == 1)
	{
		if (buffer[0] == '\n')
			number_line++;
		return_read = read_and_check_block(fd, buffer);
		if (buffer[0] == 'P')
			count_p++;
	}
	if (count_p != 1)
		exit_error("Error\nProblem of player number", 1, NULL);
	close(fd);
	return (number_line);
}

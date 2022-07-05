/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 02:22:49 by efournou          #+#    #+#             */
/*   Updated: 2022/06/23 09:12:35 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_color(t_image img, int pixel, int color, char *buffer)
{
	if (img.endian == 1)
	{
		buffer[pixel + 0] = (color >> 24);
		buffer[pixel + 1] = (color >> 16) & 0xFF;
		buffer[pixel + 2] = (color >> 8) & 0xFF;
		buffer[pixel + 3] = (color) & 0xFF;
	}
	else if (img.endian == 0)
	{
		buffer[pixel + 0] = (color) & 0xFF;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24);
	}
}

void	print_color(int color, t_image img, void *mlx)
{
	int		y;
	int		x;
	int		pixel;
	char	*buffer;

	buffer = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	y = 0;
	x = 0;
	if (img.bits_per_pixel != 32)
		color = mlx_get_color_value(mlx, color);
	while (y < 50)
	{
		while (x < 50)
		{
			pixel = (y * img.line_size) + (x * 4);
			put_color(img, pixel, color, buffer);
			x++;
		}
		x = 0;
		y++;
	}
}

void	declare_img_struct(t_vars *vars, t_map_img *img, char **map_tab)
{
	img->player.reference = mlx_xpm_file_to_image(vars->mlx, "texture/moi.xpm",
			&img->player.size.x, &img->player.size.y);
	img->piece.reference = mlx_xpm_file_to_image(vars->mlx, "texture/piece.xpm",
			&img->piece.size.x, &img->piece.size.y);
	img->wall.reference = mlx_new_image(vars->mlx, 50, 50);
	img->start_pos.reference = mlx_new_image(vars->mlx, 50, 50);
	img->free_space.reference = mlx_new_image(vars->mlx, 50, 50);
	img->exit.reference = mlx_new_image(vars->mlx, 50, 50);
	if (!img->player.reference || !img->piece.reference || !img->wall.reference
		|| !img->start_pos.reference || !img->free_space.reference
		|| !img->exit.reference)
		exit_error("Error\n Probleme creating image", 1, map_tab);
	print_color(0xE92626, img->start_pos, vars->mlx);
	print_color(0xFFFFFF, img->free_space, vars->mlx);
	print_color(0x4C57E7, img->wall, vars->mlx);
	print_color(0x3AE242, img->exit, vars->mlx);
}

void	put_image(char **map_tab, t_vars *vars, t_map_img *img, t_vector index)
{
	if (map_tab[index.y][index.x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall.reference,
			index.x * 50, index.y * 50);
	if (map_tab[index.y][index.x] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, img->free_space.reference,
			index.x * 50, index.y * 50);
	if (map_tab[index.y][index.x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img->start_pos.reference,
			index.x * 50, index.y * 50);
		mlx_put_image_to_window(vars->mlx, vars->win, img->player.reference,
			index.x * 50, index.y * 50);
	}
	if (map_tab[index.y][index.x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, img->exit.reference,
			index.x * 50, index.y * 50);
	if (map_tab[index.y][index.x] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img->free_space.reference,
			index.x * 50, index.y * 50);
		mlx_put_image_to_window(vars->mlx, vars->win, img->piece.reference,
			index.x * 50 + 5, index.y * 50 + 5);
	}
}

void	render_map(char **map_tab, t_vars *vars, t_map_img *img)
{
	t_vector	index;

	index.x = 0;
	index.y = 0;
	while (map_tab[index.y] != NULL)
	{
		while (map_tab[index.y][index.x] != '\n'
			&& map_tab[index.y][index.x] != '\0')
		{
			put_image(map_tab, vars, img, index);
			index.x++;
		}
		index.x = 0;
		index.y++;
	}
}

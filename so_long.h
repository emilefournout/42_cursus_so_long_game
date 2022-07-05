/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:15:10 by efournou          #+#    #+#             */
/*   Updated: 2022/06/24 08:28:09 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;
typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_map_img
{
	t_image		wall;
	t_image		start_pos;
	t_image		free_space;
	t_image		exit;
	t_image		piece;
	t_image		player;
}				t_map_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img_ref;
}				t_vars;

typedef struct s_stat
{
	t_vector	player_pos;
	t_vector	win_pos;
	int			objectif;
	int			score;
	int			move_count;
}				t_stat;
typedef struct s_solong
{
	t_map_img	img;
	t_vars		vars;
	t_stat		stat;
	char		**map_tab;
}				t_solong;

void			render_map(char **map_tab, t_vars *vars, t_map_img *img);
void			declare_img_struct(t_vars *vars, t_map_img *img,
					char **map_tab);
int				count_line_and_check(char *map_path);
void			check_first_and_last_line(char *line, int line_number);
void			check_map_valid_and_add_stat(char **map_tab, int number_line,
					t_stat *stat);
char			**parse_map(char *map_path, int number_line, t_stat *stat);
int				key_hook(int keycode, t_solong *solong);
void			exit_error(char *message, int code_exit, char **map_tab);
void			free_map(char **map);
int				exit_success(char **map);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
void			check_argv(int argc, char **argv);

#endif
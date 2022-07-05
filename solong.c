/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efournou <efournou@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:26:44 by efournou          #+#    #+#             */
/*   Updated: 2022/06/28 11:04:12 by efournou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_pos(char **map_tab, int x, int y)
{
	if (map_tab[y][x] == '0' || map_tab[y][x] == 'P' ||
		map_tab[y][x] == 'E')
		return (1);
	if (map_tab[y][x] == 'C')
		return (2);
	return (0);
}

void	move_player(t_solong *solong, t_vector next_pos)
{
	void	*to_print;

	if (solong->map_tab[solong->stat.player_pos.y]
		[solong->stat.player_pos.x] == 'E')
		to_print = solong->img.exit.reference;
	else if (solong->map_tab[solong->stat.player_pos.y]
		[solong->stat.player_pos.x] == 'P')
		to_print = solong->img.start_pos.reference;
	else
		to_print = solong->img.free_space.reference;
	mlx_put_image_to_window(solong->vars.mlx, solong->vars.win, to_print,
		solong->stat.player_pos.x * 50, solong->stat.player_pos.y * 50);
	mlx_put_image_to_window(solong->vars.mlx, solong->vars.win,
		solong->img.player.reference, next_pos.x * 50, next_pos.y * 50);
}

t_vector	next_pos_init(int keycode, t_vector player_pos)
{
	t_vector	next_pos;

	next_pos = player_pos;
	if (keycode == 13 || keycode == 126)
		next_pos.y--;
	if (keycode == 0 || keycode == 123)
		next_pos.x--;
	if (keycode == 1 || keycode == 125)
		next_pos.y++;
	if (keycode == 2 || keycode == 124)
		next_pos.x++;
	return (next_pos);
}

int	key_hook(int keycode, t_solong *solong)
{
	int			next_case_avaibility;
	t_vector	next_pos;

	if (keycode == 53)
		exit_success(solong->map_tab);
	next_case_avaibility = 0;
	next_pos = next_pos_init(keycode, solong->stat.player_pos);
	next_case_avaibility = check_pos(solong->map_tab, next_pos.x, next_pos.y);
	if (next_case_avaibility == 2)
	{
		solong->stat.score++;
		solong->map_tab[next_pos.y][next_pos.x] = '0';
	}
	if (next_case_avaibility > 0)
	{
		move_player(solong, next_pos);
		solong->stat.player_pos = next_pos;
		ft_printf("%i\n", solong->stat.move_count++);
	}
	if (solong->stat.objectif == solong->stat.score
		&& solong->map_tab[solong->stat.player_pos.y]
		[solong->stat.player_pos.x] == 'E')
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	int			number_line;
	t_solong	solong;

	check_argv(argc, argv);
	solong.stat.objectif = 0;
	solong.stat.player_pos.x = 0;
	solong.stat.player_pos.y = 0;
	solong.stat.score = 0;
	solong.stat.move_count = 1;
	number_line = count_line_and_check(argv[1]);
	solong.map_tab = parse_map(argv[1], number_line, &solong.stat);
	solong.vars.mlx = mlx_init();
	solong.vars.win = mlx_new_window(solong.vars.mlx,
			(ft_strlen(solong.map_tab[0]) - 1) * 50,
			number_line * 50, "solong");
	declare_img_struct(&solong.vars, &solong.img, solong.map_tab);
	render_map(solong.map_tab, &solong.vars, &solong.img);
	mlx_hook(solong.vars.win, 17, 0, exit_success, solong.map_tab);
	mlx_key_hook(solong.vars.win, key_hook, &solong);
	mlx_loop(solong.vars.mlx);
}

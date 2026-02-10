/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:38:05 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/10 12:25:34 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	init_map(const char *filename)
{
	t_map	map;

	map.map = read_map(filename, &map.rows, &map.cols);
	check_shape(&map);
	check_walls(&map);
	check_content(&map);
	flood_fill_check(&map);
	return (map);
}

static void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->map.player_x = x;
				game->map.player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game, t_map map)
{
	game->map = map;
	game->moves = 0;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("MLX init failed");

	game->win = mlx_new_window(game->mlx,
			game->map.cols * 64,
			game->map.rows * 64,
			"so_long");
	if (!game->win)
		ft_error("Window creation failed");

	find_player(game);
}


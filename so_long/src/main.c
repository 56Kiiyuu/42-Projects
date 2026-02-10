/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:40:30 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 16:28:20 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	if (argc != 2)
		ft_error("Usage: ./so_long map.ber");

	map = init_map(argv[1]);
	flood_fill_check(&map);

	init_game(&game, map);
	load_images(&game);

	mlx_hook(game.win, 2, 1L<<0, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);

	return (0);
}

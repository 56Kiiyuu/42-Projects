/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:44:54 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/12 16:19:13 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_game(char *file)
{
	t_game	so_long;

	ft_bzero(&so_long, sizeof(t_game));
	read_map(&so_long, file);
	check_map(&so_long);
	launch_mlx(&so_long, so_long.map);
	load_assets(&so_long);
	render_map(&so_long, so_long.map);
	mlx_hook(so_long.display.win, 2, (1L << 0), check_keypress, &so_long);
	mlx_hook(so_long.display.win, 17, (1L << 17), quit_game, &so_long);
	mlx_loop_hook(so_long.display.mlx, render_move, &so_long);
	mlx_loop(so_long.display.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments.");
	check_filename(av[1]);
	launch_game(av[1]);
}

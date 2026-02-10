/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:29:50 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/10 13:28:21 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int key_handler(int key, t_game *game)
{
	if (key == 65307) // ESC
		return (close_window(game));
	if (key == 'w' || key == 119)
		update_player_position(game, 0, -1);
	if (key == 's' || key == 115)
		update_player_position(game, 0, 1);
	if (key == 'a' || key == 97)
		update_player_position(game, -1, 0);
	if (key == 'd' || key == 100)
		update_player_position(game, 1, 0);
	return (0);
}


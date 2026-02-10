/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:12:13 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 16:15:36 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_map(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			tile = game->map.map[y][x];
			if (tile == '1')
				draw_tile(game, game->wall, x, y);
			else if (tile == '0')
				draw_tile(game, game->floor, x, y);
			else if (tile == 'P')
				draw_tile(game, game->player, x, y);
			else if (tile == 'C')
				draw_tile(game, game->collectible, x, y);
			else if (tile == 'E')
				draw_tile(game, game->exit, x, y);
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:43:49 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 16:19:09 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_player_position(t_game *game, int dx, int dy)
{
	int		next_x = game->map.player_x + dx;
	int		next_y = game->map.player_y + dy;
	char	next_tile;

	if (next_x < 0 || next_x >= game->map.cols
		|| next_y < 0 || next_y >= game->map.rows)
		return ; // en dehors de la map

	next_tile = game->map.map[next_y][next_x];

	if (next_tile == '1')
		return ; // mur, pas de mouvement
	else if (next_tile == 'C')
	{
		game->map.collectible_count--;
		game->map.map[next_y][next_x] = '0';
	}
	else if (next_tile == 'E')
	{
		if (game->map.collectible_count == 0)
		{
			ft_printf("You win in %d moves!\n", game->moves + 1);
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		else
			return ; // sortie verrouillée
	}

	// Déplacer le joueur sur la map
	game->map.map[game->map.player_y][game->map.player_x] = '0';
	game->map.map[next_y][next_x] = 'P';
	game->map.player_x = next_x;
	game->map.player_y = next_y;

	game->moves++;
	ft_printf("Moves: %d\n", game->moves);

	// Redessiner la map après le déplacement
	render_map(game);
}

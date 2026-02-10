/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:09:15 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 14:46:09 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_content(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->map)
		ft_error("Error: map not loaded");

	map->player_count = 0;
	map->exit_count = 0;
	map->collectible_count = 0;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
				map->player_count++;
			else if (map->map[i][j] == 'E')
				map->exit_count++;
			else if (map->map[i][j] == 'C')
				map->collectible_count++;
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				ft_error("Error: invalid character in map");
			j++;
		}
		i++;
	}
	if (map->player_count != 1)
		ft_error("Error: there must be exactly 1 player");
	if (map->exit_count != 1)
		ft_error("Error: there must be exactly 1 exit");
	if (map->collectible_count < 1)
		ft_error("Error: there must be at least 1 collectible");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:43:43 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/10 12:51:07 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdlib.h>

// flood fill sur la copie de la map, compte localement C et E atteignables
static void	flood_fill(char **map_copy, int x, int y)
{
	if (!map_copy || x < 0 || y < 0)
		return ;
	if (!map_copy[x] || !map_copy[x][y])
		return ;
	if (map_copy[x][y] == '1' || map_copy[x][y] == 'V')
		return ;

	map_copy[x][y] = 'V';

	flood_fill(map_copy, x + 1, y);
	flood_fill(map_copy, x - 1, y);
	flood_fill(map_copy, x, y + 1);
	flood_fill(map_copy, x, y - 1);
}

// copie de la map
static char	**copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * map->rows);
	if (!copy)
		ft_error("Error: malloc failed");

	i = 0;
	while (i < map->rows)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
			ft_error("Error: malloc failed");
		i++;
	}
	return (copy);
}

void	flood_fill_check(t_map *map)
{
	char	**map_copy;
	int		x;
	int		y;
	int		found;

	map_copy = copy_map(map);

	// trouver la position du joueur
	x = 0;
	found = 0;
	while (x < map->rows && !found)
	{
		y = 0;
		while (y < map->cols && !found)
		{
			if (map->map[x][y] == 'P')
				found = 1;
			else
				y++;
		}
		if (!found)
			x++;
	}

	// flood fill sur la copie
	flood_fill(map_copy, x, y);

	// vérifier si tous les collectibles et l'exit sont atteignables
	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->cols)
		{
			if (map_copy[x][y] == 'C')
				ft_error("Error: not all collectibles are reachable");
			if (map_copy[x][y] == 'E')
				ft_error("Error: exit is not reachable");
			y++;
		}
		free(map_copy[x]);
		x++;
	}
	free(map_copy);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:02:40 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 14:46:11 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_first_last_line(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols)
	{
		if (map->map[0][i] != '1' || map->map[map->rows - 1][i] != '1')
			ft_error("Error: top or bottom wall missing");
		i++;
	}
}

static void	check_first_last_column(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
			ft_error("Error: side wall missing");
		i++;
	}
}

void	check_walls(t_map *map)
{
	if (!map || !map->map)
		ft_error("Error: map not loaded");

	check_first_last_line(map);
	check_first_last_column(map);
}

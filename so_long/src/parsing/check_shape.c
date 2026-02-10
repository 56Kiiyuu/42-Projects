/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:56:45 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 14:46:10 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_shape(t_map *map)
{
	int	i;
	int	len;

	if (!map || !map->map)
		ft_error("Error: map not loaded");

	len = ft_strlen(map->map[0]);
	i = 1;
	while (i < map->rows)
	{
		if ((int)ft_strlen(map->map[i]) != len)
			ft_error("Error: map is not rectangular");
		i++;
	}
	map->cols = len;
}

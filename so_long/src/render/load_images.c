/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:24:04 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/10 13:07:02 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_img	load_img(t_game *g, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(g->mlx, path, &img.width, &img.height);
	if (!img.img)
		ft_error("Failed to load texture");
	return (img);
}

void	load_images(t_game *game)
{
	game->wall = load_img(game, "textures/wall.xpm");
	game->floor = load_img(game, "textures/floor.xpm");
	game->player = load_img(game, "textures/player.xpm");
	game->exit = load_img(game, "textures/exit.xpm");
	game->collectible = load_img(game, "textures/collectible.xpm");
}


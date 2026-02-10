/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:12:11 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/10 12:29:49 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		player_x;
	int		player_y;

}	t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	player;
	t_img	wall;
	t_img	floor;
	t_img	exit;
	t_img	collectible;
	int		moves;
}	t_game;

// parsing
char	**read_map(const char *filename, int *rows, int *cols);
void	check_shape(t_map *map);
void	check_content(t_map *map);
void	check_walls(t_map *map);
void	flood_fill_check(t_map *map);

// utils
void	ft_error(const char *msg);
t_map	init_map(const char *filename);

// game
void	init_game(t_game *game, t_map map);
int		all_collectibles_collected(t_game *game);
int		close_window(t_game *game);
int		key_handler(int key, t_game *game);
int		game_loop(t_game *game);
void	update_player_position(t_game *game, int dx, int dy);

// render
void	load_images(t_game *game);
void	draw_tile(t_game *game, t_img img, int x, int y);
void	render_map(t_game *game);
#endif


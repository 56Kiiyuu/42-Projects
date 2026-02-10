/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:42:45 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 16:08:18 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	win_game(t_game *game)
{
	ft_printf("Congratulations! You collected all items \
		 in %d moves!\n", game->moves);
	close_window(game);
}

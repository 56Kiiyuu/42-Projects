/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:49:33 by kevlim            #+#    #+#             */
/*   Updated: 2026/02/09 14:46:13 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**read_map(const char *filename, int *rows, int *cols)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error: cannot open map file");
/* compter les lignes */
	*rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		(*rows)++;
		free(line);
		line = get_next_line(fd);
	}
	if (*rows == 0)
		ft_error("Error: empty map");
	close(fd);
/* rouvrir pour lire et stocker */
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("Error: cannot reopen map file");
	map = malloc(sizeof(char *) * (*rows + 1));
	if (!map)
		ft_error("Error: malloc failed");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0'; // enlever \n
		map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	*cols = ft_strlen(map[0]);
	close(fd);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:33:07 by kevlim            #+#    #+#             */
/*   Updated: 2025/12/03 14:36:17 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	//int		fd;
	char	*line;

	//fd = open("files/read_error.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(1);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}

}

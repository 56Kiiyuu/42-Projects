/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:15:38 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/30 16:57:29 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str, int output)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(output, &str[i], 1);
		i++;
	}
}

int	ft_display_file(char *path_file)
{
	int	fd;
	int	ret;
	char	buffer[1];

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(NO_READ_MSG, 2);
		return (1);
	}
	ret = read(fd, buffer, 1);
	while (ret)
	{
		buffer[ret] = 0;
		ft_putstr(buffer, 1);
		ret = read(fd, buffer, 1);
	}
	if (close(fd) == -1)
	{
		ft_putstr(NO_READ_MSG, 2);
		return (1);
	}
	return (0);	
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr(NO_ARG_MSG, 2);
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr(TOO_ARG_MSG, 2);
		return (1);
	}
	else
	{
		return (ft_display_file(argv[1]));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:11:05 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/19 17:23:20 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i;
		int	j;
		int	len;

		i = 0;
		j = 0;
		len = 0;
		while (av[1][len])
			len++;
		while (i < len && av[2][j])
		{
			if (av[1][i] == av[2][j])
				i++;
			j++;
		}
		if (i == len)
			write(1, av[1], len);
	}
	write(1, "\n", 1);
}

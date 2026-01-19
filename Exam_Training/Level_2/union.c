/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:26:24 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/19 17:33:35 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int	ac, char	**av)
{
	int	i = 0;
	int	is_here[256] = {};

	if (ac == 3)
	{
		while (av[1][i])
		{
			is_here[(int)av[1][i]] = 1;
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			is_here[(int)av[2][i]] = 1;
			i++;
		}
		i = 0;

		while (av[1][i])
		{
			if (is_here[(int)av[1][i]])
			{
				write(1, &av[1][i], 1);
				is_here[(int)av[1][i]] = 0;
			}
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (is_here[(int)av[2][i]])
			{
				write(1, &av[2][i], 1);
				is_here[(int)av[2][i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

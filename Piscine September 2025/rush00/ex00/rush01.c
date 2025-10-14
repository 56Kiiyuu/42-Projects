/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:20:01 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/13 16:55:52 by lchambos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_display_row(int x, char f, char b, char l)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
		{
			if (i == 0)
				ft_putchar(f);
			else
				ft_putchar(l);
		}
		else
			ft_putchar(b);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	if (x < 0 || y < 0)
	{
		write(1, "Please input valid parameters.", 30);
	}
	else
	{
		row = 0;
		while (row < y)
		{
			if (row == 0 || row == y - 1)
			{
				if (row == 0)
					ft_display_row(x, '/', '*', '\\');
				else
					ft_display_row(x, '\\', '*', '/');
			}
			else
				ft_display_row(x, '*', ' ', '*');
			row++;
		}
	}
}

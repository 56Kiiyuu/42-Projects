/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorell <mmorell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:12:48 by mmorell           #+#    #+#             */
/*   Updated: 2025/09/13 16:56:17 by lchambos         ###   ########.fr       */
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
					ft_display_row(x, 'A', 'B', 'A');
				else
					ft_display_row(x, 'C', 'B', 'C');
			}
			else
				ft_display_row(x, 'B', ' ', 'B');
			row++;
		}
	}
}	

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchambos <lchambos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:49:26 by lchambos          #+#    #+#             */
/*   Updated: 2025/09/13 16:54:53 by lchambos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_row(int n, char s, char t, char u)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i == 0 || i == n - 1)
		{
			if (i == 0)
				ft_putchar(s);
			else
				ft_putchar(u);
		}
		else
			ft_putchar(t);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	r;

	if (x < 0 || y < 0)
	{
		write(1, "Please input valid parameters.", 30);
	}
	else
	{
		r = 0;
		while (r < y)
		{
			if (r == 0 || r == y - 1)
			{
				if (r == 0)
					ft_row(x, 'A', 'B', 'C');
				else
					ft_row(x, 'C', 'B', 'A');
			}
			else
				ft_row(x, 'B', ' ', 'B');
			r++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:34:39 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/11 10:20:14 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_3digits(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i < '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	a;	
	char	b;
	char	c;

	a = '0';
	b = a + 1;
	c = a + 2;
	while (a <= '7')
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				ft_print_3digits(a, b, c);
				c++;
			}
			c = 2 + b++;
		}
		b = 1 + a++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
}
*/

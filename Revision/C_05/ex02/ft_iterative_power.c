/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:12:13 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/17 18:26:25 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
	{
		while (power > 0)
		{
			result *= nb;
			power--;
		}
		return (result);
	}
}
/*
int	main(void)
{
	printf("%d\n", ft_iterative_power(-2, 3));
	printf("%d\n", ft_iterative_power(-2, 2));
	printf("%d\n", ft_iterative_power(2, 8));
	printf("%d\n", ft_iterative_power(2, 0));
	printf("%d\n", ft_iterative_power(2, -3));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:27:41 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/17 18:38:31 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		result = nb * ft_recursive_power(nb, power - 1);
	return (result);
}
/*
int	main(void)
{
	printf("%d\n", ft_recursive_power(-2, 3));
	printf("%d\n", ft_recursive_power(-2, 2));
	printf("%d\n", ft_recursive_power(2, 8));
	printf("%d\n", ft_recursive_power(2, 0));
	printf("%d\n", ft_recursive_power(2, -3));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:56:41 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/18 16:57:54 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
/*
int	main(void)
{
	printf("%d\n", ft_find_next_prime(32));
	printf("%d\n", ft_find_next_prime(17));
	printf("%d\n", ft_find_next_prime(6));
	printf("%d\n", ft_find_next_prime(85));
	printf("%d\n", ft_find_next_prime(135));
	printf("%d\n", ft_find_next_prime(67));
	printf("%d\n", ft_find_next_prime(395));
}
*/

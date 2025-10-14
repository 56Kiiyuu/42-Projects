/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:11:43 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/18 09:28:33 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_sqrt(-4));
	printf("%d\n", ft_sqrt(0));
	printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(2));
	printf("%d\n", ft_sqrt(4));
	printf("%d\n", ft_sqrt(9));
	printf("%d\n", ft_sqrt(16));
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(36));
	printf("%d\n", ft_sqrt(49));
	printf("%d\n", ft_sqrt(64));
	printf("%d\n", ft_sqrt(81));
	printf("%d\n", ft_sqrt(100));
	printf("%d\n", ft_sqrt(625));
}
*/

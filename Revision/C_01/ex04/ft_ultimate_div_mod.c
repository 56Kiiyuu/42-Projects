/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:49:20 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/11 18:44:54 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp_d;

	tmp_d = *a;
	*a = *a / *b;
	*b = tmp_d % *b;
}
/*
int	main(void)
{
	int	nb1;
	int	nb2;

	nb1 = 15;
	nb2 = 6;
	ft_ultimate_div_mod(&nb1, &nb2);
	printf("nb1 : %d\n", nb1);
	printf("nb2 : %d\n", nb2);
}
*/

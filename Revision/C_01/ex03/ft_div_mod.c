/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:23:14 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/11 18:49:03 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	res_d;
	int	res_m;

	ft_div_mod(15, 6, &res_d, &res_m);
	printf("%d\n", res_d);
	printf("%d\n", res_m);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 09:18:55 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/12 10:06:26 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	last;
	int	temp;

	i = 0;
	last = size - 1;
	while (i < last)
	{
		temp = tab[i];
		tab[i] = tab[last];
		tab[last] = temp;
		i++;
		last--;
	}
}
/*
int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5};
	int	size;
	int	i;

	size = 5;
	ft_rev_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:10:31 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/12 11:14:01 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 1;
	while (i < size)
	{
		min = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > min)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = min;
		i++;
	}
}
/*
int	main(void)
{
	int     tab[] = {3, 2, 1, 4, 1};
        int     size;
        int     i;

        size = 5;
        ft_sort_int_tab(tab, size);
        i = 0;
        while (i < size)
        {
                printf("%d ", tab[i]);
                i++;
        }
}
*/

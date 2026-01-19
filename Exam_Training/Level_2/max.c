/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:52:55 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/19 16:57:12 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int	*tab, unsigned int len)
{
	unsigned int	i;
	int	max;

	if (len > 0)
	{
		i = 0;
		max = tab[i];
		while (i < len)
		{
			if (max < tab[i])
				max = tab[i];
			i++;
		}
		return (max);
	}
	return (0);
}

#include <stdio.h>

int main()
{
	int int_tab[] = {1, 3, 2, 10, 9};
	printf("%d", max(int_tab, 5));
}

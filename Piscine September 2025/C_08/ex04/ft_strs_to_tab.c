/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:14:50 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/25 10:13:10 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup_dest;
	int		size_src;

	size_src = 0;
	while (src[size_src] != '\0')
		size_src++;
	dup_dest = (char *)malloc(sizeof(char) * size_src + 1);
	size_src = 0;
	if (dup_dest == NULL)
		return (NULL);
	else
	{
		while (src[size_src])
		{
			dup_dest[size_src] = src[size_src];
			size_src++;
		}
		dup_dest[size_src] = '\0';
		return (dup_dest);
	}
}

void	ft_free_tab(struct s_stock_str *tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i].str != 0)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		tab[i].size = ft_strlen(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

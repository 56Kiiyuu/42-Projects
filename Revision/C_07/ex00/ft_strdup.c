/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:56:09 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/24 15:00:07 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

char	*ft_strdup(char *src)
{
	char	*dup_dest;
	int		size_src;

	size_src = 0;
	while (src[size_src] != '\0')
		size_src++;
	dup_dest = (char *)malloc(sizeof(src) * (size_src + 1));
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
/*
int	main(void)
{
	char	src[18] = "Couscous tajine !";
	char	*dup;
	int	size_src;
	int	size_dup;

	dup = ft_strdup(src);
	size_src = strlen(src);
	size_dup = strlen(dup);

	printf("SRC : %s (%d)\n", src, size_src);
	printf("DUP : %s (%d)\n", dup, size_dup);
}
*/

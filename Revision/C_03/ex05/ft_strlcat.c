/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:28:55 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/17 09:32:34 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size > dest_len)
		res = dest_len + src_len;
	else
		res = src_len + size;
	while (src[i] && dest_len <= size)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (res);
}
/*
int	main(void)
{
	char	src[] = " toi !";
	char	dest[] = "Salutations a"; 
	unsigned int	res_strl;
	unsigned int	res_ft;

	res_ft = ft_strlcat(dest, src, 12);
	printf("ft_strlcat : %d\n", res_ft);
}
*/

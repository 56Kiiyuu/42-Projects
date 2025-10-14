/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:15:27 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/17 09:28:29 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	length;
	unsigned int	i;

	length = 0;
	i = 0;
	while (dest[length] != '\0')
	{
		length++;
	}
	while (i < nb && src[i] != '\0')
	{
		dest[i + length] = src[i];
		i++;
	}
	dest[i + length] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	s1[] = "a tous !";
	char	s2[] = "Salut ";
	unsigned int	nb;

	nb = 3;
	printf("%s\n", ft_strncat(s2, s1, nb));
	//printf("%s\n", strncat(s2, s1, nb));
}
*/

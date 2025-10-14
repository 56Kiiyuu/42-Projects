/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:15:27 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/18 16:03:20 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
char	*ft_strcat(char *dest, char *src)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (dest[length] != '\0')
	{
		length++;
	}
	while (src[i] != '\0')
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

	printf("%s\n", ft_strcat(s2, s1));
}
*/

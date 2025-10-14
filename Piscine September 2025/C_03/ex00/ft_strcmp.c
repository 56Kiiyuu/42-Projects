/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:21:37 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/16 10:13:37 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <string.h>
#include <stdio.h>
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	str1[] = "Salut!";
	char	str2[] = "Hello!";
	char	str3[] = "Hola!";

	printf("%d\n", ft_strcmp(str1, str2));
	printf("%d\n", ft_strcmp(str1, str3));
	printf("%d\n", ft_strcmp(str3, str2));
	// test strcmp
	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strcmp(str1, str3));
	printf("%d\n", strcmp(str3, str2));
}
*/

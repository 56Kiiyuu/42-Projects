/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:24:41 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/15 19:09:58 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (*str < 'A' || (*str > 'Z' && *str < 'a') || *str > 'z')
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str1[] = "Salut";
	char	str2[] = "coucou_";
	char	str3[] = "gdgsfgs3";

	printf("%d\n", ft_str_is_alpha(str1));
	printf("%d\n", ft_str_is_alpha(str2));
	printf("%d\n", ft_str_is_alpha(str3));
}
*/

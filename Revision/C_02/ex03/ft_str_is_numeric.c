/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:24:41 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/15 10:09:32 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
	str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str1[] = "08094385876";
	char	str2[] = "3943984284 ";
	char	str3[] = "";

	printf("%d\n", ft_str_is_numeric(str1));
	printf("%d\n", ft_str_is_numeric(str2));
	printf("%d\n", ft_str_is_numeric(str3));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:32:22 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/22 17:32:24 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_concat(int size, char **strs, char *sep, char *dest)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = dest;
	while (i < size)
	{
		ft_strcpy(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(ptr, sep);
			ptr += ft_strlen(sep);
		}
		i++;
	}
	*ptr = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (size == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += ft_strlen(sep) * (size - 1);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_concat(size, strs, sep, str);
	return (str);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argc, argv, "; "));
}
*/

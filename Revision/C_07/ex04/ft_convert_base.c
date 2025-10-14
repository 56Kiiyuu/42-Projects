/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:00:38 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/24 09:53:04 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str_base);
int		checkbase(char *str_base);
void	ft_create_nbr_base(int nbr, char *str_base, char *ptr, int *index);

int	search_index(char c, char *str_base)
{
	int	i;

	i = 0;
	while (str_base[i])
	{
		if (c == str_base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *str_base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (search_index(str[i], str_base) == -1)
			return (res * sign);
		res = (res * ft_strlen(str_base)) + search_index(str[i], str_base);
		i++;
	}
	return (res * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_dec;
	char	*ptr;
	int		i;

	if (checkbase(base_from) == 0 || checkbase(base_to) == 0)
		return (0);
	i = 0;
	ptr = malloc(40 * sizeof(char));
	nbr_dec = ft_atoi_base(nbr, base_from);
	ft_create_nbr_base(nbr_dec, base_to, ptr, &i);
	ptr[i] = 0;
	return (ptr);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*ptr;

	if (argc == 4)
	{
		ptr = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("%s", ptr);
		free(ptr);
	}
}
*/

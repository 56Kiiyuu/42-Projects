/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:30:33 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/23 15:17:43 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str_base)
{
	int	i;

	i = 0;
	while (str_base[i])
		i++;
	return (i);
}

int	checkbase(char *str_base)
{
	int	i;
	int	j;

	i = 0;
	if (str_base[0] == '\0' || str_base[i] == '\0')
		return (0);
	while (str_base[i])
	{
		if (str_base[i] == '+' || str_base[i] == '-')
			return (0);
		j = 0;
		while (str_base[j])
		{
			if (str_base[i] == str_base[j] && i != j)
				return (0);
			j++;
		}
		if (str_base[i] == '+' || str_base[i] == '-')
			return (0);
		if (str_base[i] < 32 || str_base[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

void	ft_create_nbr_base(int nbr, char *str_base, char *ptr, int *index)
{
	int			i;
	long int	n;
	int			base_len;

	n = nbr;
	i = 0;
	base_len = ft_strlen(str_base);
	if (n < 0)
	{
		ptr[*index] = '-';
		*index = *index + 1;
		n = -n;
	}
	if (n < base_len)
	{
		ptr[*index] = str_base[n];
		*index = *index + 1;
	}
	else
	{
		ft_create_nbr_base(n / base_len, str_base, ptr, index);
		ptr[*index] = str_base[n % base_len];
		*index = *index + 1;
	}
}

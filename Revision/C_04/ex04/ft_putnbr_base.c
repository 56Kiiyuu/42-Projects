/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:21:17 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/18 11:48:42 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	l;
	int	res[300];

	i = 0;
	l = 0;
	if (valid_base(base))
	{
		if (nbr < 0)
		{
			nbr = nbr * -1;
			ft_putchar('-');
		}
		while (base[l])
			l++;
		while (nbr)
		{
			res[i] = nbr % l;
			nbr = nbr / l;
			i++;
		}
		while (i-- > 0)
			ft_putchar(base[res[i]]);
	}
}

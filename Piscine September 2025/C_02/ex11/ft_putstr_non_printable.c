/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: [kevlim] <[kevlim@student.42.fr]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:22:09 by [kevlim]          #+#    #+#             */
/*   Updated: 2025/09/15 20:07:56 by [kevlim]         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	j;
	char	*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 127)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			j = str[i];
			write(1, &hexa[j / 16], 1);
			write(1, &hexa[j % 16], 1);
		}
		i++;
	}
}
/*
int	main(void)
{
	ft_putstr_non_printable("Hello\nHow are you?");
}
*/

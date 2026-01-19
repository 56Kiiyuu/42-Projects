/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:02:26 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/19 15:11:07 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int	last;
	int	i;
	char	tmp;

	i = 0;
	last = 0;
	while (str[last])
		last++;
	while (i < last - 1)
	{
		tmp = str[i];
		str[i] = str[last - 1];
		str[last - 1] = tmp;
		i++;
		last--;
	}
	return (str);
}
#include <stdio.h>
int	main(void)
{
	char s[] = "Hello World";
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}

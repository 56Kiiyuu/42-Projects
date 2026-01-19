/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:03:09 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/19 14:11:57 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		switch (av[2][0])
		{
			case '+':
				printf("%d", (atoi(av[1]) + atoi(av[3])));
				break;

			case '-':
				printf("%d", (atoi(av[1]) - atoi(av[3])));
				break;

			case '*':
				printf("%d", (atoi(av[1]) * atoi(av[3])));
				break;

			case '/':
				printf("%d", (atoi(av[1]) / atoi(av[3])));
				break;

			case '%':
				printf("%d", (atoi(av[1]) % atoi(av[3])));
				break;
		}
	}
	printf("\n");
}

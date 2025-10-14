/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:27:20 by kevlim            #+#    #+#             */
/*   Updated: 2025/09/24 10:38:28 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft.h"

int	main(void)
{
	ft_putchar('K');
	ft_putchar('\n');
	int n1;
	int n2;

	n1 = 6;
	n2 = 9;
	ft_swap(&n1, &n2);
	printf("%d\n", n1);
	printf("%d\n", n2);
	ft_putstr("Salut a tous !");
	ft_putchar('\n');
	printf("%d\n", ft_strlen("Salut a tous !"));
	printf("%d\n", ft_strcmp("Salut a tous", "Salut tout le monde"));
}

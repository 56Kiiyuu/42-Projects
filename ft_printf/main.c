/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:53 by kevlim            #+#    #+#             */
/*   Updated: 2025/11/24 17:42:00 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	a;

	printf("Coucou %s \n !\n", "Kiiyuu");
	ft_printf("Coucou %s \n !", "Kiiyuu");
	ft_printf("Coucou %d \n !", -45);
	ft_printf("Coucou %x, %X !\n", 42, 42);
	printf("Coucou %x !\n", 42);
	a = 10;
	ft_printf("%p\n", &a);
	printf("%p\n", &a);
	printf("%u\n", -1);
	ft_printf("%u\n", -1);
	printf("%%\n");
	ft_printf("%%\n");
	printf("%p cos%p \n", 0, 0);
	ft_printf("%p cos%p \n", 0, 0);
	ft_printf(0);
}

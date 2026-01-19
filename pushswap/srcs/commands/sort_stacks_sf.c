/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:30:00 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/07 14:00:44 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_stack_to_top(t_stack_node **stack, t_stack_node *node, char stack_name)
{
	if (!stack || !*stack || !node)
		return ;
	if (node->above_median)
	{
		while (*stack != node)
			(stack_name == 'a') ? ra(stack, true) : rb(stack, true);
	}
	else
	{
		while (*stack != node)
			(stack_name == 'a') ? rra(stack, true) : rrb(stack, true);
	}
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	init_nodes_a(*a, *b);
	cheapest = get_cheapest(*a);
	if (!cheapest)
		return ;

	// Aligne A et B séparément pour éviter KO
	rotate_stack_to_top(a, cheapest, 'a');
	rotate_stack_to_top(b, cheapest->target_node, 'b');

	pb(b, a, true); // push A -> B
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*target;

	init_nodes_b(*a, *b);
	target = (*b)->target_node;
	if (!target)
		return ;

	// Aligne A pour recevoir le node de B
	rotate_stack_to_top(a, target, 'a');
	pa(a, b, true);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);

	// Push jusqu'à 3 elements restent dans A
	while (len-- > 3 && !stack_sorted(*a))
		move_a_to_b(a, b);

	// Tri des 3 restants
	if (!stack_sorted(*a))
		sort_three(a);

	// Remet B dans A correctement
	while (*b)
		move_b_to_a(a, b);

	min_on_top(a); // Place le plus petit sur le dessus
}

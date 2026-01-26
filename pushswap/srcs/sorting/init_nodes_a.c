/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlim <kevlim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:44:51 by kevlim            #+#    #+#             */
/*   Updated: 2026/01/26 15:30:25 by kevlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_b;
	t_stack_node	*target;
	long			best_match;

	while (a)
	{
		best_match = LONG_MIN;
		cur_b = b;
		target = NULL;
		while (cur_b)
		{
			if (cur_b->nbr < a->nbr && cur_b->nbr > best_match)
			{
				best_match = cur_b->nbr;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (!target)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void	set_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = len_a - a->index;
		if (a->target_node)
		{
			if (a->target_node->above_median)
				a->push_cost += a->target_node->index;
			else
			a->push_cost += len_b - a->target_node->index;
		}
		a = a->next;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*tmp;
	t_stack_node	*cheapest;

	if (!a)
		return ;
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	tmp = a;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp = tmp->next;
	}
	cheapest = get_cheapest(a);
	if (cheapest)
		cheapest->cheapest = true;
}

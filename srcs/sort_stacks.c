/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:01:33 by thbasse           #+#    #+#             */
/*   Updated: 2024/06/11 10:01:44 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	mono_rotation(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	*find_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node == NULL || cheapest_node->target_node == NULL)
		return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	mono_rotation(b, cheapest_node, 'b');
	mono_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	sort_stacks(t_stack_node **a, t_stack_node**b)
{
	t_stack_node	*smallest_node;
	int				length_a;

	length_a = stack_len(*a);
	while (length_a-- > 3)
		pb(b, a);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	current_index(*a);
	smallest_node = find_smallest(*a);
	if (smallest_node->above_median)
		while (*a != smallest_node)
			ra(a);
	else
		while (*a != smallest_node)
			rra(a);
}

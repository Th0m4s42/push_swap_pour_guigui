/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:57:35 by thbasse           #+#    #+#             */
/*   Updated: 2024/06/10 14:19:12 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
					best_match_index = current_a->value;
					target_node = current_a;
			}
				current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

static void	cost_analysis(t_stack_node *a, t_stack_node *b)
{
	int				len_a;
	int				len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->index;
		if (!(b->above_median))
			b->push_price = len_b - (b->index);
		if (b->target_node->above_median)
			b->push_price += b->target_node->index;
		else
			b->push_price += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (stack == NULL)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < cheapest_value)
		{
			cheapest_value = stack->push_price;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target(a, b);
	cost_analysis(a, b);
	set_cheapest(b);
}

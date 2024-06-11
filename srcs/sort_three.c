/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:43:40 by thbasse           #+#    #+#             */
/*   Updated: 2024/06/03 10:08:06 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_stack_node	*find_highest_value(t_stack_node *stack)
{
	t_stack_node	*highest_node_value;
	int				highest;

	if (stack == NULL)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node_value = stack;
		}
		stack = stack->next;
	}
	return (highest_node_value);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_value_node;

	highest_value_node = find_highest_value(*a);
	if (*a == highest_value_node)
		ra(a);
	else if ((*a)->next == highest_value_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

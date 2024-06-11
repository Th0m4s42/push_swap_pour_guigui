/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:56:24 by thbasse           #+#    #+#             */
/*   Updated: 2024/06/10 14:18:48 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest_node_value;
	int				smallest_value;

	if (stack == NULL)
		return (NULL);
	smallest_value = INT_MAX;
	while (stack)
	{
		if (stack->value < smallest_value)
		{
			smallest_value = stack->value;
			smallest_node_value = stack;
		}
		stack = stack->next;
	}
	return (smallest_node_value);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}

bool	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	stack_len(t_stack_node *stack)
{
	int	lenth;

	lenth = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		stack = stack->next;
		lenth++;
	}
	return (lenth);
}

t_stack_node	*find_last(t_stack_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

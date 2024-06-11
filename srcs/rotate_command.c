/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:21:48 by thbasse           #+#    #+#             */
/*   Updated: 2024/06/05 07:48:57 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}

void	rotate_both(t_stack_node **a,
				t_stack_node **b,
				t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

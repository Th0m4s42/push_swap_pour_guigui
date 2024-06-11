/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:22:30 by thbasse           #+#    #+#             */
/*   Updated: 2024/06/05 07:49:06 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_both(t_stack_node **a,
				t_stack_node **b,
				t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

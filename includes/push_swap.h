/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:01:28 by thbasse           #+#    #+#             */
/*   Updated: 2024/06/10 10:22:09 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack_node;

/////Handle input//////////////////////////////////////////////
void			init_stack_a(t_stack_node **a, char **argv, int argc);
/////Handle errors/////////////////////////////////////////////
void			free_argv(char **argv);
void			free_error(t_stack_node **a, char **argv, int argc);
int				error_duplicate(t_stack_node *a, int n);
int				error_syntax(char *str);
/////Utils/////////////////////////////////////////////////////
void			free_stack(t_stack_node **stack);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *node);
t_stack_node	*find_smallest(t_stack_node *stack);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			sort_stacks(t_stack_node **a, t_stack_node**b);
/////Commands//////////////////////////////////////////////////
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
/////Sort//////////////////////////////////////////////////////
void			sort_three(t_stack_node **a);
int				main(int argc, char **argv);

#endif
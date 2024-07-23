/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:41:07 by thbasse           #+#    #+#             */
/*   Updated: 2024/07/23 14:25:27 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void perform_sort(t_stack_node *a, t_stack_node *b)
// {
// 	if (stack_len(a) == 2)
// 		sa(&a);
// 	else if (stack_len(a) == 3)
// 		sort_three(&a);
// 	else
// 		sort_stacks(&a, &b);
// }

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			return (1);
	}
	else
		argv++;
	init_stack_a(&a, argv, argc);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (argc == 2)
		free_argv(argv);
	free_stack(&a);
	return (0);
}

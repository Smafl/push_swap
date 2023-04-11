/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:18:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/12 01:17:13 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

/*
cheapest: the value of the cheapest elem
i_cheapest: index of elem which we need to push in stack_a
i_target: index of place where we shoud push elem
*/
void	sort(t_stack *stack)
{
	int				min;
	int				max;
	int				med;
	// int				cheapest;
	unsigned int	i_cheapest;
	unsigned int	i_target;

	min = find_min(&stack->stack_a, stack->total_size);
	med = find_med(&stack->stack_a, stack->total_size);
	max = find_max(&stack->stack_a, stack->total_size);
	ft_printf("min: %d\n", min);
	ft_printf("med: %d\n", med);
	ft_printf("max: %d\n", max);
	while (stack->stack_a.size != 3)
	{
		if (stack->stack_a.items[stack->stack_a.begin] == min
			|| stack->stack_a.items[stack->stack_a.begin] == max
			|| stack->stack_a.items[stack->stack_a.begin] == med)
		{
			rotate_a(stack);
		}
		else
			push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	}
	sort_three(stack);
	ft_printf("new stacks:\n");
	print_stack_a(stack);
	print_stack_b(stack);
	while (stack->stack_b.size != 0)
	{
		i_cheapest = find_cheapest(stack, &i_target);
		if (stack->case_nbr == 1)
			case_one(stack);
	}
	ft_printf("case_nbr %d\n", stack->case_nbr);
}

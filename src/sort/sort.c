/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:18:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/12 20:28:42 by ekulichk         ###   ########.fr       */
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
	t_find_cheapest_res	cheapest;
	int					min;
	int					max;
	int					med;

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
	ft_printf("\n");
	while (stack->stack_b.size != 0)
	{
		cheapest = find_cheapest(stack);
		if (cheapest.case_nbr == 0)
			case_one(stack, cheapest.i_target, cheapest.i_cheapest);
		else if (cheapest.case_nbr == 1)
			case_two(stack, cheapest.i_target, cheapest.i_cheapest);
		else if (cheapest.case_nbr == 2)
			case_three(stack, cheapest.i_target, cheapest.i_cheapest);
		else if (cheapest.case_nbr == 3)
			case_four(stack, cheapest.i_target, cheapest.i_cheapest);
	}
	ft_printf("sorted stacks:\n");
	print_stack_a(stack);
	print_stack_b(stack);
	ft_printf("\n");
}

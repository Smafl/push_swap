/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:18:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 20:12:06 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

static void	find_s(t_stack *stack, int min, unsigned int i_min)
{
	while (i_min != stack->stack_a.size)
	{
		if (stack->stack_a.items[(
					stack->stack_a.begin + i_min) % stack->buffer_size] == min)
		{
			stack->s = i_min;
		}
		i_min++;
	}
}

static void	push_all_in_b(t_stack *stack, int min, int med, int max)
{
	while (stack->stack_a.size != 3)
	{
		if (stack->stack_a.items[stack->stack_a.begin] == min
			|| stack->stack_a.items[stack->stack_a.begin] == max
			|| stack->stack_a.items[stack->stack_a.begin] == med)
		{
			rotate_a(stack);
		}
		else
			push_b(stack);
	}
}

static void	sort_all(t_stack *stack, int min)
{
	t_find_cheapest_res	cheapest;
	unsigned int		i_min;

	while (stack->stack_b.size != 0)
	{
		i_min = 0;
		cheapest = find_cheapest(stack);
		if (cheapest.case_nbr == 0)
			case_zero(stack, cheapest.i_target, cheapest.i_cheapest);
		else if (cheapest.case_nbr == 1)
			case_one(stack, cheapest.i_target, cheapest.i_cheapest);
		else if (cheapest.case_nbr == 2)
			case_two(stack, cheapest.i_target, cheapest.i_cheapest);
		else if (cheapest.case_nbr == 3)
			case_three(stack, cheapest.i_target, cheapest.i_cheapest);
		find_s(stack, min, i_min);
	}
}

void	sort(t_stack *stack)
{
	int					min;
	int					max;
	int					med;
	unsigned int		i_min;

	min = find_min(&stack->stack_a, stack->buffer_size);
	med = find_med(&stack->stack_a, stack->buffer_size);
	max = find_max(&stack->stack_a, stack->buffer_size);
	push_all_in_b(stack, min, med, max);
	sort_three(stack);
	sort_all(stack, min);
	i_min = 0;
	while (stack->stack_a.items[stack->stack_a.begin] != min)
	{
		if (stack->s < stack->stack_a.size / 2)
			rotate_a(stack);
		else
			rev_rotate_a(stack);
	}
}

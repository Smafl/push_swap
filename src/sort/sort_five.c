/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:15:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/10 18:00:29 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	sort_three(t_stack *stack)
{
	int	max;

	if (stack->stack_a.size == 2)
	{
		swap_a(stack);
		return ;
	}
	max = find_max(&stack->stack_a, stack->total_size);
	if (stack->stack_a.items[stack->stack_a.begin] == max)
		rotate_a(stack);
	if (stack->stack_a.items[(stack->stack_a.begin + 1) % stack->total_size]
		== max)
		rev_rotate_a(stack);
	if (stack->stack_a.items[stack->stack_a.begin] > stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->total_size])
		swap_a(stack);
	stack->s = 0;
}

void	sort_five(t_stack *stack)
{
	int	min;
	int	max;

	min = find_min(&stack->stack_a, stack->total_size);
	max = find_max(&stack->stack_a, stack->total_size);
	while (stack->stack_b.size != 2)
	{
		if (stack->stack_a.items[stack->stack_a.begin] == max
			|| stack->stack_a.items[stack->stack_a.begin] == min)
			push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
		else
			rotate_a(stack);
	}
	sort_three(stack);
	push_a(&stack->stack_a, &stack->stack_b, stack->total_size);
	push_a(&stack->stack_a, &stack->stack_b, stack->total_size);
	if (stack->stack_a.items[stack->stack_a.begin] == max)
		rotate_a(stack);
	else
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:15:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 21:14:46 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	start_sort(t_stack *stack)
{
	if (stack->stack_a.size <= 3)
		sort_three(stack);
	else if (stack->stack_a.size == 5)
		sort_five(stack);
	else if (stack->stack_a.size == 4 || stack->stack_a.size > 5)
		sort(stack);
}

void	sort_three(t_stack *stack)
{
	int	max;

	if (stack->stack_a.size == 2)
	{
		swap_a(stack);
		return ;
	}
	max = find_max(&stack->stack_a, stack->buffer_size);
	if (stack->stack_a.items[stack->stack_a.begin] == max)
		rotate_a(stack);
	if (stack->stack_a.items[(stack->stack_a.begin + 1) % stack->buffer_size]
		== max)
		rev_rotate_a(stack);
	if (stack->stack_a.items[stack->stack_a.begin] > stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->buffer_size])
		swap_a(stack);
	stack->s = 0;
}

void	sort_five(t_stack *stack)
{
	int	min;
	int	max;

	min = find_min(&stack->stack_a, stack->buffer_size);
	max = find_max(&stack->stack_a, stack->buffer_size);
	while (stack->stack_b.size != 2)
	{
		if (stack->stack_a.items[stack->stack_a.begin] == max
			|| stack->stack_a.items[stack->stack_a.begin] == min)
			push_b(stack);
		else
			rotate_a(stack);
	}
	sort_three(stack);
	push_a(stack);
	push_a(stack);
	if (stack->stack_a.items[stack->stack_a.begin] == max)
		rotate_a(stack);
	else
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

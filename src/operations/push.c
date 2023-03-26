/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:45:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/26 12:06:01 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	push_a(t_rb *stack_a, t_rb *stack_b, unsigned int total_size)
{
	if (!rb_is_empty(stack_b->size))
	{
		stack_a->items[(stack_a->begin + stack_a->size) % total_size]
			= stack_b->items[stack_b->begin];
		stack_b->size--;
		stack_a->size++;
		stack_b->begin = (stack_b->begin + 1) % total_size;
		if (stack_a->size > 1)
			stack_a->begin = (stack_a->begin + 1) % total_size;
	}
}

void	push_b(t_rb *stack_a, t_rb *stack_b, unsigned int total_size)
{
	if (!rb_is_empty(stack_a->size))
	{
		stack_b->items[(stack_b->begin + stack_b->size) % total_size]
			= stack_a->items[stack_a->begin];
		stack_a->size--;
		stack_b->size++;
		stack_a->begin = (stack_a->begin + 1) % total_size;
		if (stack_b->size > 1)
			stack_b->begin = (stack_b->begin + 1) % total_size;
	}
}

void	push_both(t_stack *stack)
{
	push_a(&stack->stack_a, &stack->stack_b, stack->total_size);
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:45:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 19:06:22 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <unistd.h>

void	push_a(t_stack *stack)
{
	ft_printf("pa\n");
	exec_push_a(&stack->stack_a, &stack->stack_b, stack->buffer_size);
}

void	push_b(t_stack *stack)
{
	ft_printf("pb\n");
	exec_push_b(&stack->stack_a, &stack->stack_b, stack->buffer_size);
}

void	exec_push_a(t_rb *stack_a, t_rb *stack_b, unsigned int buffer_size)
{
	if (rb_is_empty(stack_b->size))
		return ;
	stack_a->begin = (stack_a->begin - 1 + buffer_size) % buffer_size;
	stack_a->items[stack_a->begin]
		= stack_b->items[stack_b->begin];
	stack_b->begin = (stack_b->begin + 1) % buffer_size;
	stack_b->size--;
	stack_a->size++;
}

void	exec_push_b(t_rb *stack_a, t_rb *stack_b, unsigned int buffer_size)
{
	if (rb_is_empty(stack_a->size))
		return ;
	stack_b->begin = (stack_b->begin - 1 + buffer_size) % buffer_size;
	stack_b->items[stack_b->begin]
		= stack_a->items[stack_a->begin];
	stack_a->begin = (stack_a->begin + 1) % buffer_size;
	stack_a->size--;
	stack_b->size++;
}

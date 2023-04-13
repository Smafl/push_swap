/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:45:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/13 21:25:58 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	push_a(t_rb *stack_a, t_rb *stack_b, unsigned int buffer_size)
{
	if (!rb_is_empty(stack_b->size))
	{
		stack_a->begin = (stack_a->begin - 1 + buffer_size) % buffer_size;
		stack_a->items[stack_a->begin]
			= stack_b->items[stack_b->begin];
		stack_b->begin = (stack_b->begin + 1) % buffer_size;
		stack_b->size--;
		stack_a->size++;
	}
	ft_printf("pa\n");
}

void	push_b(t_rb *stack_a, t_rb *stack_b, unsigned int buffer_size)
{
	if (!rb_is_empty(stack_a->size))
	{
		stack_b->begin = (stack_b->begin - 1 + buffer_size) % buffer_size;
		stack_b->items[stack_b->begin]
			= stack_a->items[stack_a->begin];
		stack_a->begin = (stack_a->begin + 1) % buffer_size;
		stack_a->size--;
		stack_b->size++;
	}
	ft_printf("pb\n");
}

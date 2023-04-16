/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:46:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 04:57:36 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <unistd.h>

void	rev_rotate_a(t_stack *stack)
{
	if (stack->stack_a.size > 1)
	{
		stack->stack_a.items[(stack->stack_a.begin + stack->buffer_size - 1) % stack->buffer_size] = stack->stack_a.items[(stack->stack_a.begin + stack->stack_a.size - 1) % stack->buffer_size];
		stack->stack_a.begin = (stack->stack_a.begin + stack->buffer_size - 1) % stack->buffer_size;
		// ft_printf("rra\n");
		write(1, "rra\n", 4);
	}
}

void	rev_rotate_b(t_stack *stack)
{
	if (stack->stack_b.size > 1)
	{
		stack->stack_b.items[(stack->stack_b.begin + stack->buffer_size - 1) % stack->buffer_size] = stack->stack_b.items[(stack->stack_b.begin + stack->stack_b.size - 1) % stack->buffer_size];
		stack->stack_b.begin = (stack->stack_b.begin + stack->buffer_size - 1) % stack->buffer_size;
		// ft_printf("rrb\n");
		write(1, "rrb\n", 4);
	}
}

void	rev_rotate_both(t_stack *stack)
{
	if (stack->stack_a.size > 1 && stack->stack_b.size > 1)
	{
		rev_rotate_a(stack);
		rev_rotate_b(stack);
		// ft_printf("rrr\n");
		write(1, "rrr\n", 4);
	}
}

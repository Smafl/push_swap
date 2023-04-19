/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_both_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:15:13 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/19 14:14:00 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	exec_swap_both(t_stack *stack)
{
	int	temp;

	if (stack->stack_a.size > 1)
	{
		temp = stack->stack_a.items[stack->stack_a.begin];
		stack->stack_a.items[stack->stack_a.begin] = stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->buffer_size];
		stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->buffer_size] = temp;
	}
	if (stack->stack_b.size > 1)
	{
		temp = stack->stack_b.items[stack->stack_b.begin];
		stack->stack_b.items[stack->stack_b.begin] = stack->stack_b.items[(
				stack->stack_b.begin + 1) % stack->buffer_size];
		stack->stack_b.items[(
				stack->stack_b.begin + 1) % stack->buffer_size] = temp;
	}
}

void	exec_rotate_both(t_stack *stack)
{
	if (stack->stack_a.size > 1)
	{
		stack->stack_a.items[(stack->stack_a.size + stack->stack_a.begin)
			% stack->buffer_size] = stack->stack_a.items[stack->stack_a.begin];
		stack->stack_a.begin = (stack->stack_a.begin + 1) % stack->buffer_size;
	}
	if (stack->stack_b.size > 1)
	{
		stack->stack_b.items[(stack->stack_b.size + stack->stack_b.begin)
			% stack->buffer_size] = stack->stack_b.items[stack->stack_b.begin];
		stack->stack_b.begin = (stack->stack_b.begin + 1) % stack->buffer_size;
	}
}

void	exec_rev_rotate_both(t_stack *stack)
{
	if (stack->stack_a.size > 1)
	{
		stack->stack_a.items[(
				stack->stack_a.begin + stack->buffer_size - 1)
			% stack->buffer_size] = stack->stack_a.items[(
				stack->stack_a.begin + stack->stack_a.size - 1)
			% stack->buffer_size];
		stack->stack_a.begin = (
				stack->stack_a.begin + stack->buffer_size - 1)
			% stack->buffer_size;
	}
	if (stack->stack_b.size > 1)
	{
		stack->stack_b.items[(
				stack->stack_b.begin + stack->buffer_size - 1)
			% stack->buffer_size] = stack->stack_b.items[(
				stack->stack_b.begin + stack->stack_b.size - 1)
			% stack->buffer_size];
		stack->stack_b.begin = (
				stack->stack_b.begin + stack->buffer_size - 1)
			% stack->buffer_size;
	}
}

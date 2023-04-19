/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:46:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/19 14:16:59 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <unistd.h>

void	exec_rev_rotate_a(t_stack *stack)
{
	if (stack->stack_a.size <= 1)
		return ;
	stack->stack_a.items[(stack->stack_a.begin + stack->buffer_size - 1)
		% stack->buffer_size] = stack->stack_a.items[(stack->stack_a.begin
			+ stack->stack_a.size - 1) % stack->buffer_size];
	stack->stack_a.begin = (stack->stack_a.begin + stack->buffer_size - 1)
		% stack->buffer_size;
}

void	exec_rev_rotate_b(t_stack *stack)
{
	if (stack->stack_b.size <= 1)
		return ;
	stack->stack_b.items[(stack->stack_b.begin + stack->buffer_size - 1)
		% stack->buffer_size] = stack->stack_b.items[(stack->stack_b.begin
			+ stack->stack_b.size - 1) % stack->buffer_size];
	stack->stack_b.begin = (stack->stack_b.begin + stack->buffer_size - 1)
		% stack->buffer_size;
}

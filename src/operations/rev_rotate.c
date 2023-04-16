/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:46:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 20:01:08 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <unistd.h>

void	rev_rotate_a(t_stack *stack)
{
	ft_printf("rra\n");
	exec_rev_rotate_a(stack);
}

void	rev_rotate_b(t_stack *stack)
{
	ft_printf("rrb\n");
	exec_rev_rotate_b(stack);
}

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

void	rev_rotate_both(t_stack *stack)
{
	ft_printf("rrr\n");
	exec_rev_rotate_both(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:46:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/09 16:44:44 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	rev_rotate_a(t_stack *stack)
{
	if (stack->stack_a.size > 1)
	{
		stack->stack_a.items[(stack->stack_a.begin + stack->total_size - 1) % stack->total_size] = stack->stack_a.items[(stack->stack_a.begin + stack->stack_a.size - 1) % stack->total_size];
		stack->stack_a.begin = (stack->stack_a.begin + stack->total_size - 1) % stack->total_size;
	}
	ft_printf("rra\n");
}

void	rev_rotate_b(t_stack *stack)
{
	if (stack->stack_b.size > 1)
	{
		stack->stack_b.items[(stack->stack_b.begin + stack->total_size - 1) % stack->total_size] = stack->stack_b.items[(stack->stack_b.begin + stack->stack_b.size - 1) % stack->total_size];
		stack->stack_b.begin = (stack->stack_b.begin + stack->total_size - 1) % stack->total_size;
	}
	ft_printf("rrb\n");
}

void	rev_rotate_both(t_stack *stack)
{
	rev_rotate_a(stack);
	rev_rotate_b(stack);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:33:40 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/07 14:17:07 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	rotate_a(t_stack *stack)
{
	if (stack->stack_a.size > 1)
	{
		stack->stack_a.items[(stack->stack_a.size + stack->stack_a.begin)
			% stack->total_size] = stack->stack_a.items[stack->stack_a.begin];
		stack->stack_a.begin = (stack->stack_a.begin + 1) % stack->total_size;
	}
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	if (stack->stack_b.size > 1)
	{
		stack->stack_b.items[(stack->stack_b.size + stack->stack_b.begin)
			% stack->total_size] = stack->stack_b.items[stack->stack_b.begin];
		stack->stack_b.begin = (stack->stack_b.begin + 1) % stack->total_size;
	}
	ft_printf("rb\n");
}

void	rotate_both(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	ft_printf("rr\n");
}

/*
[5][1][2][3][4][-] -> rotate -> [5][1][2][3][4][5]
 0	1  2  3  4  5				 0	1  2  3  4  5
 ^									^
 begin								begin
*/
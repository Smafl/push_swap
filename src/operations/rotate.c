/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:33:40 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 04:58:43 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <unistd.h>

void	rotate_a(t_stack *stack)
{
	if (stack->stack_a.size > 1)
	{
		stack->stack_a.items[(stack->stack_a.size + stack->stack_a.begin)
			% stack->buffer_size] = stack->stack_a.items[stack->stack_a.begin];
		stack->stack_a.begin = (stack->stack_a.begin + 1) % stack->buffer_size;
		// ft_printf("ra\n");
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack *stack)
{
	if (stack->stack_b.size > 1)
	{
		stack->stack_b.items[(stack->stack_b.size + stack->stack_b.begin)
			% stack->buffer_size] = stack->stack_b.items[stack->stack_b.begin];
		stack->stack_b.begin = (stack->stack_b.begin + 1) % stack->buffer_size;
		// ft_printf("rb\n");
		write(1, "rb\n", 3);
	}
}

void	rotate_both(t_stack *stack)
{
	if (stack->stack_a.size > 1 && stack->stack_b.size > 1)
	{		
		rotate_a(stack);
		rotate_b(stack);
		// ft_printf("rr\n");
		write(1, "rr\n", 4);
	}
}

/*
[5][1][2][3][4][-] -> rotate -> [5][1][2][3][4][5]
 0	1  2  3  4  5				 0	1  2  3  4  5
 ^									^
 begin								begin
*/
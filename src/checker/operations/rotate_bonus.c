/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:33:40 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/19 14:16:43 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <unistd.h>

void	exec_rotate_a(t_stack *stack)
{
	if (stack->stack_a.size <= 1)
		return ;
	stack->stack_a.items[(stack->stack_a.size + stack->stack_a.begin)
		% stack->buffer_size] = stack->stack_a.items[stack->stack_a.begin];
	stack->stack_a.begin = (stack->stack_a.begin + 1) % stack->buffer_size;
}

void	exec_rotate_b(t_stack *stack)
{
	if (stack->stack_b.size <= 1)
		return ;
	stack->stack_b.items[(stack->stack_b.size + stack->stack_b.begin)
		% stack->buffer_size] = stack->stack_b.items[stack->stack_b.begin];
	stack->stack_b.begin = (stack->stack_b.begin + 1) % stack->buffer_size;
}

/*
[5][1][2][3][4][-] -> rotate -> [5][1][2][3][4][5]
 0	1  2  3  4  5				 0	1  2  3  4  5
 ^									^
 begin								begin
*/
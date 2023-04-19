/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:47:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/19 14:16:23 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <unistd.h>

void	exec_swap_a(t_stack *stack)
{
	int	temp;

	if (stack->stack_a.size <= 1)
		return ;
	temp = stack->stack_a.items[stack->stack_a.begin];
	stack->stack_a.items[stack->stack_a.begin] = stack->stack_a.items[(
			stack->stack_a.begin + 1) % stack->buffer_size];
	stack->stack_a.items[(
			stack->stack_a.begin + 1) % stack->buffer_size] = temp;
}

void	exec_swap_b(t_stack *stack)
{
	int	temp;

	if (stack->stack_b.size <= 1)
		return ;
	temp = stack->stack_b.items[stack->stack_b.begin];
	stack->stack_b.items[stack->stack_b.begin] = stack->stack_b.items[(
			stack->stack_b.begin + 1) % stack->buffer_size];
	stack->stack_b.items[(
			stack->stack_b.begin + 1) % stack->buffer_size] = temp;
}

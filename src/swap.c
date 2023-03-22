/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:47:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/23 00:41:43 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->stack_a.size > 1)
	{
		temp = stack->stack_a.items[0];
		stack->stack_a.items[0] = stack->stack_a.items[1];
		stack->stack_a.items[1] = temp;
	}
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->stack_b.size > 1)
	{
		temp = stack->stack_b.items[0];
		stack->stack_b.items[0] = stack->stack_b.items[1];
		stack->stack_b.items[1] = temp;
	}
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}

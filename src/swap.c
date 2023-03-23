/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:47:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/23 15:58:53 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	swap(int *items, unsigned int size, unsigned int begin)
{
	int	temp;

	if (size > 1)
	{
		temp = items[begin];
		items[begin] = items[begin + 1];
		items[begin + 1] = temp;
	}
}

void	ss(t_stack *stack)
{
	swap(stack->stack_a.items, stack->stack_a.size, stack->stack_a.begin);
	swap(stack->stack_b.items, stack->stack_b.size, stack->stack_b.begin);
}

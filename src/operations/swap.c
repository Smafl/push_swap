/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:47:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/26 06:49:30 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	swap(
	int *items, unsigned int size, unsigned int begin, unsigned int total_size)
{
	int	temp;

	if (size > 1)
	{
		temp = items[begin];
		items[begin] = items[(begin + 1) % total_size];
		items[(begin + 1) % total_size] = temp;
	}
}

void	swap_both(t_stack *stack)
{
	swap(stack->stack_a.items, stack->stack_a.size,
		stack->stack_a.begin, stack->total_size);
	swap(stack->stack_b.items, stack->stack_b.size,
		stack->stack_b.begin, stack->total_size);
}

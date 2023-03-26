/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:33:40 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/26 12:21:04 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	rotate(unsigned int size, unsigned int begin, unsigned int total_size)
{
	if (size > 1)
	{
		begin = (begin + total_size + 1) % size;
	}
}

void	rotate_both(t_stack *stack)
{
	rotate(stack->stack_a.size, stack->stack_a.begin, stack->total_size);
	rotate(stack->stack_b.size, stack->stack_b.begin, stack->total_size);
}

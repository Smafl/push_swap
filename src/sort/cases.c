/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:15:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/12 17:49:28 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	case_one(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i != stack->cost)
	{
		rotate_a(stack);
		rotate_b(stack);
		i++;
	}
	push_a(&stack->stack_a, &stack->stack_b, stack->total_size);
}

void	case_two(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i != stack->cost)
	{
		rev_rotate_a(stack);
		rev_rotate_b(stack);
		i++;
	}
	push_a(&stack->stack_a, &stack->stack_b, stack->total_size);
}

void	case_three(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i != stack->cost)
	{
		rotate_a(stack);
		rev_rotate_b(stack);
		i++;
	}
	push_a(&stack->stack_a, &stack->stack_b, stack->total_size);
}

void	case_four(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i != stack->cost)
	{
		rev_rotate_a(stack);
		rotate_b(stack);
		i++;
	}
	push_a(&stack->stack_a, &stack->stack_b, stack->total_size);
}

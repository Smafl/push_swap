/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:15:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 20:58:42 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	case_zero(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	while (i != min_uint(i_a, i_b))
	{
		rotate_both(stack);
		i++;
	}
	case_zero_end(stack, i_a, i_b);
	push_a(stack);
}

void	case_one(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	while (i != min_uint(stack->stack_a.size - i_a, stack->stack_b.size - i_b))
	{
		rev_rotate_both(stack);
		i++;
	}
	case_one_end(stack, i_a, i_b);
	push_a(stack);
}

void	case_two(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	while (i != i_a)
	{
		rotate_a(stack);
		i++;
	}
	i = 0;
	while (i != stack->stack_b.size - i_b)
	{
		rev_rotate_b(stack);
		i++;
	}
	push_a(stack);
}

void	case_three(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	while (i != stack->stack_a.size - i_a)
	{
		rev_rotate_a(stack);
		i++;
	}
	i = 0;
	while (i != i_b)
	{
		rotate_b(stack);
		i++;
	}
	push_a(stack);
}

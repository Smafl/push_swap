/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:15:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 14:23:00 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

/*
stack a: -38    2135    2773
stack b: 1387   41      2242    103     515     1630    393
i_a = 1
i_b = 4
rr
rb
rb
rb
*/
void	case_zero(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	while (i != min_uint(i_a, i_b))
	{
		rotate_both(stack);
		i++;
	}
	i = 0;
	if (i_a > i_b)
	{
		while (i != i_a - i_b)
		{
			rotate_a(stack);
			i++;
		}
	}
	else
	{
		while (i != i_b - i_a)
		{
			rotate_b(stack);
			i++;
		}
	}
	push_a(&stack->stack_a, &stack->stack_b, stack->buffer_size);
}

/*
stack a: -70    -31      -52     -15     281     349     380     -81
stack b: 264    292     278     -79     376     363     14
i_a: 4
i_b: 0

*/
void	case_one(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	while (i != min_uint(stack->stack_a.size - i_a, stack->stack_b.size - i_b))
	{
		rev_rotate_both(stack);
		i++;
	}
	i = 0;
	if (stack->stack_a.size - i_a > stack->stack_b.size - i_b)
	{
		while (i != (stack->stack_a.size - i_a) - (stack->stack_b.size - i_b))
		{
			rev_rotate_a(stack);
			i++;
		}
	}
	else
	{
		while (i != (stack->stack_b.size - i_b) - (stack->stack_a.size - i_a))
		{
			rev_rotate_b(stack);
			i++;
		}
	}
	push_a(&stack->stack_a, &stack->stack_b, stack->buffer_size);
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
	push_a(&stack->stack_a, &stack->stack_b, stack->buffer_size);
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
	push_a(&stack->stack_a, &stack->stack_b, stack->buffer_size);
}

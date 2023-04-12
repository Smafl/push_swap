/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:15:31 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/12 20:40:14 by ekulichk         ###   ########.fr       */
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
void	case_one(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	while (i != min(i_a, i_b))
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
	push_a(&stack->stack_a, &stack->stack_b, stack->total_size);
}

void	case_two(t_stack *stack, unsigned int i_a, unsigned int i_b)
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

void	case_three(t_stack *stack, unsigned int i_a, unsigned int i_b)
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

void	case_four(t_stack *stack, unsigned int i_a, unsigned int i_b)
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


//остальные кейсф и обновить s
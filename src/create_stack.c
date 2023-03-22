/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:13:18 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/23 00:49:21 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include "stdbool.h"
#include <stdlib.h>

bool	create_stack(t_stack *stack, char **argv)
{
	int	result;

	rb_a_init(stack);
	while (*argv != NULL)
	{
		if (is_space(*argv))
			if (!parse_str(stack, *argv))
				return (false);
		if (*argv == 0)
			return (false);
		else
		{
			if (!ps_atoi(*argv, &result))
				return (false);
			else
			{
				if (!int_push(stack, result))
					return (false);
			}
		}
		argv++;
	}
	stack->total_size = stack->stack_a.size;
	return (true);
}

void	rb_a_init(t_stack *stack)
{
	stack->total_size = 0;
	stack->is_argv_sorted = true;
	stack->stack_a.start = 0;
	stack->stack_a.size = 0;
	stack->stack_a.capacity = 1;
	stack->stack_a.items = malloc(sizeof(int) * stack->stack_a.capacity);
}

void	rb_b_init(t_stack *stack)
{
	stack->stack_b.start = 0;
	stack->stack_b.size = 0;
	stack->stack_b.items = malloc(sizeof(int) * stack->total_size);
}

bool	int_push(t_stack *stack, int result)
{
	unsigned int	i;

	i = 0;
	if (stack->stack_a.size == stack->stack_a.capacity)
		extend_a_rb(stack);
	while (i != stack->stack_a.size)
	{
		if (stack->stack_a.items[i] == result)
			return (false);
		i++;
	}
	if (!rb_is_empty(stack->stack_a.size)
		&& result < stack->stack_a.items[stack->stack_a.size - 1])
		stack->is_argv_sorted = false;
	stack->stack_a.items[stack->stack_a.size] = result;
	stack->stack_a.size++;
	return (true);
}

void	extend_a_rb(t_stack *stack)
{
	size_t	new_capacity;
	int		*new_stack;

	new_capacity = stack->stack_a.capacity * 2;
	new_stack = malloc(sizeof(int) * new_capacity);
	ft_memcpy(
		new_stack, stack->stack_a.items, sizeof(int) * stack->stack_a.capacity);
	stack->stack_a.items = new_stack;
	stack->stack_a.capacity = new_capacity;
}

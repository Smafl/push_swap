/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:13:18 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/13 21:26:06 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include "stdbool.h"
#include <stdlib.h>

bool	create_stack(t_stack *stack, char **argv)
{
	rb_a_init(stack);
	while (*argv != NULL)
	{
		if (is_space(*argv))
		{
			if (is_all_space(*argv))
				return (false);
			if (!parse_str(stack, *argv))
				return (false);
		}
		else if (**argv == 0)
			return (false);
		else
		{
			if (!is_atoi(stack, *argv))
				return (false);
		}
		argv++;
	}
	stack->buffer_size = stack->stack_a.size;
	return (true);
}

bool	is_atoi(t_stack *stack, char *argv)
{
	int	result;

	if (!ps_atoi(argv, &result))
		return (false);
	else
		if (!int_push(stack, result))
			return (false);
	return (true);
}

void	rb_a_init(t_stack *stack)
{
	stack->buffer_size = 0;
	stack->is_argv_sorted = true;
	stack->stack_a.begin = 0;
	stack->stack_a.size = 0;
	stack->stack_a.capacity = 1;
	stack->stack_a.items = malloc(sizeof(int) * stack->stack_a.capacity);
	if (stack->stack_a.items == NULL)
	{
		free_stack(stack->stack_a.items);
		return ;
	}
}

void	rb_b_init(t_stack *stack)
{
	stack->stack_b.begin = 0;
	stack->stack_b.size = 0;
	stack->stack_b.items = malloc(sizeof(int) * stack->buffer_size);
	if (stack->stack_b.items == NULL)
	{
		free_all(stack);
		return ;
	}
}

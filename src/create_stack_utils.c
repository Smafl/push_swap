/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:37:30 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/26 00:43:53 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:47:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 14:05:15 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <unistd.h>

void	swap_a(t_stack *stack)
{
	int	temp;

	if (stack->stack_a.size > 1)
	{
		temp = stack->stack_a.items[stack->stack_a.begin];
		stack->stack_a.items[stack->stack_a.begin] = stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->buffer_size];
		stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->buffer_size] = temp;
		// ft_printf("sa\n");
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack *stack)
{
	int	temp;

	if (stack->stack_b.size > 1)
	{
		temp = stack->stack_b.items[stack->stack_b.begin];
		stack->stack_b.items[stack->stack_b.begin] = stack->stack_b.items[(
				stack->stack_b.begin + 1) % stack->buffer_size];
		stack->stack_b.items[(
				stack->stack_b.begin + 1) % stack->buffer_size] = temp;
		// ft_printf("sb\n");
		write(1, "sb\n", 3);
	}
}

void	swap_both(t_stack *stack)
{
	int	temp;

	if (stack->stack_a.size > 1)
	{
		temp = stack->stack_a.items[stack->stack_a.begin];
		stack->stack_a.items[stack->stack_a.begin] = stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->buffer_size];
		stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->buffer_size] = temp;
	}
	if (stack->stack_b.size > 1)
	{
		temp = stack->stack_b.items[stack->stack_b.begin];
		stack->stack_b.items[stack->stack_b.begin] = stack->stack_b.items[(
				stack->stack_b.begin + 1) % stack->buffer_size];
		stack->stack_b.items[(
				stack->stack_b.begin + 1) % stack->buffer_size] = temp;
	}
	// if (stack->stack_a.size > 1 && stack->stack_b.size > 1)
	// {
	// 	swap_a(stack);
	// 	swap_b(stack);
	// 	// ft_printf("ss\n");
	// }
	write(1, "ss\n", 3);
}

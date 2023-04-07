/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:47:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/06 18:27:09 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	swap_a(t_stack *stack)
{
	int	temp;

	if (stack->stack_a.size > 1)
	{
		temp = stack->stack_a.items[stack->stack_a.begin];
		stack->stack_a.items[stack->stack_a.begin] = stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->total_size];
		stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->total_size] = temp;
	}
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	int	temp;

	if (stack->stack_b.size > 1)
	{
		temp = stack->stack_b.items[stack->stack_b.begin];
		stack->stack_b.items[stack->stack_b.begin] = stack->stack_b.items[(
				stack->stack_b.begin + 1) % stack->total_size];
		stack->stack_b.items[(
				stack->stack_b.begin + 1) % stack->total_size] = temp;
	}
	ft_printf("sb\n");
}

void	swap_both(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	ft_printf("ss\n");
}

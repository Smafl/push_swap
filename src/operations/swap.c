/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:47:27 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 20:01:16 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <unistd.h>

void	swap_a(t_stack *stack)
{
	ft_printf("sa\n");
	exec_swap_a(stack);
}

void	swap_b(t_stack *stack)
{
	ft_printf("sb\n");
	exec_swap_b(stack);
}

void	exec_swap_a(t_stack *stack)
{
	int	temp;

	if (stack->stack_a.size <= 1)
		return ;
	temp = stack->stack_a.items[stack->stack_a.begin];
	stack->stack_a.items[stack->stack_a.begin] = stack->stack_a.items[(
			stack->stack_a.begin + 1) % stack->buffer_size];
	stack->stack_a.items[(
			stack->stack_a.begin + 1) % stack->buffer_size] = temp;
}

void	exec_swap_b(t_stack *stack)
{
	int	temp;

	if (stack->stack_b.size <= 1)
		return ;
	temp = stack->stack_b.items[stack->stack_b.begin];
	stack->stack_b.items[stack->stack_b.begin] = stack->stack_b.items[(
			stack->stack_b.begin + 1) % stack->buffer_size];
	stack->stack_b.items[(
			stack->stack_b.begin + 1) % stack->buffer_size] = temp;
}

void	swap_both(t_stack *stack)
{
	ft_printf("ss\n");
	exec_swap_both(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:52 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/23 15:59:26 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void	print_stack_a(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i != stack->total_size)
	{
		ft_printf("%d in stack a\n", stack->stack_a.items[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (!create_stack(&stack, ++argv))
	{
		write(2, "Error\n", 6);
		// free_all(&stack);
		return (EXIT_FAILURE);
	}
	if (stack.is_argv_sorted == true)
	{
		// free_all(&stack);
		return (EXIT_FAILURE);
	}
	rb_b_init(&stack);
	print_stack_a(&stack);
	ft_printf("\n");
	swap(stack.stack_a.items, stack.stack_a.size, stack.stack_a.begin);
	print_stack_a(&stack);
	// free_all(&stack);
	// system("leaks push_swap");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:52 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/07 16:18:30 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (!create_stack(&stack, ++argv))
	{
		write(2, "Error\n", 6);
		free_stack(stack.stack_a.items);
		return (EXIT_FAILURE);
	}
	if (stack.is_argv_sorted == true)
	{
		free_stack(stack.stack_a.items);
		return (EXIT_FAILURE);
	}
	rb_b_init(&stack);
	// find_max(&stack.stack_a, &stack.max, stack.total_size);
	// find_min(&stack.stack_a, &stack.min, stack.total_size);
	// ft_printf("min: %d\n", stack.max);
	// ft_printf("max: %d\n", stack.min);

	if (stack.stack_a.size <= 3)
		sort_three(&stack);
	else if (stack.stack_a.size <= 5)
		sort_five(&stack);

	free_all(&stack);
	// system("leaks push_swap");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:52 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/26 12:15:03 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void	print_stacks(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	ft_printf("stack a:	");
	while (i != stack->total_size)
	{
		ft_printf("%d	", stack->stack_a.items[i]);
		i++;
	}
	ft_printf("\nstack b:	");
	i = 0;
	while (i != stack->total_size)
	{
		ft_printf("%d	", stack->stack_b.items[i]);
		i++;
	}
}

void	check_swap(t_stack *stack)
{
	ft_printf("\n\nSWAP a\n");
	swap(stack->stack_a.items, stack->stack_a.size,
		stack->stack_a.begin, stack->total_size);
	print_stacks(stack);
}

void	check_swap_both(t_stack *stack)
{
	ft_printf("\n\nSWAP BOTH\n");
	swap_both(stack);
	print_stacks(stack);
}

void	check_push_b(t_stack *stack)
{
	ft_printf("\n\nPUSH b\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stacks(stack);
	ft_printf("\n\nPUSH b\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stacks(stack);
	ft_printf("\n\nPUSH b\n");
	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
	print_stacks(stack);
}

// void	check_push_a(t_stack *stack)
// {
// 	ft_printf("\n\nPUSH a\n");
// 	push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
// 	print_stacks(stack);
// }

void	check_push_both(t_stack *stack)
{
	ft_printf("\n\nPUSH BOTH\n");
	push_both(stack);
	print_stacks(stack);
}

void	check_rotate(t_stack *stack)
{
	ft_printf("\n%u ", stack->stack_b.begin);
	rotate(stack->stack_b.size, stack->stack_b.begin, stack->stack_b.size);
	ft_printf("%u ", stack->stack_b.begin);
	rotate(stack->stack_b.size, stack->stack_b.begin, stack->stack_b.size);
	ft_printf("%u ", stack->stack_b.begin);
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
	print_stacks(&stack);
	// check_swap(&stack);
	check_push_b(&stack);
	check_rotate(&stack);
	// check_swap_both(&stack);
	// check_push_a(&stack);
	// check_push_both(&stack);
	// free_all(&stack);
	// system("leaks push_swap");
	return (0);
}

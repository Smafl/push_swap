/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:05:51 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/19 14:56:11 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"
#include "checker/gnl/get_next_line.h"
#include <unistd.h>

static void	is_sorted(t_stack *stack)
{
	unsigned int	i;

	i = 1;
	stack->is_sorted = true;
	while (i < stack->stack_a.size)
	{
		if (stack->stack_a.items[(
					stack->stack_a.begin + i - 1) % stack->buffer_size]
			> stack->stack_a.items[(
					stack->stack_a.begin + i) % stack->buffer_size])
			stack->is_sorted = false;
		i++;
	}
}

static bool	exec_operation(t_stack *stack, char *operation)
{
	if (!ft_strncmp(operation, "pa\n", ft_strlen(operation)))
		return (exec_push_a(&stack->stack_a, &stack->stack_b,
				stack->buffer_size), false);
	if (!ft_strncmp(operation, "pb\n", ft_strlen(operation)))
		return (exec_push_b(&stack->stack_a, &stack->stack_b,
				stack->buffer_size), false);
	if (!ft_strncmp(operation, "sa\n", ft_strlen(operation)))
		return (exec_swap_a(stack), false);
	if (!ft_strncmp(operation, "sb\n", ft_strlen(operation)))
		return (exec_swap_b(stack), false);
	if (!ft_strncmp(operation, "ss\n", ft_strlen(operation)))
		return (exec_swap_both(stack), false);
	if (!ft_strncmp(operation, "ra\n", ft_strlen(operation)))
		return (exec_rotate_a(stack), false);
	if (!ft_strncmp(operation, "rb\n", ft_strlen(operation)))
		return (exec_rotate_b(stack), false);
	if (!ft_strncmp(operation, "rr\n", ft_strlen(operation)))
		return (exec_rotate_both(stack), false);
	if (!ft_strncmp(operation, "rra\n", ft_strlen(operation)))
		return (exec_rev_rotate_a(stack), false);
	if (!ft_strncmp(operation, "rrb\n", ft_strlen(operation)))
		return (exec_rev_rotate_b(stack), false);
	if (!ft_strncmp(operation, "rrr\n", ft_strlen(operation)))
		return (exec_rev_rotate_both(stack), false);
	return (true);
}

static bool	operations(t_stack *stack)
{
	char	*operation;

	while (1)
	{
		operation = get_next_line(0);
		if (operation == NULL)
			return (true);
		if (exec_operation(stack, operation))
			return (free(operation), false);
		free(operation);
	}
}

bool	run_checker(t_stack *stack)
{
	if (!operations(stack))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	is_sorted(stack);
	if (stack->stack_b.size != 0 || !stack->is_sorted)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (true);
}

// void	check_leaks(void)
// {
// 	system("leaks checker");
// }
	// atexit(check_leaks);

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
	rb_b_init(&stack);
	run_checker(&stack);
	free_all(&stack);
	return (0);
}

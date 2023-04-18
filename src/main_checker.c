/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:07:14 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/18 02:27:38 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <unistd.h>

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
	if (stack.is_sorted == true)
	{
		free_stack(stack.stack_a.items);
		return (EXIT_FAILURE);
	}
	rb_b_init(&stack);
	sort(&stack);
	run_checker(&stack);
	free_all(&stack);
	return (0);
}
// system("leaks push_swap");

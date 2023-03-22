/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:52 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/22 00:08:09 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void	print_stack_a(t_rb *rb)
{
	unsigned int	i;

	i = 0;
	while (i != rb->size_a)
	{
		ft_printf("%d in stack a\n", rb->stack_a[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_rb	rb;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (!create_stack(&rb, ++argv))
	{
		ft_printf("Error\n");
		free_all(&rb);
		return (EXIT_FAILURE);
	}
	print_stack_a(&rb);
	free_all(&rb);
	// system("leaks push_swap");
	return (0);
}

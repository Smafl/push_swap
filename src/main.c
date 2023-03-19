/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:52 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/19 17:03:31 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

void	ringbuff_init(t_rb *rb)
{
	rb->start_a = 0;
	rb->size_a = 0;
}

int	main(int argc, char **argv)
{
	t_rb	rb;

	if (argc < 2 || !create_stack(&rb, argc, argv))
		return (EXIT_FAILURE);
	return (0);
}

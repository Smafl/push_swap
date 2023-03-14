/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:20:52 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/14 21:29:59 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include <stdio.h>
#include <stdbool.h>

void	ringbuff_init(t_ringbuff *ringbuff)
{
	ringbuff->start = 0;
	ringbuff->end = 0;
}

int	main(int argc, char **argv)
{
	if (argc < 2 || !insert_element(argv))
		return (EXIT_FAILURE);
	// push_swap(argv);
	return (0);
}

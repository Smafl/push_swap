/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/23 00:01:18 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

bool	rb_is_empty(unsigned int size)
{
	return (size == 0);
}

bool	rb_is_full(t_stack *stack, unsigned int size)
{
	return (stack->total_size == size);
}

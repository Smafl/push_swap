/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/13 21:26:00 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

bool	rb_is_empty(unsigned int size)
{
	return (size == 0);
}

bool	rb_is_full(unsigned int buffer_size, unsigned int current_size)
{
	return (buffer_size == current_size);
}

int	get_item(unsigned int *begin, unsigned int index, unsigned int buffer_size)
{
	return ((*begin + index) % buffer_size);
}

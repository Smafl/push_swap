/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ringbuffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:26:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/04 19:01:05 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

bool	rb_is_empty(unsigned int size)
{
	return (size == 0);
}

bool	rb_is_full(unsigned int total_size, unsigned int current_size)
{
	return (total_size == current_size);
}

int	get_item(unsigned int *begin, unsigned int index, unsigned int total_size)
{
	return ((*begin + index) % total_size);
}

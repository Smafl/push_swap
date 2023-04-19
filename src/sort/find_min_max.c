/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:23:37 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/19 13:39:07 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_rb *stack, int buffer_size)
{
	unsigned int	i;
	int				min;

	i = 0;
	min = stack->items[i];
	while (i < stack->size)
	{
		if (min > stack->items[(stack->begin + i) % buffer_size])
			min = stack->items[(stack->begin + i) % buffer_size];
		i++;
	}
	return (min);
}

int	find_max(t_rb *stack, int buffer_size)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = stack->items[stack->begin];
	while (i < stack->size)
	{
		if (max < stack->items[(stack->begin + i) % buffer_size])
			max = stack->items[(stack->begin + i) % buffer_size];
		i++;
	}
	return (max);
}

int	find_med(t_rb *stack, int buffer_size)
{
	int				*array;
	int				med;
	unsigned int	i;

	array = malloc(sizeof(int) * (stack->size + 1));
	if (array == NULL)
	{
		free_stack(stack->items);
		return (-1);
	}
	i = 0;
	while (i < stack->size)
	{
		array[i] = stack->items[(stack->begin + i) % buffer_size];
		i++;
	}
	bubble_sort(array, stack->size);
	med = array[stack->size / 2];
	free(array);
	return (med);
}

unsigned int	max_uint(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned int	min_uint(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

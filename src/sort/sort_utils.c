/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:34 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/10 18:41:09 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <stdbool.h>

int	find_min(t_rb *stack, int total_size)
{
	unsigned int	i;
	int				min;

	i = 0;
	min = stack->items[i];
	while (i < stack->size)
	{
		if (min > stack->items[(stack->begin + i) % total_size])
			min = stack->items[(stack->begin + i) % total_size];
		i++;
	}
	return (min);
}

int	find_max(t_rb *stack, int total_size)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = stack->items[stack->begin];
	while (i < stack->size)
	{
		if (max < stack->items[(stack->begin + i) % total_size])
			max = stack->items[(stack->begin + i) % total_size];
		i++;
	}
	return (max);
}

void	bubble_sort(int *array, int size)
{
	int		i;
	int		n;
	int		temp;
	bool	no_swap;

	i = 0;
	n = size;
	while (n > 1)
	{
		i = 0;
		no_swap = true;
		while (i < n - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				no_swap = false;
			}
			i++;
			if (!no_swap)
				break ;
		}
		n--;
	}
}

int	find_med(t_rb *stack, int total_size)
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
		array[i] = stack->items[(stack->begin + i) % total_size];
		i++;
	}
	bubble_sort(array, stack->size);
	med = array[stack->size / 2];
	free(array);
	return (med);
}

void	print_stack_a(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	ft_printf("stack a: ");
	while (i != stack->stack_a.size)
	{
		ft_printf("%d	", stack->stack_a.items[(
				stack->stack_a.begin + i) % stack->total_size]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack_b(t_stack *stack)
{
	unsigned int	index;

	index = 0;
	ft_printf("stack b: ");
	while (index != stack->stack_b.size)
	{
		ft_printf("%d	", stack->stack_b.items[get_item(
				&stack->stack_b.begin, index, stack->total_size)]);
		index++;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

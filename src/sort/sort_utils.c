/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:22:34 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 20:59:37 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	case_zero_end(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	if (i_a > i_b)
	{
		while (i != i_a - i_b)
		{
			rotate_a(stack);
			i++;
		}
	}
	else
	{
		while (i != i_b - i_a)
		{
			rotate_b(stack);
			i++;
		}
	}
}

void	case_one_end(t_stack *stack, unsigned int i_a, unsigned int i_b)
{
	unsigned int	i;

	i = 0;
	if (stack->stack_a.size - i_a > stack->stack_b.size - i_b)
	{
		while (i != (stack->stack_a.size - i_a) - (stack->stack_b.size - i_b))
		{
			rev_rotate_a(stack);
			i++;
		}
	}
	else
	{
		while (i != (stack->stack_b.size - i_b) - (stack->stack_a.size - i_a))
		{
			rev_rotate_b(stack);
			i++;
		}
	}
}

void	bubble_sort(int *array, int size)
{
	int		i;
	int		n;
	int		temp;
	bool	no_swap;

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

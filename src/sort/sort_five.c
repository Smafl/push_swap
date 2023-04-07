/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:15:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/07 19:03:36 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

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

void	find_min(t_rb *stack, int *min, int total_size)
{
	unsigned int	i;

	i = 0;
	*min = stack->items[i];
	while (i < stack->size)
	{
		if (*min > stack->items[(stack->begin + i) % total_size])
			*min = stack->items[(stack->begin + i) % total_size];
		i++;
	}
}

void	find_max(t_rb *stack, int *max, int total_size)
{
	unsigned int	i;

	i = 0;
	*max = stack->items[stack->begin];
	while (i < stack->size)
	{
		if (*max < stack->items[(stack->begin + i) % total_size])
			*max = stack->items[(stack->begin + i) % total_size];
		i++;
	}
}

void	sort_three(t_stack *stack)
{
	if (stack->stack_a.size == 2)
	{
		swap_a(stack);
		return ;
	}
	find_max(&stack->stack_a, &stack->max, stack->total_size);
	ft_printf("max sort 3: %d\n", stack->max);
	if (stack->stack_a.items[stack->stack_a.begin] == stack->max)
		rotate_a(stack);
	if (stack->stack_a.items[(stack->stack_a.begin + 1) % stack->total_size]
		== stack->max)
		rev_rotate_a(stack);
	if (stack->stack_a.items[stack->stack_a.begin] > stack->stack_a.items[(
				stack->stack_a.begin + 1) % stack->total_size])
		swap_a(stack);
	print_stack_a(stack);
}

void	sort_five(t_stack *stack)
{
	// unsigned int	i;

	// i = 0;
	find_max(&stack->stack_a, &stack->max, stack->total_size);
	find_min(&stack->stack_a, &stack->min, stack->total_size);
	ft_printf("max sort 5: %d\n", stack->max);
	ft_printf("min: %d\n", stack->min);
	print_stack_a(stack);
	while (stack->stack_b.size != 2)
	{
		if (stack->stack_a.items[stack->stack_a.begin] == stack->max
			|| stack->stack_a.items[stack->stack_a.begin] == stack->min)
		{
			push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
			print_stack_a(stack);
		}
		else
		{
			rotate_a(stack);
			print_stack_a(stack);
		}
	}
	sort_three(stack);
	print_stack_a(stack);
	print_stack_b(stack);
}

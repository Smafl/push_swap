/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:18:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 14:23:30 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	find_s(t_stack *stack, int min, unsigned int i_min)
{
	while (i_min != stack->stack_a.size)
	{
		if (stack->stack_a.items[(stack->stack_a.begin + i_min) % stack->buffer_size] == min)
		{
			stack->s = i_min;
			// ft_printf("s: %u\n", stack->s);
			// ft_printf("n`br for s: %d\n", stack->stack_a.items[(stack->stack_a.begin + i_min) % stack->buffer_size]);
		}
		i_min++;
	}
}

/*
cheapest: the value of the cheapest elem
i_cheapest: index of elem which we need to push in stack_a
i_target: index of place where we shoud push elem
*/
void	sort(t_stack *stack)
{
	t_find_cheapest_res	cheapest;
	int					min;
	int					max;
	int					med;
	unsigned int		i_min;
	// int					nbr_begin;

	ft_printf("old stacks:\n");
	print_stack_a(stack);
	print_stack_b(stack);
	min = find_min(&stack->stack_a, stack->buffer_size);
	med = find_med(&stack->stack_a, stack->buffer_size);
	max = find_max(&stack->stack_a, stack->buffer_size);
	while (stack->stack_a.size != 3)
	{
		if (stack->stack_a.items[stack->stack_a.begin] == min
			|| stack->stack_a.items[stack->stack_a.begin] == max
			|| stack->stack_a.items[stack->stack_a.begin] == med)
		{
			rotate_a(stack);
		}
		else
			push_b(&stack->stack_a, &stack->stack_b, stack->buffer_size);
	}
	sort_three(stack);
	ft_printf("new stacks:\n");
	print_stack_a(stack);
	print_stack_b(stack);
	while (stack->stack_b.size != 0)
	{
		i_min = 0;
		cheapest = find_cheapest(stack);
		if (cheapest.case_nbr == 0)
		{
			case_zero(stack, cheapest.i_target, cheapest.i_cheapest);
			ft_printf("sorted after case 0:\n");
			print_stack_a(stack);
			print_stack_b(stack);
		}
		else if (cheapest.case_nbr == 1)
		{
			case_one(stack, cheapest.i_target, cheapest.i_cheapest);
			ft_printf("sorted after case 1:\n");
			print_stack_a(stack);
			print_stack_b(stack);
		}
		else if (cheapest.case_nbr == 2)
		{
			case_two(stack, cheapest.i_target, cheapest.i_cheapest);
			ft_printf("sorted after case 2:\n");
			print_stack_a(stack);
			print_stack_b(stack);
		}
		else if (cheapest.case_nbr == 3)
		{
			case_three(stack, cheapest.i_target, cheapest.i_cheapest);
			ft_printf("sorted after case 3:\n");
			print_stack_a(stack);
			print_stack_b(stack);
		}
		find_s(stack, min, i_min);
		// nbr_begin = stack->stack_a.items[stack->stack_a.b`egin];
	}
	i_min = 0;
	while (stack->stack_a.items[stack->stack_a.begin] != min)
	{
		rotate_a(stack);
	}
	ft_printf("sorted stacks:\n");
	print_stack_a(stack);
	print_stack_b(stack);
	ft_printf("s: %u\n", stack->s);
}

void	sort_without_print(t_stack *stack)
{
	t_find_cheapest_res	cheapest;
	int					min;
	int					max;
	int					med;
	unsigned int		i_min;

	min = find_min(&stack->stack_a, stack->buffer_size);
	med = find_med(&stack->stack_a, stack->buffer_size);
	max = find_max(&stack->stack_a, stack->buffer_size);
	while (stack->stack_a.size != 3)
	{
		if (stack->stack_a.items[stack->stack_a.begin] == min
			|| stack->stack_a.items[stack->stack_a.begin] == max
			|| stack->stack_a.items[stack->stack_a.begin] == med)
		{
			rotate_a(stack);
		}
		else
			push_b(&stack->stack_a, &stack->stack_b, stack->buffer_size);
	}
	sort_three(stack);
	while (stack->stack_b.size != 0)
	{
		i_min = 0;
		cheapest = find_cheapest(stack);
		if (cheapest.case_nbr == 0)
		{
			case_zero(stack, cheapest.i_target, cheapest.i_cheapest);
		}
		else if (cheapest.case_nbr == 1)
		{
			case_one(stack, cheapest.i_target, cheapest.i_cheapest);
		}
		else if (cheapest.case_nbr == 2)
		{
			case_two(stack, cheapest.i_target, cheapest.i_cheapest);
		}
		else if (cheapest.case_nbr == 3)
		{
			case_three(stack, cheapest.i_target, cheapest.i_cheapest);
		}
		find_s(stack, min, i_min);
	}
	i_min = 0;
	while (stack->stack_a.items[stack->stack_a.begin] != min)
	{
		rotate_a(stack);
	}
}

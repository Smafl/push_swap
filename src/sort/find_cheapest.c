/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:53:41 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/12 17:43:35 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <limits.h>

// add if (min_cost == 1) -> break and do
unsigned int	find_cheapest(
	t_stack *stack, unsigned int *i_target)
{
	unsigned int	min_cost;
	unsigned int	i_cheapest;
	unsigned int	i_current_target;
	unsigned int	i;

	i = 0;
	min_cost = UINT_MAX;
	while (i != stack->stack_b.size)
	{
		stack->cost = get_cost(stack, &i_current_target, i);
		if (stack->cost < min_cost)
		{
			min_cost = stack->cost;
			i_cheapest = i;
			*i_target = i_current_target;
		}
		i++;
	}
	return (i_cheapest);
}

/*
case one: rotate_both
case two: rev_totate_both
case three: rotate_a + rev_totate_b
case four: rotate_b + rev_totate_a
*/
int	get_cost(
	t_stack *stack, unsigned int *i_current_target, unsigned int i)
{
	unsigned int	min_case;

	*i_current_target = get_target_index(stack, stack->stack_b.items[(
				stack->stack_b.begin + i) % stack->total_size]);
	stack->case_one = max(*i_current_target, i);
	stack->case_two = max(
			stack->stack_b.size - i, stack->stack_a.size - *i_current_target);
	stack->case_three = *i_current_target + (stack->stack_b.size - i);
	stack->case_four = i + (stack->stack_a.size - *i_current_target);
	min_case = stack->case_one;
	stack->case_nbr = 1;
	find_case(stack, &min_case);
	return (min_case);
}

// return (0) не должен никогда случиться
unsigned int	get_target_index(t_stack *stack, int nbr)
{
	unsigned int	i;

	i = 0;
	// while (i != stack->stack_a.size)
	// {
	// 	if (nbr < stack->stack_a.items[(stack->stack_a.begin + stack->s + i)
	// 			% stack->total_size])
	// 	{
	// 		return ((stack->s + i) % stack->total_size);
	// 	}
	// 	i++;
	// }
	while (i != stack->stack_a.size)
	{
		if (nbr < stack->stack_a.items[(stack->stack_a.begin + stack->s + i)
				% stack->stack_a.size])
		{
			return ((stack->s + i) % stack->stack_a.size);
		}
		i++;
	}
	return (0);
}

void	find_case(t_stack *stack, unsigned int *min_case)
{
	if (stack->case_one < *min_case)
	{
		*min_case = stack->case_one;
		stack->case_nbr = 1;
	}
	else if (stack->case_two < *min_case)
	{
		*min_case = stack->case_two;
		stack->case_nbr = 2;
	}
	else if (stack->case_three < *min_case)
	{
		*min_case = stack->case_three;
		stack->case_nbr = 3;
	}
	else if (stack->case_four < *min_case)
	{
		*min_case = stack->case_four;
		stack->case_nbr = 4;
	}
}

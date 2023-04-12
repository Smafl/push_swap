/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:53:41 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/12 20:21:51 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <limits.h>

// add if (min_cost == 1) -> break and do
t_find_cheapest_res	find_cheapest(t_stack *stack)
{
	t_get_cost_result	curr_cost;
	t_find_cheapest_res	res;
	unsigned int		min_cost;
	unsigned int		i;

	i = 0;
	min_cost = UINT_MAX;
	while (i != stack->stack_b.size)
	{
		curr_cost = get_cost(stack, i);
		if (curr_cost.case_cost < min_cost)
		{
			min_cost = curr_cost.case_cost;
			res.i_cheapest = i;
			res.i_target = curr_cost.i_current_target;
			res.case_nbr = curr_cost.case_nbr;
		}
		i++;
	}
	return (res);
}

/*
case one: rotate_both
case two: rev_totate_both
case three: rotate_a + rev_totate_b
case four: rotate_b + rev_totate_a

returns case number, case cost, i_current_target
*/
t_get_cost_result	get_cost(t_stack *stack, unsigned int i)
{
	t_get_cost_result	res;
	unsigned int		case_cost[4];
	int					i;

	i = 0;
	res.i_current_target = get_target_index(stack, stack->stack_b.items[(
				stack->stack_b.begin + i) % stack->total_size]);
	case_cost[0] = max(res.i_current_target, i);
	case_cost[1] = max(stack->stack_b.size - i, stack->stack_a.size - res.i_current_target);
	case_cost[2] = res.i_current_target + (stack->stack_b.size - i);
	case_cost[3] = i + (stack->stack_a.size - res.i_current_target);
	res.case_cost = UINT_MAX;
	while (i != 4)
	{
		if (res.case_cost > case_cost[i])
		{
			res.case_cost = case_cost[i];
			res.case_nbr = i;
		}
		i++;
	}
	return (res);
}

// return (0) не должен никогда случиться
unsigned int	get_target_index(t_stack *stack, int nbr)
{
	unsigned int	i;

	i = 0;
	while (i != stack->stack_a.size)
	{
		if (nbr < stack->stack_a.items[(stack->stack_a.begin + (stack->s + i) % stack->stack_a.size) % stack->total_size])
		{
			return ((stack->s + i) % stack->stack_a.size);
		}
		i++;
	}
	return (0);
}

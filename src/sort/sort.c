/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:18:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/10 21:15:32 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <limits.h>

// return (0) не должен никогда случиться
unsigned int	get_target_index(t_stack *stack, int nbr)
{
	unsigned int	i;

	i = 0;
	while (i != stack->stack_a.size)
	{
		if (nbr < stack->stack_a.items[(stack->stack_a.begin + stack->s + i) % stack->total_size])
		{
			return ((stack->s + i) % stack->total_size);
		}
		i++;
	}
	return (0);
}

/*
case one: rotate_both
case two: rev_totate_both
case three: rotate_a + rev_totate_b
case four: rotate_b + rev_totate_a
*/
int	get_cost(t_stack *stack, unsigned int *i_current_target, unsigned int i, int *case_nbr)
{
	int	case_one;
	int	case_two;
	int	case_three;
	int	case_four;

	*i_current_target = get_target_index(stack, stack->stack_b.items[(stack->stack_b.begin + i) % stack->total_size]);
	case_one = max(*i_current_target, i);
	case_two = max(stack->stack_b.size - i, stack->stack_a.size - *i_current_target);
	case_three = *i_current_target + (stack->stack_b.size - i);
	case_four = i + (stack->stack_a.size - *i_current_target);
	*case_nbr = min(case_one, (min(case_two, (min(case_three, case_four)))));
	return (0);
}

unsigned int	find_cheapest(t_stack *stack, unsigned int *i_target, int *case_nbr)
{
	int				min_cost;
	int				cost;
	unsigned int	i_cheapest;
	unsigned int	i_current_target;
	unsigned int	i;

	i = 0;
	min_cost = UINT_MAX;
	while (i != stack->stack_b.size)
	{
		cost = get_cost(stack, &i_current_target, i, case_nbr);
		if (cost < min_cost)
		{
			min_cost = cost;
			i_cheapest = i;
			*i_target = i_current_target;
		}
		i++;
	}
	return (i_cheapest);
}

/*
cheapest: the value of the cheapest elem
i_cheapest: index of elem which we need to push in stack_a
i_target: index of place where we shoud push elem


*/

void	sort(t_stack *stack)
{
	int				min;
	int				max;
	int				med;
	int				case_nbr;
	// int				cheapest;
	unsigned int	i_cheapest;
	unsigned int	i_target;
	unsigned int	i;

	i = 0;
	min = find_min(&stack->stack_a, stack->total_size);
	max = find_max(&stack->stack_a, stack->total_size);
	med = find_med(&stack->stack_a, stack->total_size);
	while (stack->stack_a.size != 3)
	{
		if (stack->stack_a.items[(stack->stack_a.begin + i) % stack->total_size] != min
			|| stack->stack_a.items[(stack->stack_a.begin + i) % stack->total_size] != max
			|| stack->stack_a.items[(stack->stack_a.begin + i) % stack->total_size] != med)
		{
			push_b(&stack->stack_a, &stack->stack_b, stack->total_size);
			i++;
		}
	}
	sort_three(stack);
	while (stack->stack_b.size != 0)
	{
		i_cheapest = find_cheapest(stack, &i_target, &case_nbr);
	}
	print_stack_a(stack);
	print_stack_b(stack);
	ft_printf("case_nbr %d\n", case_nbr);
}

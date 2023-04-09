/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:18:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/09 18:30:19 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"

void	sort(t_stack *stack)
{
	int	min;
	int	max;
	int	med;

	min = find_min(&stack->stack_a, stack->total_size);
	max = find_max(&stack->stack_a, stack->total_size);
	med = find_med(&stack->stack_a, stack->total_size);
}

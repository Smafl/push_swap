/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:28:57 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/26 18:12:52 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

void	free_stack(int *items)
{
	free(items);
	items = NULL;
}

void	free_all(t_stack *stack)
{
	free_stack(stack->stack_a.items);
	free_stack(stack->stack_b.items);
}

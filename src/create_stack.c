/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:13:18 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/22 11:24:27 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"
#include "stdbool.h"
#include <stdlib.h>

static void	ringbuff_init(t_rb *rb)
{
	rb->start_a = 0;
	rb->size_a = 0;
	rb->capacity = 1;
	rb->stack_a = malloc(sizeof(int) * rb->capacity);
}

static bool	is_space(char *arg)
{
	while (*arg)
	{
		if (*arg == ' ')
			return (true);
		arg++;
	}
	return (false);
}

static void	extend_rb(t_rb *rb)
{
	size_t	new_capacity;
	int		*new_stack;

	new_capacity = rb->capacity * 2;
	new_stack = malloc(sizeof(int) * new_capacity);
	ft_memcpy(new_stack, rb->stack_a, sizeof(int) * rb->capacity);
	rb->stack_a = new_stack;
	rb->capacity = new_capacity;
}

static bool	int_push(t_rb *rb, int result)
{
	unsigned int	i;

	i = 0;
	if (rb->size_a == rb->capacity)
		extend_rb(rb);
	while (i != rb->size_a)
	{
		if (rb->stack_a[i] == result)
			return (false);
		i++;
	}
	rb->stack_a[rb->size_a] = result;
	rb->size_a++;
	return (true);
}

bool	parse_str(t_rb *rb, char *str)
{
	int		result;
	char	**str_splited;

	str_splited = ft_split(str, ' ');
	while (*str_splited)
	{
		if (!ps_atoi(*str_splited, &result))
			return (false);
		else
		{
			if (!int_push(rb, result))
				return (false);
		}
		str_splited++;
	}
	return (true);
}

bool	create_stack(t_rb *rb, char **argv)
{
	int	result;

	(void)rb;
	ringbuff_init(rb);
	while (*argv != NULL)
	{
		if (is_space(*argv))
		{
			if (!parse_str(rb, *argv))
				return (false);
		}
		else if (ft_strlen(*argv) == 0)
			return (false);
		else
		{
			if (!ps_atoi(*argv, &result))
				return (false);
			else
			{
				if (!int_push(rb, result))
					return (false);
			}
		}
		argv++;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:29:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/23 19:03:32 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private.h"

bool	parse_str(t_stack *stack, char *str)
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
			if (!int_push(stack, result))
				return (false);
		}
		str_splited++;
	}
	return (true);
}

bool	is_space(char *arg)
{
	while (*arg)
	{
		if (*arg == ' ')
			return (true);
		arg++;
	}
	return (false);
}

bool	is_all_space(char *arg)
{
	while (*arg)
	{
		if (*arg != ' ')
			return (false);
		arg++;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:29:55 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 19:55:14 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../private.h"
#include <limits.h>

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

bool	parse_str(t_stack *stack, char *str)
{
	char	**str_splited;

	str_splited = ft_split(str, ' ');
	while (*str_splited)
	{
		if (!is_atoi(stack, *str_splited))
			return (false);
		str_splited++;
	}
	return (true);
}

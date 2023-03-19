/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:31:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/19 16:53:57 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

bool	ps_atoi(const char *str, int *result)
{
	int		i;
	int		sign;
	long	temp;

	i = 0;
	sign = 1;
	if (((str[0] >= '\t' && str[0] <= '\r') || str[0] == ' '))
		return (false);
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		temp = (sign * (str[i++] - '0') + (temp * 10));
		if (temp > INT_MAX || temp < INT_MIN)
			return (false);
		else
			*result = temp;
	}
	return (true);
}
/*
INT_MIN -2147483648
*/
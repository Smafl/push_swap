/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:31:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/16 16:55:00 by ekulichk         ###   ########.fr       */
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
	temp = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == 0)
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		temp = (sign * (str[i++] - '0') + (temp * 10));
		if (temp > INT_MAX || temp < INT_MIN)
			return (false);
		*result = temp;
	}
	return (true);
}
/*
INT_MIN -2147483648
*/
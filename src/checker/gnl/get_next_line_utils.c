/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:36:54 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/12 00:29:58 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	gnl_find_chr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

void	*gnl_memcpy(void *dst, const void *src, int n)
{
	unsigned char		*pnt_dst;
	const unsigned char	*pnt_src;
	int					i;

	if (dst == NULL || src == NULL)
		return (NULL);
	pnt_src = src;
	pnt_dst = dst;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		pnt_dst[i] = pnt_src[i];
		i++;
	}
	return (dst);
}

char	*gnl_strdup(const char *s1)
{
	int		len;
	char	*pnt_s1;
	char	*str_dup;

	if (s1 == NULL)
		return (NULL);
	pnt_s1 = (char *)s1;
	len = gnl_strlen(pnt_s1);
	str_dup = malloc(sizeof(char) * (len + 1));
	if (str_dup == NULL)
		return (NULL);
	gnl_memcpy(str_dup, pnt_s1, sizeof(char) * (len + 1));
	return (str_dup);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i_1;
	int		i_2;

	if (s1 == NULL)
		return (gnl_strdup(s2));
	result = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (result == NULL)
	{
		gnl_free(&s1);
		return (NULL);
	}
	i_1 = 0;
	i_2 = 0;
	while (s1[i_1])
		result[i_1++] = s1[i_2++];
	i_2 = 0;
	while (s2[i_2])
		result[i_1++] = s2[i_2++];
	result[i_1] = '\0';
	gnl_free(&s1);
	return (result);
}

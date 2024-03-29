/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:24:53 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/12 00:34:11 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*gnl_get_leftover(int *end_position, char *line)
{
	int		left_size;
	char	*leftover;

	if (line == NULL)
		return (NULL);
	left_size = gnl_strlen(line) - *end_position + 1;
	if (left_size <= 1)
	{
		gnl_free(&line);
		return (NULL);
	}
	leftover = malloc(sizeof(char) * left_size);
	if (leftover == NULL)
	{
		gnl_free(&line);
		return (NULL);
	}
	gnl_memcpy(leftover, line + *end_position, left_size);
	gnl_free(&line);
	return (leftover);
}

char	*gnl_get_line(int *end_position, char *line)
{
	char	*result;

	if (line == NULL)
		return (NULL);
	*end_position = gnl_find_chr(line, '\n');
	if (*end_position == 0)
		*end_position = gnl_strlen(line);
	result = malloc(sizeof(char) * (*end_position + 1));
	if (result == NULL)
		return (NULL);
	gnl_memcpy(result, line, *end_position);
	result[*end_position] = '\0';
	return (result);
}

char	*gnl_read_line(int fd, char *line)
{
	int		read_bytes;
	char	*read_buf;

	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buf == NULL)
		return (NULL);
	while (gnl_find_chr(line, '\n') == 0)
	{
		read_bytes = read(fd, read_buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			gnl_free(&read_buf);
			gnl_free(&line);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		read_buf[read_bytes] = '\0';
		line = gnl_strjoin(line, read_buf);
	}
	gnl_free(&read_buf);
	return (line);
}

char	*get_next_line(int fd)
{
	int			end_position;
	char		*result;
	static char	*line = NULL;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (line != NULL)
		{
			gnl_free(&line);
			line = NULL;
		}
		return (NULL);
	}
	line = gnl_read_line(fd, line);
	result = gnl_get_line(&end_position, line);
	line = gnl_get_leftover(&end_position, line);
	return (result);
}

/*
cc *.c -L../LeakSanitizer -llsan -lc++
   -Wno-gnu-include-next -I ../LeakSanitizer && ./a.out
*/

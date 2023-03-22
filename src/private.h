/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:44 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/21 22:35:38 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "push_swap.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_ringbuff
{
	int				*stack_a;
	unsigned int	start_a;
	unsigned int	size_a;
	unsigned int	capacity;
}	t_rb;

// push_swap.c
// void	push_swap(char **argv);

// free.c
void	free_all(t_rb *rb);

// create_stack.c
bool	create_stack(t_rb *rb, char **argv);

#endif

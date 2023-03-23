/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:44 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/23 19:04:12 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_H
# define PRIVATE_H

# include "push_swap.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_ringbuff
{
	int				*items;
	unsigned int	begin;
	unsigned int	size;
	unsigned int	capacity;
}	t_rb;

typedef struct s_stacks
{
	t_rb			stack_a;
	t_rb			stack_b;
	unsigned int	total_size;
	bool			is_argv_sorted;
}	t_stack;

// create_stack.c
bool	create_stack(t_stack *stack, char **argv);
void	rb_a_init(t_stack *stack);
bool	int_push(t_stack *stack, int result);
void	extend_a_rb(t_stack *stack);
void	rb_b_init(t_stack *stack);

// parse_str.c
bool	parse_str(t_stack *stack, char *str);
bool	is_space(char *arg);
bool	is_all_space(char *arg);

// ringbuffer.c
bool	rb_is_empty(unsigned int size);
bool	rb_is_full(t_stack *stack, unsigned int size);

// free.c
void	free_all(t_rb *rb);

// swap.c
void	swap(int *items, unsigned int size, unsigned int begin);
void	ss(t_stack *stack);

// push.c
void	push(int *items, unsigned int size, unsigned int begin);

#endif

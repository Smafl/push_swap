/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:44 by ekulichk          #+#    #+#             */
/*   Updated: 2023/03/26 08:15:44 by ekulichk         ###   ########.fr       */
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
bool	is_atoi(t_stack *stack, char *argv);
void	rb_a_init(t_stack *stack);
void	rb_b_init(t_stack *stack);

// parse_str.c
bool	is_space(char *arg);
bool	is_all_space(char *arg);
bool	parse_str(t_stack *stack, char *str);

// create_stack_utils.c
bool	int_push(t_stack *stack, int result);
void	extend_a_rb(t_stack *stack);

// ringbuffer.c
bool	rb_is_empty(unsigned int size);
bool	rb_is_full(unsigned int total_size, unsigned int current_size);

// free.c
void	free_all(t_rb *rb);

// swap.c
void	swap(int *items, unsigned int size,
			unsigned int begin, unsigned int total_size);
void	swap_both(t_stack *stack);

// rotate.c
void	rotate(unsigned int size, unsigned int begin, unsigned int total_size);
void	rotate_both(t_stack *stack);

// push.c
void	push_a(t_rb *stack_a, t_rb *stack_b, unsigned int total_size);
void	push_b(t_rb *stack_a, t_rb *stack_b, unsigned int total_size);
void	push_both(t_stack *stack);

#endif

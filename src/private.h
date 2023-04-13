/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:44 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/13 21:25:14 by ekulichk         ###   ########.fr       */
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
	unsigned int	buffer_size;
	unsigned int	s;
	bool			is_argv_sorted;
}	t_stack;

typedef struct s_find_cheapest_res
{
	int				case_nbr;
	unsigned int	i_cheapest;
	unsigned int	i_target;
}	t_find_cheapest_res;

typedef struct s_get_cost_result
{
	int				case_nbr;
	unsigned int	case_cost;
	unsigned int	i_current_target;
}	t_get_cost_result;

// unsigned int s -- индекс, где лежит минимум в stack_a

// SRC/CREATE STACK
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
bool	rb_is_full(unsigned int buffer_size, unsigned int current_size);
int		get_item(unsigned int *begin, unsigned int index, unsigned int buffer_size); // delete?

// SRC/SORT
// sort.c
void	sort(t_stack *stack);

// sort_five.c
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);

// find_cheapest.c
t_find_cheapest_res	find_cheapest(t_stack *stack);
t_get_cost_result	get_cost(t_stack *stack, unsigned int i);
unsigned int		get_target_index(t_stack *stack, int nbr);

// cases.c
void	case_zero(t_stack *stack, unsigned int i_a, unsigned int i_b);
void	case_one(t_stack *stack, unsigned int i_a, unsigned int i_b);
void	case_two(t_stack *stack, unsigned int i_a, unsigned int i_b);
void	case_three(t_stack *stack, unsigned int i_a, unsigned int i_b);

// sort_utils.c
int		find_min(t_rb *stack, int buffer_size);
int		find_max(t_rb *stack, int buffer_size);
int		find_med(t_rb *stack, int buffer_size);
void	print_stack_a(t_stack *stack); // delete
void	print_stack_b(t_stack *stack); // delete
int		min_int(int a, int b);
int		max_int(int a, int b);
unsigned int	min_uint(unsigned int a, unsigned int b);
unsigned int	max_uint(unsigned int a, unsigned int b);

// SRC/OPERATIONS
// push.c
void	push_a(t_rb *stack_a, t_rb *stack_b, unsigned int buffer_size);
void	push_b(t_rb *stack_a, t_rb *stack_b, unsigned int buffer_size);

// swap.c
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_both(t_stack *stack);

// rotate.c
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_both(t_stack *stack);

// rev_rotate.c
void	rev_rotate_a(t_stack *stack);
void	rev_rotate_b(t_stack *stack);
void	rev_rotate_both(t_stack *stack);

// SRC/
// free.c
void	free_stack(int *items);
void	free_all(t_stack *stack);

#endif

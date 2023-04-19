/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:42:43 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/19 14:17:21 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "checker/gnl/get_next_line.h"

// checker_bonus.c
bool	run_checker(t_stack *stack);

// free_bonus.c
void	free_stack(int *items);
void	free_all(t_stack *stack);

// SRC/CHECKER/CREATE STACK
// create_stack_bonus.c
bool	create_stack(t_stack *stack, char **argv);
bool	is_atoi(t_stack *stack, char *argv);
void	rb_a_init(t_stack *stack);
void	rb_b_init(t_stack *stack);

// parse_str_bonus.c
bool	is_space(char *arg);
bool	is_all_space(char *arg);
bool	parse_str(t_stack *stack, char *str);

// create_stack_utils_bonus.c
bool	int_push(t_stack *stack, int result);
void	extend_a_rb(t_stack *stack);
bool	rb_is_empty(unsigned int size);
bool	rb_is_full(unsigned int buffer_size, unsigned int current_size);

// SRC/CHECKER/OPERATIONS
// push_bonus.c
void	exec_push_a(t_rb *stack_a, t_rb *stack_b, unsigned int buffer_size);
void	exec_push_b(t_rb *stack_a, t_rb *stack_b, unsigned int buffer_size);

// swap_bonus.c
void	exec_swap_a(t_stack *stack);
void	exec_swap_b(t_stack *stack);

// rotate_bonus.c
void	exec_rotate_a(t_stack *stack);
void	exec_rotate_b(t_stack *stack);

// rev_rotate_bonus.c
void	exec_rev_rotate_a(t_stack *stack);
void	exec_rev_rotate_b(t_stack *stack);

// exec_both_bonus.c
void	exec_swap_both(t_stack *stack);
void	exec_rotate_both(t_stack *stack);
void	exec_rev_rotate_both(t_stack *stack);

#endif

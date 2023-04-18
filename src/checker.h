/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:42:43 by ekulichk          #+#    #+#             */
/*   Updated: 2023/04/18 02:11:52 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "private.h"
# include "src/checker/get_next_line.h"

// main.c
int		main(int argc, char **argv);

// checker.c
bool	run_checker(t_stack *stack);

#endif

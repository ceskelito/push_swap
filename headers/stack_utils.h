/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:59:09 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/28 11:25:24 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

#include "../headers/stack_struct.h"

/*********METHODS********/
void	sa(void);
void	pa(void);
void	ra(void);
void	rra(void);

void	sb(void);
void	pb(void);
void	rb(void);
void	rrb(void);

void	ss(void);
void	rr(void);
void	rrr(void);

/*********COSTRUCT********/
t_stack			*new_stack(void);
t_stack_compose	new_stack_compose(void);

/*********UTILS*********/
t_stack	*get_address(int stack_name, ...);
void	swap_values(long *a, long *b);

#endif
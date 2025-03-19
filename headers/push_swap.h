/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:17 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/19 11:21:36 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../LIBFT/headers/libft.h"
# include "stack_struct.h"

/**********MOVES*********/
void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);

/**********UTILS********/
void	exit_error(void);
void	swap_values(long *a, long *b);
t_stack *get_address(char stack_name, ...);

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

#endif
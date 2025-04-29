/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:59:09 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/22 11:48:50 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "../headers/stack_struct.h"

/*********METHODS********/
void			sa(void);
void			pa(void);
void			ra(void);
void			rra(void);

void			sb(void);
void			pb(void);
void			rb(void);
void			rrb(void);

void			ss(void);
void			rr(void);
void			rrr(void);

/*********CONSTRUCTORS********/
t_stack			*new_stack(char name);
t_stack_compose	new_stack_compose(void);
t_moves_single	*new_moves(void);
t_moves_set		*new_moves_set(void);

/*********UTILS*********/
t_stack			*get_address(int stack_name, ...);
t_stack_compose *address_compose(char *request, ...);
void			swap_values(long *a, long *b);
void	        free_stack(t_stack_compose *stack);

#endif

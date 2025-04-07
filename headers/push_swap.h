/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:17 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/07 19:45:25 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
# include "../LIBFT/headers/libft.h"
# include "stack_struct.h"

/**********MOVES*********/
void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);

/**********UTILS********/
void	exit_error(void);
t_stack *get_first_stack(char **args);


/**********ALGO*********/
void mechanical_turk(t_stack_compose *stack, t_stack *a, t_stack *b);

#endif
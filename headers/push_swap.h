/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:17 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 11:20:43 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../LIBFT/headers/libft.h"
# include "ordering_utils.h"
# include "stack_struct.h"
# include "stack_utils.h"
# include <limits.h>

/**********MOVES*********/
void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);

/**********UTILS********/
void	exit_error(void);
t_stack	*create_stack(char **args);
bool	is_sorted(t_stack *stack);
void	free_string_array(char **string_stack);

/**********ALGO*********/
void	mechanical_turk(t_stack_compose *stack, t_stack *a, t_stack *b);

#endif

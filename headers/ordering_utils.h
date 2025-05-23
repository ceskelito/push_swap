/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:45:19 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 14:17:39 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDERING_UTILS_H
# define ORDERING_UTILS_H
# include "stack_struct.h"

void			free_moves_set(t_moves_set *moves, char *names);
void			exec(t_moves_set *moves, char *names);
void			translate_moves(t_moves_set *moves, t_stack_compose *stack,
					char *names);
t_moves_single	*get_moves_to_top(int index_from, int length);
void			order_stack_a(t_stack_compose *stack);

#endif

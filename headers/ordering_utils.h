/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:45:19 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/22 12:05:59 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDERING_UTILS_H
# define ORDERING_UTILS_H
# include "../headers/push_swap.h"

void			free_moves_set(t_moves_set *moves, char *names);
void			exec(t_moves_set *moves, char *names);
void			translate_moves(t_moves_set *moves, t_stack_compose *stack,
					char *names);
t_moves_single	*get_moves_to_top(int index_from, int lenght);
void			order_stack_a(t_stack_compose *stack);

#endif

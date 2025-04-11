/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:45:19 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/11 15:22:10 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDERING_UTILS_H
# define ORDERING_UTILS_H
# include "../headers/stack_utils.h"

void free_moves_set(t_moves_set *moves, t_moves_set *comparison);
void exec(t_moves *moves);
void translate_moves(t_moves_set *moves, t_stack_compose *stack);

#endif

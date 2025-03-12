/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:06:29 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/12 14:24:50 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_STRUCT_H
# define STACK_STRUCT_H

typedef struct s_stack_single
{
	long				*list;
	int					size;
	int					capacity;
}						t_stack_single;

typedef struct s_stack_compose
{
	t_stack_single	a;
	t_stack_single	b;
}					t_stack_compose;

#endif
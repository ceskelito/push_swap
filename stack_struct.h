/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:06:29 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/12 13:11:47 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_STRUCT_H
# define STACK_STRUCT_H

typedef struct s_stack_info
{
	long				*arr;
	int					size;
	int					capacity;
}						t_stack_info;

typedef struct s_stack
{
	union
	{
		t_stack_info	stack_a;
		struct
		{
			long		*a;
			int			a_size;
			int			a_capacity;
		};
	};
	union
	{
		t_stack_info	stack_b;
		struct
		{
			long		*b;
			int			b_size;
			int			b_capacity;
		};
	};
}						t_stack;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:06:29 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/04 12:24:21 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_STRUCT_H
# define STACK_STRUCT_H

# include <stdbool.h>

typedef struct s_moves_to_exec
{
	int		count;
	bool	double_verse;
	void	(*to_exec)(void);
}			t_moves_to_exec;

typedef struct s_stack
{
	long			*list;
	int				lenght;
	int				size;
	t_moves_to_exec	*moves;

	void			(*swap)(void);
	void			(*push)(void);
	void			(*rotate)(void);
	void			(*rev_rotate)(void);
}					t_stack;

typedef struct s_stack_compose
{
	t_stack	*a;
	t_stack	*b;

	void	(*ss)(void);
	void	(*rr)(void);
	void	(*rrr)(void);

}					t_stack_compose;

#endif
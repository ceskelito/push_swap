/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:06:29 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/11 12:03:45 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_STRUCT_H
# define STACK_STRUCT_H

# include <stdbool.h>

/*
dir : 0 = to_exec : rotate()
dir : 1 = to_exec : rev_rotate()
dir : 2 = to_exec : depend to the other.
Default : rotate() 
*/
typedef struct s_moves
{
	int		count;
	union
	{
		int 	dir;
		void	(*to_exec)(void);
	};
}			t_moves;

typedef struct s_moves_set
{
	t_moves *a;
	t_moves *b;
	t_moves *twin;
	int		total;
}				t_moves_set;

typedef struct s_stack
{
	long			*list;
	int				lenght;
	int				size;
	long			max[3];

	void			(*swap)(void);
	void			(*push)(void);
	void			(*rotate)(void);
	void			(*rev_rotate)(void);
}					t_stack;

typedef struct s_stack_compose
{
	t_stack			*a;
	t_stack			*b;

	void	(*ss)(void);
	void	(*rr)(void);
	void	(*rrr)(void);
}					t_stack_compose;

#endif

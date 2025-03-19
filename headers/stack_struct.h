/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:06:29 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/19 11:15:45 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_STRUCT_H
# define STACK_STRUCT_H

typedef struct s_stack
{
	long	*list;
	int		lenght;
	int		size;

	void	(*swap)(void);
	void	(*push)(void);
	void	(*rotate)(void);
	void	(*rev_rotate)(void);
}			t_stack;

typedef struct s_stack_compose
{
	t_stack	*a;
	t_stack	*b;
}					t_stack_compose;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:00:05 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/07 15:30:42 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/stack_struct.h"
#include "../headers/stack_utils.h"
#include "../LIBFT/headers/ft_lib.h"
#include <stdarg.h>
#include <stddef.h>

void	exit_error(void);

/*********COSTRUCTORS**********/

t_moves *new_moves(void)
{
	t_moves *moves;

	moves = ft_calloc(1, sizeof(t_moves));
	moves->direction = 2;
	moves->count = 0;
	return(moves);
}

t_moves_set new_moves_set(void)
{
	t_moves_set moves_set;

	moves_set.a = new_moves();
	moves_set.b = new_moves();
	moves_set.twin = new_moves();
	moves_set.total = 0;
	return (moves_set);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		exit_error();
	stack->list = NULL;
	stack->size = 0;
	stack->lenght = 0;
	return (stack);
}

t_stack_compose	new_stack_compose(void)
{
	t_stack_compose	stack;

	stack.ss = ss;
	stack.rr = rr;
	stack.rrr = rrr;
	stack.a = new_stack();
	get_address('s', 'a', stack.a);
	stack.a->swap = sa;
	stack.a->push = pa;
	stack.a->rotate = ra;
	stack.a->rev_rotate = rra;
	stack.b = new_stack();
	get_address('s', 'b', stack.b);
	stack.b->swap = sb;
	stack.b->push = pb;
	stack.b->rotate = rb;
	stack.b->rev_rotate = rrb;
	return (stack);
}

/*********UTILS**********/

/*	GET ADDRESS
If called with one argument only, return the address of the stack named
as the argument says.

If the first arg is 's' (means "set"), so the selected by name stack address
is setted in function of the third argument (the stack address).

This function is used in order to call the moves specifically on a stack
without passing any argument.
*/
t_stack	*get_address(int stack_name, ...)
{
	static t_stack	*stack_a;
	static t_stack	*stack_b;
	char			stack_to_set;
	va_list			args;

	if (stack_name == 's')
	{
		va_start(args, stack_name);
		stack_to_set = va_arg(args, int);
		if (stack_to_set == 'a')
			stack_a = va_arg(args, t_stack *);
		else if (stack_to_set == 'b')
			stack_b = va_arg(args, t_stack *);
		va_end(args);
		if((stack_to_set == 'a' && !stack_a) ||
			(stack_to_set == 'b' && !stack_b))
			exit_error();
		return (NULL);
	}
	if (stack_name == 'a' && stack_a)
		return (stack_a);
	else if (stack_name == 'b' && stack_b)
		return (stack_b);
	exit_error();
	return (NULL);
}

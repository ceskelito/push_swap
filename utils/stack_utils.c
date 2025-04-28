/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:00:05 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 18:25:18 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stddef.h>

/*********COSTRUCTORS**********/

t_moves_single	*new_moves(void)
{
	t_moves_single	*moves;

	moves = ft_calloc(1, sizeof(t_moves_single));
	moves->dir = 2;
	moves->count = 0;
	return (moves);
}

t_moves_set	*new_moves_set(void)
{
	t_moves_set	*moves_set;

	moves_set = ft_calloc(1, sizeof(t_moves_set));
	moves_set->twin = new_moves();
	moves_set->total = 0;
	return (moves_set);
}

t_stack	*new_stack(char name)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		exit_error();
	stack->list = NULL;
	stack->size = 0;
	stack->length = 0;
	if (name == 'a')
	{
		stack->swap = sa;
		stack->push = pa;
		stack->rotate = ra;
		stack->rev_rotate = rra;
	}
	else if (name == 'b')
	{
		stack->swap = sb;
		stack->push = pb;
		stack->rotate = rb;
		stack->rev_rotate = rrb;
	}
	get_address('s', name, stack);
	return (stack);
}

t_stack_compose	new_stack_compose(void)
{
	t_stack_compose	stack;

	stack.ss = ss;
	stack.rr = rr;
	stack.rrr = rrr;
	stack.a = new_stack('a');
	stack.b = new_stack('b');
	address_compose("set", &stack);
	return (stack);
}

void	free_stack(t_stack_compose *stack)
{
	if (!stack)
		return ;
	if (stack->a)
	{
		if (stack->a->list)
			free(stack->a->list);
		free(stack->a);
	}
	if (stack->b)
	{
		if (stack->b->list)
			free(stack->b->list);
		free(stack->b);
	}
}

/*********UTILS**********/

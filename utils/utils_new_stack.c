/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_new_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:00:05 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/27 15:06:07 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
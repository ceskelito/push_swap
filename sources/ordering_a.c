/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:21:55 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/26 17:34:15 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	order_three_nums(t_stack *a)
{
	if (is_sorted(a))
		return ;
	if (a->length > 3)
		exit_error();
	if ((a->list[0] < a->list[1] && a->list[1] > a->list[2]
			&& a->list[0] < a->list[2])
		|| (a->list[0] > a->list[1] && a->list[1] > a->list[2]))
	{
		a->swap();
		order_three_nums(a);
	}
	else if (a->list[0] > a->list[1] && a->list[0] > a->list[2])
		a->rotate();
	else if (a->list[0] > a->list[1] && a->list[0] < a->list[2])
		a->swap();
	else
		a->rev_rotate();
	return ;
}

static int	find_target_index_a(int num, t_stack *a)
{
	int	i;
	int	target_index;
	int	min_diff;
	int	min_index;

	i = 0;
	target_index = -1;
	min_diff = INT_MAX;
	min_index = 0;
	while (i < a->length)
	{
		if (num < a->list[i] && a->list[i] - num < min_diff)
		{
			min_diff = a->list[i] - num;
			target_index = i;
		}
		if (a->list[i] < a->list[min_index])
			min_index = i;
		i++;
	}
	if (target_index == -1)
		return (min_index);
	return (target_index);
}

static void	last_ordering_a(t_stack *a)
{
	int	min_index;
	int	i;
	int	count;

	min_index = 0;
	i = 1;
	if (is_sorted(a))
		return ;
	while (i < a->length)
	{
		if (a->list[i] < a->list[min_index])
			min_index = i;
		i++;
	}
	if (min_index <= a->length / 2)
	{
		while (min_index-- > 0)
			a->rotate();
	}
	else
	{
		count = a->length - min_index;
		while (count-- > 0)
			a->rev_rotate();
	}
}

void	order_stack_a(t_stack_compose *stack)
{
	t_moves_set	*moves;
	int			target;

	if (stack->a->length == 3)
		order_three_nums(stack->a);
	else if (stack->a->length == 2 && !is_sorted(stack->a))
		stack->a->swap();
	while (stack->b->length > 0)
	{
		target = find_target_index_a(stack->b->list[0], stack->a);
		moves = new_moves_set();
		free(moves->a);
		moves->a = get_moves_to_top(target, stack->a->length);
		translate_moves(moves, stack, "a");
		exec(moves, "a");
		free_moves_set(moves, "a");
		stack->a->push();
	}
	last_ordering_a(stack->a);
}

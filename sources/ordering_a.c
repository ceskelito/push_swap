/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:21:55 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 12:22:20 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	order_three_nums(t_stack *a)
{
	if (is_sorted(a))
	{
		return ;
	}
	if (a->lenght > 3)
		exit_msg("Error");
	if (a->list[0] > a->list[1] && a->list[1] > a->list[2])
	{
		a->swap();
		a->rev_rotate();
	}
	else if (a->list[0] > a->list[1])
	{
		if (a->list[0] < a->list[2])
			a->swap();
		else
			a->rotate();
	}
	else if (a->list[1] > a->list[0])
	{
		if (a->list[0] > a->list[2])
			a->rev_rotate();
		else
		{
			a->rev_rotate();
			a->swap();
		}
	}
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
	while (i < a->lenght)
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
	{
		return ;
	}
	while (i < a->lenght)
	{
		if (a->list[i] < a->list[min_index])
			min_index = i;
		i++;
	}
	if (min_index <= a->lenght / 2)
	{
		while (min_index-- > 0)
			a->rotate();
	}
	else
	{
		count = a->lenght - min_index;
		while (count-- > 0)
			a->rev_rotate();
	}
}

void		DEBUG_PRINT(char name);

void	order_stack_a(t_stack_compose *stack)
{
	t_moves_set	*moves;
	int			target;

	order_three_nums(stack->a);
	moves = new_moves_set();
	while (stack->b->lenght > 0)
	{
		target = find_target_index_a(stack->b->list[0], stack->a);
		free(moves->a);
		moves->a = get_moves_to_top(target, stack->a->lenght);
		translate_moves(moves, stack, "a");
		exec(moves, "a");
		stack->a->push();
	}
	free_moves_set(moves, "a");
	last_ordering_a(stack->a);
}

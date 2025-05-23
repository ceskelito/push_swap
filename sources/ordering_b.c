/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:16:58 by rceschel          #+#             */
/*   Updated: 2025/04/22 14:35:48 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
//to avoid the norm
#define FTIB find_target_index_b
#define GMTT get_moves_to_top

static int	find_target_index_b(int num, t_stack *b)
{
	int	i;
	int	target_index;
	int	biggest_index;
	int	diff;

	i = 0;
	target_index = -1;
	biggest_index = 0;
	diff = INT_MAX;
	while (i < b->length)
	{
		if (num > b->list[i] && num - b->list[i] < diff)
		{
			target_index = i;
			diff = num - b->list[i];
		}
		if (b->list[i] > b->list[biggest_index])
			biggest_index = i;
		i++;
	}
	if (target_index < 0)
		return (biggest_index);
	return (target_index);
}

static void	optimize(t_moves_set *moves)
{
	int	*longest;
	int	*shortest;

	if (!moves)
		return ;
	if (moves->a->dir == 2)
		moves->a->dir = moves->b->dir;
	if (moves->b->dir == 2)
		moves->b->dir = moves->a->dir;
	if (moves->a->dir != moves->b->dir)
		return ;
	moves->twin->dir = moves->a->dir;
	if (moves->a->count > moves->b->count)
	{
		longest = &moves->a->count;
		shortest = &moves->b->count;
	}
	else
	{
		longest = &moves->b->count;
		shortest = &moves->a->count;
	}
	moves->twin->count = *shortest;
	*longest = *longest - *shortest;
	*shortest = 0;
}

static t_moves_set	*get_cheapest_moves_set(t_stack_compose *s)
{
	int			i;
	t_moves_set	*new_moves;
	t_moves_set	*best_moves;

	best_moves = new_moves_set();
	best_moves->total = INT_MAX;
	i = 0;
	while (i < s->a->length)
	{
		new_moves = new_moves_set();
		new_moves->a = get_moves_to_top(i, s->a->length);
		new_moves->b = GMTT(FTIB(s->a->list[i], s->b), s->b->length);
		optimize(new_moves);
		new_moves->total = new_moves->a->count + new_moves->b->count
			+ new_moves->twin->count;
		if (new_moves->total < best_moves->total)
		{
			free_moves_set(best_moves, "abt");
			best_moves = new_moves;
		}
		else
			free_moves_set(new_moves, "abt");
		i++;
	}
	return (best_moves);
}

static void	last_ordering_b(t_stack *b)
{
	int	max_index;
	int	i;
	int	count;

	i = 1;
	max_index = 0;
	while (i < b->length)
	{
		if (b->list[i] > b->list[max_index])
			max_index = i;
		i++;
	}
	if (max_index <= b->length / 2)
	{
		while (max_index-- > 0)
			b->rotate();
	}
	else
	{
		count = b->length - max_index;
		while (count-- > 0)
			b->rev_rotate();
	}
}

void	mechanical_turk(t_stack_compose *stack, t_stack *a, t_stack *b)
{
	t_moves_set	*moves;

	if (is_sorted(a))
		return ;
	if (a->length <= 3)
	{
		order_stack_a(stack);
		return ;
	}
	b->push();
	b->push();
	if (b->list[0] < b->list[1])
		b->swap();
	while (a->length > 3)
	{
		if (is_sorted(a))
			order_stack_a(stack);
		moves = get_cheapest_moves_set(stack);
		translate_moves(moves, stack, "abt");
		exec(moves, "abt");
		free_moves_set(moves, "abt");
		b->push();
	}
	last_ordering_b(b);
	order_stack_a(stack);
}

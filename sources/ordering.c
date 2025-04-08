/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:16:58 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/08 15:45:41 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
#include "../headers/push_swap.h"
#include "../headers/ordering_utils.h"

static t_moves *get_moves_to_top(int index_from, int lenght)
{
	t_moves *moves;
	moves = new_moves();
	if (index_from > lenght / 2)
	{
		moves->count = lenght - index_from;
		moves->dir = 1;
	}
	else
	{
		moves->count = index_from;
		moves->dir = 0;
		if(lenght % 2 == 0 && index_from == lenght / 2)
			moves->dir = 2;
	}
	return (moves);
}

static int find_target_index(int num, t_stack *s)
{
	int i;
	int target_index;
	int biggest_index;
	int diff;

	i = 0;
	target_index = -1;
	biggest_index = 0;
	diff = INT_MAX;
	while(i < s->lenght)
	{
		if(num > s->list[i] && num - s->list[i] < diff)
		{
			target_index = i;
			diff = num - s->list[i];
		}
		if(s->list[i] > s->list[biggest_index])
			biggest_index = i;
		i++;
	}
	if(target_index < 0)
		return(biggest_index);
	return(target_index);
}

static void optimize(t_moves_set *moves)
{
	int *longest;
	int *shortest;
	if(moves->a->dir == 2 && moves->b->dir == 2)
		moves->a->dir = 1;
	if(moves->a->dir == 2)
		moves->a->dir = moves->b->dir;
	if(moves->b->dir == 2)
		moves->b->dir = moves->a->dir;
	if(moves->a->dir != moves->b->dir)
		return;
	moves->twin->dir = moves->a->dir;
	if(moves->a->count > moves->b->count){
		longest = &moves->a->count;
		shortest = &moves->b->count;
	}
	else{
		longest = &moves->b->count;
		shortest = &moves->a->count;
	}
	moves->twin->count = *shortest;
	*longest = *longest - *shortest;
	*shortest = 0;
	moves->total = moves->a->count + moves->b->count + moves->twin->count;
}

static t_moves_set *get_cheapest_moves_set(t_stack_compose *s)
{
	int i;
	int target;
	t_moves_set *new_moves;
	t_moves_set *best_moves;

	new_moves = new_moves_set();
	best_moves = new_moves_set();
	best_moves->total = INT_MAX;
	i = 0;
	while(i < s->a->lenght){
		target = find_target_index(s->a->list[i], s->b);
		new_moves->a = get_moves_to_top(i, s->a->lenght);
		new_moves->b = get_moves_to_top(target, s->b->lenght);
		optimize(new_moves);
		if(new_moves->total < best_moves->total){
			free_moves_set(best_moves, NULL);
			best_moves = new_moves;
		}
		i++;
	}
	free_moves_set(new_moves, best_moves);
	return (best_moves);
}

void mechanical_turk(t_stack_compose *stack, t_stack *a, t_stack *b)
{
	int i;
	int rotation_count;
	(void)stack;
	t_moves_set *moves;

	b->push();
	b->push();
	if(b->list[0] < b->list[1])
		b->swap();
	while(a->lenght > 3)
	{
		moves = get_cheapest_moves_set(stack);
		translate_moves(moves, stack);
		exec(moves->twin);
		exec(moves->a);
		exec(moves->b);
		free_moves_set(moves, NULL);
		b->push();
	}
	i = b->lenght - 1;
	rotation_count = 0;
	while(i > 0 && rotation_count < b->lenght * 2)
	{
		if(b->list[i] > b->list[i - 1])
		{
			b->rotate();
			rotation_count++;
			i = b->lenght - 1;
			continue;
		}
		rotation_count++;
		i--;
	}
}
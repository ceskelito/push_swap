/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:27:59 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/07 17:04:12 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"



static void optimize_moves(t_moves_set *moves)
{
	t_moves			*biggest;
	t_moves			*smallest;

	smallest = NULL;
	biggest = NULL;
	if(moves->a->direction == moves->b->direction)
	{
		moves->twin->direction = moves->a->direction;
		if(moves->a->count > moves->b->count)
		{
			biggest = moves->a;
			smallest = moves->b;
		}
		else
		{
			biggest = moves->b;
			smallest = moves->a;
		}
		moves->twin->count = smallest->count;
		biggest->count = biggest->count - smallest->count;
		smallest->count = 0;
	}
	else if(moves->a->direction == 2 || moves->b->direction == 2)
	{
		if(moves->a->direction == 2)
			moves->a->direction = moves->b->direction;
		else
			moves->b->direction = moves->a->direction;
		optimize_moves(moves);
	}
	moves->total = moves->a->count + moves->b->count + moves->twin->count;
}

static t_moves *get_moves_to_top(int index_from, int lenght)
{
	t_moves *moves;
	moves = new_moves();
	if (index_from > lenght / 2)
	{
		moves->count = lenght - index_from;
		moves->direction = 1;
	}
	else
	{
		moves->count = index_from;
		moves->direction = 0;
		if(lenght % 2 == 0 && index_from == lenght / 2)
			moves->direction = 2;
	}
	return (moves);
}

// All variables in the function refers to an index_from
static int find_target_index(int na, t_stack *b)
{
	int	i;
	int closest_smaller;
	int biggest;

	i = 0;
	closest_smaller = -1;
	biggest = 0;
	while(i < b->lenght)
	{
		if(b->list[i] < na)
			if(closest_smaller < 0 || na - b->list[i] < na - b->list[closest_smaller])
				closest_smaller = i;
		if(b->list[i] > b->list[biggest])
			biggest = i;
		i++;
	}
	if (closest_smaller < 0)
		return (biggest);
	return (closest_smaller);
}

static void translate_moves(t_moves *moves_set, t_stack *stack_name)
{
	if(!moves_set || !stack_name)
		return;
	if(moves_set->direction == 0 || moves_set->direction == 2)
		moves_set->to_exec = stack_name->rotate;
	else
		moves_set->to_exec = stack_name->rev_rotate;
}

static void free_if_different(void *to_free, void *comparison)
{
	if(to_free != comparison)
		free(to_free);
}

static void free_moves_set(t_moves_set *moves, t_moves_set *comparison)
{
	if(!comparison)
	{
		free(moves->a);
		free(moves->b);
		free(moves->twin);
		return;
	}
	free_if_different(moves->a, comparison->a);
	free_if_different(moves->b, comparison->b);
	free_if_different(moves->twin, comparison->twin);
}

static t_moves_set get_cheapest_moves(t_stack_compose *stack)
{
	int target_index;
	int index_from;
	t_moves_set new_moves;
	t_moves_set best_moves;

	new_moves = new_moves_set();
	best_moves = new_moves_set();
	index_from = 0;
	while(index_from < stack->a->lenght)
	{
		free_if_different(new_moves.a, best_moves.a);
		free_if_different(new_moves.b, best_moves.b);
		target_index = find_target_index(stack->a->list[index_from], stack->b);
		new_moves.a = get_moves_to_top(index_from, stack->a->lenght);
		new_moves.b = get_moves_to_top(target_index, stack->b->lenght);
		optimize_moves(&new_moves);
		if(new_moves.total < best_moves.total || index_from == 0)
		{
			free_moves_set(&best_moves, NULL);
			ft_memmove(&best_moves, &new_moves, sizeof(new_moves));
		}
		index_from++;
	}
	translate_moves(best_moves.a, stack->a);
	translate_moves(best_moves.b, stack->b);
	free_moves_set(&new_moves, &best_moves);
	return (best_moves);
}

static void exec(t_moves *moves)
{
	if(!moves->to_exec)
		return;
	while(moves->count > 0)
	{
		moves->to_exec();
		moves->count--;
	}
}
/* potrei salvare tutte le mosse in un array di puntatori a funzione e poi eseguirle*/
void mechanical_turk(t_stack_compose *stack, t_stack *a, t_stack *b)
{
	(void)stack;
	t_moves_set moves;
	int i;

	b->push();
	b->push();
	if(b->list[0] < b->list[1])
		swap_values(b->list + 0, b->list + 1);

	while(a->lenght > 3)
	{
		moves = get_cheapest_moves(stack);
		exec(moves.twin);
		exec(moves.a);
		exec(moves.b);
		free_moves_set(&moves, NULL);
		b->push();
	}
	i = b->lenght;
	while(i > 0)
	{
		if(b->list[i] > b->list[i -1])
		{
			b->rotate();
			i = b->lenght;
			continue;
		}
		i--;
	}
}

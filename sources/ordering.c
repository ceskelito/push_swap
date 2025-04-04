/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:27:59 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/04 12:52:52 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

#define NR 0
#define RR 1
#define XR 2

// static int count_moves(t_stack *a, t_stack *b, int index_from);

// moves[0] = moves count; moves[1] = 0-NR:rotate | 1-RR:rev rotate | 2-XR:equivalent
static void moves_to_top(int index, int lenght, int moves[2])
{
	if (index > lenght / 2)
	{
		moves[0] = lenght - index;
		moves[1] = RR;
	}
	else
	{
		moves[0] = index;
		moves[1] = NR;
		if(lenght % 2 == 0 && index == lenght / 2)
			moves[1] = XR;
	}
}

static void set_moves_to_top(t_stack *s, int index)
{
	if (index > s->lenght / 2)
	{
		s->moves->count = s->lenght - index;
		s->moves->to_exec = s->rev_rotate;
	}
	else
	{
		s->moves->count = index;
		s->moves->to_exec = s->rotate;
		if(s->lenght % 2 == 0 && index == s->lenght / 2)
			s->moves->double_verse = true;
	}
}

// All variables in the function refers to an index
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


static int get_cheapest_index(t_stack *a, t_stack *b)
{
	int	cheapest_index[2];
	int a_to_top[2];
	int b_to_top[2];
	int target_index;
	int index;

	index = 0;
	while(index < a->lenght)
	{
		target_index = find_target_index(a->list[index], b);
		moves_to_top(index, a->lenght, a_to_top);
		moves_to_top(target_index, b->lenght, b_to_top);
		if(a_to_top[1] == b_to_top[1] || (a_to_top[1] == 2 || b_to_top[1] == 2))
		{
			if( b_to_top[0] > a_to_top[0])
				a_to_top[0] = 0;
			else
				b_to_top[0] = 0;
		}
		if(a_to_top[0] + b_to_top[0] < cheapest_index[1])
		{
			cheapest_index[0] = index;
			cheapest_index[1] = a_to_top[0] + b_to_top[0];
		}
		index++;
	}
	return (cheapest_index[0]);
}

static void exec(t_moves_to_exec *moves)
{
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

	b->push();
	b->push();

	if(b->list[0] < b->list[1])
		swap_values(b->list + 0, b->list + 1);

/****************da rimuovere***************/
	int cheapest_index = get_cheapest_index(a, b);
	set_moves_to_top(a, cheapest_index);
	set_moves_to_top(b, find_target_index(a->list[cheapest_index], b));
	
	exec(a->moves);
	exec(b->moves);
	// ft_printf("\nnumero mosse: %i", );
/*******************fine da rimuovere********/
}
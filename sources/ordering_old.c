/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_old.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:27:59 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/04 17:48:18 by rceschel         ###   ########.fr       */
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
static void moves_to_top(int index_from, int lenght, int moves[2])
{
	if (index_from > lenght / 2)
	{
		moves[0] = lenght - index_from;
		moves[1] = RR;
	}
	else
	{
		moves[0] = index_from;
		moves[1] = NR;
		if(lenght % 2 == 0 && index_from == lenght / 2)
			moves[1] = XR;
	}
}

static void set_moves_to_top(t_stack *s, int index_from)
{
	if (index_from > s->lenght / 2)
	{
		s->moves->count = s->lenght - index_from;
		s->moves->to_exec = s->rev_rotate;
	}
	else
	{
		s->moves->count = index_from;
		s->moves->to_exec = s->rotate;
		if(s->lenght % 2 == 0 && index_from == s->lenght / 2)
			s->moves->double_verse = true;
	}
}

static t_moves *get_moves_to_top(int index_from, int lenght)
{
	t_moves *moves;
	moves = ft_calloc(1, sizeof(t_moves));
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


static int get_cheapest_index(t_stack *a, t_stack *b)
{
	int	cheapest_index[2];
	int a_to_top[2];
	int b_to_top[2];
	int target_index;
	int index_from;

	index_from = 0;
	while(index_from < a->lenght)
	{
		target_index = find_target_index(a->list[index_from], b);
		moves_to_top(index_from, a->lenght, a_to_top);
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
			cheapest_index[0] = index_from;
			cheapest_index[1] = a_to_top[0] + b_to_top[0];
		}
		index_from++;
	}
	return (cheapest_index[0]);
}

int optimize_moves(t_stack_compose *stack, t_moves *a_top, t_moves *b_top, int n_moves)
{
	t_moves	*biggest;
	t_moves	*smallest;
	int				new_n_moves;

	if(a_top->direction == b_top->direction)
	{
		stack->moves->direction = a_top->direction;
		if(a_top->count > b_top->count)
		{
			biggest = a_top;
			smallest = b_top;
		}
		else
		{
			biggest = b_top;
			smallest = a_top;
		}
		stack->moves->count = smallest->count;
		biggest->count = biggest->count - smallest->count;
	}
	else if(a_top->direction == 2 || b_top->direction == 2)
	{
		if(a_top->direction == 2)
			a_top->direction = b_top->direction;
		else
			b_top->direction = a_top->direction;
		return (optimize_moves(stack, a_top, b_top, n_moves));
	}
	new_n_moves = stack->moves->count + a_top->count


}

static int get_cheapest_moves(t_stack_compose *stack)
{
	int target_index;
	int index_from;
	int n_moves;
	t_moves_list *to_top;

	to_top = ft_calloc(1, sizeof(t_moves_list));
	index_from = 0;
	while(index_from < stack->a->lenght)
	{
		target_index = find_target_index(stack->a->list[index_from], stack->b);
		to_top->a = count_moves_to_top(index_from, stack->a->lenght);
		to_top->b = count_moves_to_top(target_index, stack->b->lenght);
		optimize_moves(stack, to_top);
		index_from++;
	}
	return ();
}

static void exec(t_moves *moves)
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
	int cheapest_index;
	int i;

	cheapest_index = 0;
	b->push();
	b->push();

	if(b->list[0] < b->list[1])
		swap_values(b->list + 0, b->list + 1);

	while(a->lenght > 3)
	{
		cheapest_index = get_cheapest_index(a, b);
		set_moves_to_top(a, cheapest_index);
		set_moves_to_top(b, find_target_index(a->list[cheapest_index], b));

		exec(a->moves);
		exec(b->moves);
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

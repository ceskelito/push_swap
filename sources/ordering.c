/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:27:59 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/04 18:26:26 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

static t_moves_list *optimize_moves(t_stack_compose *stack, t_moves_list *moves)
{
	t_moves			*biggest;
	t_moves			*smallest;
	t_moves_list	optimised;
	int				new_n_moves;

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
	}
	else if(moves->a->direction == 2 || moves->b->direction == 2)
	{
		if(moves->a->direction == 2)
			moves->a->direction = moves->b->direction;
		else
			moves->b->direction = moves->a->direction;
		return (optimize_moves(stack, moves));
	}
	new_n_moves = moves->twin->count + moves->a->count


}

static t_moves_list *get_cheapest_moves(t_stack_compose *stack)
{
	int target_index;
	int index_from;
	int n_moves;
	t_moves_list *to_top;
	t_moves_list *best_moves;

	to_top = ft_calloc(1, sizeof(t_moves_list));
	index_from = 0;
	while(index_from < stack->a->lenght)
	{
		target_index = find_target_index(stack->a->list[index_from], stack->b);
		to_top->a = count_moves_to_top(index_from, stack->a->lenght);
		to_top->b = count_moves_to_top(target_index, stack->b->lenght);
		best_moves = optimize_moves(stack, to_top);
		index_from++;
	}
	return (to_top);
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
	t_moves_list *moves;
	int cheapest_index;
	int i;

	cheapest_index = 0;
	b->push();
	b->push();

	if(b->list[0] < b->list[1])
		swap_values(b->list + 0, b->list + 1);

	while(a->lenght > 3)
	{
		// cheapest_index = get_cheapest_index(a, b);
		// set_moves_to_top(a, cheapest_index);
		// set_moves_to_top(b, find_target_index(a->list[cheapest_index], b));

		moves = get_cheapest_moves(stack);
		exec(moves->twin);
		exec(moves->a);
		exec(moves->b);
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

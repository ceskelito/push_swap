/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:27:59 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/28 13:16:00 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

static int count_moves(t_stack_compose *stack, t_stack *a, t_stack *b, int index_from);

static int moves_to_top(int index, int lenght)
{
	if(index > lenght / 2)
		return (lenght - index);
	else
		return (index);
}

static void (*find_cheapest_move(t_stack_compose *stack, t_stack *a, t_stack *b))(void)
{
	int	n_moves;
	int	i;
	int	tmp;

	n_moves = 0;
	i = 0;
	while(i < a->lenght)
	{
		tmp = count_moves(stack, a, b, i);
		if(tmp < n_moves)
			n_moves = tmp;
		i++;
	}
	return (NULL);
}

static int find_target_index(int na, t_stack *b)
{
	int	i;

	i = 0;
	while(i < b->lenght)
	{
		if(na > b->list[i])
			return (i);
		i++;
	}
	return (b->lenght);
}


// n_moves + 1 perchè il push è sottointeso
static int count_moves(t_stack_compose *stack, t_stack *a, t_stack *b, int index_from)
{
	int n_moves;
	int a_to_top;
	int b_to_top;
	int target_index;

	(void) stack; //debug
	target_index = find_target_index(a->list[index_from], b);
	if((index_from > a->lenght / 2 && target_index > b->lenght / 2) ||
		(index_from < a->lenght && target_index < b->lenght / 2))
	{
		a_to_top = moves_to_top(index_from, a->lenght);
		b_to_top = moves_to_top(target_index, b->lenght);
		if( a_to_top > b_to_top)
			n_moves = a_to_top;
		else
			n_moves = b_to_top;
	}
	else
		n_moves = moves_to_top(index_from, a->lenght) + moves_to_top(target_index, b->lenght);
	return (n_moves + 1);
}

/* potrei salvare tutte le mosse in un array di puntatori a funzione e poi eseguirle*/
void mechanical_turk(t_stack_compose *stack, t_stack *a, t_stack *b)
{
	void (*cheapest_move)(void);

	b->push();
	b->push();

	int	n_moves;
	int	i;
	int	tmp;

	n_moves = 0;
	i = 0;
	while(i < a->lenght)
	{
		tmp = count_moves(stack, a, b, i);
		if(tmp < n_moves)
			n_moves = tmp;
		i++;
	}
	ft_printf("\nnumero mosse: %i", n_moves);

	cheapest_move = find_cheapest_move(stack, a, b);
	(void) cheapest_move; //debug
}
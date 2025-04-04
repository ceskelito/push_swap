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

#define  R 0
#define RR 1
#define _R 2

static int count_moves(t_stack_compose *stack, t_stack *a, t_stack *b, int index_from);

/*static char **moves_to_top_sevabbè(int index, int len)
{
	char **moves;
	int i;

	moves = ft_calloc(index / 2, sizeof(char *));
	i = 0;
	while(i < index / 2)
	{
		moves[i] = ft_calloc(2, sizeof(char));
		i++;
	}
	i = 0;
	if(index > len / 2)
		while(i < len - index){
			ft_strlcpy(moves[i], "r", 1);
			i++;
		}
	else
		while (i < index){
			ft_strlcpy(moves[i], "rr", 2);
			i++;
		}
	return (moves);
}*/

// moves[0] = moves count; moves[1] = 0:rotate | 1:rev rotate | 2:equivalent
static int *moves_to_top(int index, int lenght, int moves[2])
{
	if (index > lenght / 2)
	{
		moves[0] = lenght - index;
		moves[1] = 1;
	}
	else
	{
		moves[0] = index;
		moves[1] = 0;
		if(lenght % 2 == 0 && index == lenght / 2)
			moves[1] = 2;
	}
	return (moves);
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


// n_moves + 1 perchè il push è sottointeso
static int count_moves(t_stack_compose *stack, t_stack *a, t_stack *b, int index_from)
{
	int n_moves;
	int a_to_top[2];
	int b_to_top[2];
	int target_index;

	(void) stack; //debug
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
	n_moves = a_to_top[0] + b_to_top[0];
	return (n_moves);
}

/* potrei salvare tutte le mosse in un array di puntatori a funzione e poi eseguirle*/
void mechanical_turk(t_stack_compose *stack, t_stack *a, t_stack *b)
{
	void (*cheapest_move)(void);

	b->push();
	b->push();

	if(b->list[0] < b->list[1])
		swap_values(b->list + 0, b->list + 1);

/****************da rimuovere***************/
	int	n_moves;
	int	i;
	int	tmp;

	n_moves = count_moves(stack, a, b, 0);
	i = 1;
	while(i < a->lenght)
	{
		tmp = count_moves(stack, a, b, i);
		if(tmp < n_moves)
			n_moves = tmp;
		i++;
	}
	ft_printf("\nnumero mosse: %i", n_moves);
/*******************fine da rimuovere********/

	cheapest_move = find_cheapest_move(stack, a, b);
	(void) cheapest_move; //debug
}
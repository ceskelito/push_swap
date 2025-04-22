/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:16:58 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/22 12:27:17 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
#include "../headers/push_swap.h"
#include "../headers/ordering_utils.h"

static int find_target_index_b(int num, t_stack *b)
{
	int i;
	int target_index;
	int biggest_index;
	int diff;

	i = 0;
	target_index = -1;
	biggest_index = 0;
	diff = INT_MAX;
	while(i < b->lenght)
	{
		if(num > b->list[i] && num - b->list[i] < diff)
		{
			target_index = i;
			diff = num - b->list[i];
		}
		if(b->list[i] > b->list[biggest_index])
			biggest_index = i;
		i++;
	}
	if(target_index < 0)
		return(biggest_index);
	return(target_index);
}

static void optimize(t_moves_set *moves)
{
	if(!moves)
		return;
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

    best_moves = new_moves_set();
    best_moves->total = INT_MAX;
    i = 0;
    while(i < s->a->lenght){
        target = find_target_index_b(s->a->list[i], s->b);
        new_moves = new_moves_set();
		free(new_moves->a);
		free(new_moves->b);
        new_moves->a = get_moves_to_top(i, s->a->lenght);
        new_moves->b = get_moves_to_top(target, s->b->lenght);
        optimize(new_moves);
        if(new_moves->total < best_moves->total){
            free_moves_set(best_moves, "abt");
            best_moves = new_moves;

        }
		else
            free_moves_set(new_moves, "abt");
        i++;
    }
    return (best_moves);
}

void DEBUG_PRINT(char name);

void mechanical_turk(t_stack_compose *stack, t_stack *a, t_stack *b)
{
	int i;
	t_moves_set *moves;

	if(is_sorted(a))
		return;
	b->push();
	b->push();
	if(b->list[0] < b->list[1])
		b->swap();
	while(a->lenght > 3){
		if(is_sorted(a))
			order_stack_a(stack);
		moves = get_cheapest_moves_set(stack);
		translate_moves(moves, stack, "abt");
		exec(moves, "abt");
		free_moves_set(moves, "abt");
		b->push();
		
	}
	i = b->lenght - 1;
	while(i < b->lenght - 1){
		if(b->list[i] < b->list[i + 1]){
			b->rotate();
			i = 0;
			continue;
		}
		i++;
	}
	order_stack_a(stack);
}

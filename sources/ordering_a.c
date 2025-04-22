/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:21:55 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/22 16:49:52 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/ordering_utils.h"

static void order_three_nums(t_stack *a)
{
    if(is_sorted(a)){
        return;
    }
	if(a->lenght > 3)
        exit_error();
	if (a->list[0] > a->list[1] && a->list[1] < a->list[2])
	{
		if (a->list[0] < a->list[2])
			a->swap();
		else
			a->rev_rotate();
	}
	else if (a->list[0] > a->list[1] && a->list[1] > a->list[2])
		a->rotate();
	else if (a->list[0] < a->list[1] && a->list[1] > a->list[2])
		a->rev_rotate();
}

static int find_target_index_a(int num, t_stack *a)
{
    int i = 0;
    int target_index = -1;
    int min_diff = INT_MAX;
    int min_index = 0;

    // Trova il più piccolo valore maggiore di num
    while (i < a->lenght)
    {
        if (a->list[i] > num && a->list[i] - num < min_diff)
        {
            min_diff = a->list[i] - num;
            target_index = i;
        }
        if (a->list[i] < a->list[min_index])
            min_index = i;
        i++;
    }
    if (target_index == -1)
        return min_index;
    return target_index;
}

static void last_ordering_a(t_stack *a)
{
    int min_index = 0;
    int i = 1;
    
    if(is_sorted(a)){
        return;
    }
	while (i < a->lenght) {
        if (a->list[i] < a->list[min_index])
            min_index = i;
        i++;
    }
    if (min_index <= a->lenght / 2) {
        while (min_index-- > 0)
            a->rotate();
    }
    else {
        int count = a->lenght - min_index;
        while (count-- > 0)
            a->rev_rotate();
    }
}

void DEBUG_PRINT(char name);

void order_stack_a(t_stack_compose *stack)
{
	t_moves_set	*moves;
	int			target;

	order_three_nums(stack->a);
	while(stack->b->lenght > 0){
		target = find_target_index_a(stack->b->list[0], stack->a);
		moves = new_moves_set();
		free(moves->a);
		moves->a = get_moves_to_top(target, stack->a->lenght);
		translate_moves(moves, stack, "a");
		exec(moves, "a");
		stack->a->push();
	}
	last_ordering_a(stack->a);
	// free_moves_set(moves, "a");
	// DEBUG_PRINT('a');
	// DEBUG_PRINT('b');

}

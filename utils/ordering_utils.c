#include "../headers/ordering_utils.h"
#include <stdlib.h>

void	exit_error(void);

t_moves *get_moves_to_top(int index_from, int lenght)
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

void free_moves_set(t_moves_set *moves)
{
	if(!moves)
		return;
	free(moves->a);
	free(moves->b);
	free(moves->twin);
	free(moves);
}	
void exec(t_moves *moves)
{
	if(!moves || !moves->to_exec)
		return;
	while(moves->count > 0)
	{
		moves->to_exec();
		moves->count--;
	}
}

static void translate_moves_single(t_moves *moves_set, t_stack *stack_name)
{
	if(!moves_set || !stack_name)
		exit_error();
	if(moves_set->dir == 0 || moves_set->dir == 2)
		moves_set->to_exec = stack_name->rotate;
	else
		moves_set->to_exec = stack_name->rev_rotate;
}

void translate_moves(t_moves_set *moves, t_stack_compose *stack)
{
	translate_moves_single(moves->a, stack->a);
	translate_moves_single(moves->b, stack->b);
	if(moves->twin->dir == 0 || moves->twin->dir == 2)
		moves->twin->to_exec = rr;
	else
		moves->twin->to_exec = rrr;
}
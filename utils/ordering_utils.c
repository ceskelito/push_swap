#include "../headers/ordering_utils.h"
#include <stdlib.h>

void	exit_error(void);

static void free_if_different(void *to_free, void *comparison)
{
	if(to_free != comparison)
		free(to_free);
}

void free_moves_set(t_moves_set *moves, t_moves_set *comparison)
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
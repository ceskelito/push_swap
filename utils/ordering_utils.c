#include "../headers/push_swap.h"
#include <stdlib.h>

void	free_moves_set(t_moves_set *moves, char *names)
{
	if (!moves)
		return ;
	if (ft_strchr(names, 'a'))
		free(moves->a);
	if (ft_strchr(names, 'b'))
		free(moves->b);
	if (ft_strchr(names, 't'))
		free(moves->twin);
	free(moves);
}

static void	exec_single(t_moves_single *moves)
{
	if (!moves || !moves->to_exec)
		return ;
	while (moves->count > 0)
	{
		moves->to_exec();
		moves->count--;
	}
}
void	exec(t_moves_set *moves, char *names)
{
	if (!moves)
		return ;
	if (ft_strchr(names, 't'))
		exec_single(moves->twin);
	if (ft_strchr(names, 'a'))
		exec_single(moves->a);
	if (ft_strchr(names, 'b'))
		exec_single(moves->b);
}

static void	translate_moves_single(t_moves_single *moves, t_stack *stack_name)
{
	if (!moves || !stack_name)
		return ;
	if (moves->dir == 0 || moves->dir == 2)
		moves->to_exec = stack_name->rotate;
	else
		moves->to_exec = stack_name->rev_rotate;
}

void	translate_moves(t_moves_set *moves_set, t_stack_compose *stack,
		char *names)
{
	if (ft_strchr(names, 'a'))
		translate_moves_single(moves_set->a, stack->a);
	if (ft_strchr(names, 'b'))
		translate_moves_single(moves_set->b, stack->b);
	if (ft_strchr(names, 't'))
	{
		if (moves_set->twin->dir == 0 || moves_set->twin->dir == 2)
			moves_set->twin->to_exec = rr;
		else
			moves_set->twin->to_exec = rrr;
	}
}
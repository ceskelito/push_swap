#include "../headers/push_swap.h"
#include <stdbool.h>

static void swap_values(long *a, long *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

static t_stack *expand_stack(t_stack *stack)
{
	t_stack *new_stack;
	
	new_stack = ft_calloc(1, sizeof(stack));
	new_stack->list = ft_calloc(stack->lenght + 1, sizeof(int));
	ft_memcpy(new_stack, stack, sizeof(stack));
	new_stack->size++;
	return (new_stack);
}

void swap(t_stack *stack)
{
	if(stack->lenght < 2)
		return;
	swap_values(&stack->list[0], &stack->list[1]);
}

void push(t_stack *dest, t_stack *src)
{
	if (src->lenght < 1)
		return;
	if (dest->size == dest->lenght)
		dest = expand_stack(dest);
	rev_rotate(dest);
	dest->list[0] = src->list[0];
	src->list[0] = 0;
	rotate(src);
	src->lenght--;
	dest->lenght++;
}

void rotate(t_stack *stack)
{
	int i;
	
	i = 0;
	while(i < stack->lenght - 1)
	{
		swap_values(&stack->list[i], &stack->list[i + 1]);
		i++;
	}
}

void rev_rotate(t_stack *stack)
{
	int i;
	
	i = stack->lenght -1;
	while(i > 0)
	{
		swap_values(&stack->list[i], &stack->list[i - 1]);
		i--;
	}
}



// exec_move(char *move)
// {
// 	bool double_move;
	
// 	double_move = false;
// 	if(!(ft_strchr('a', move) || ft_strchr('b', move)))
// 		double_move = true;
// }
#include "../headers/push_swap.h"
#include <stdbool.h>
#include <stdarg.h>
#define MOVE_IS(a) (ft_strcmp(move, a) == 0)

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
	if(!stack || stack->lenght < 2)
		return;
	swap_values(&stack->list[0], &stack->list[1]);
}

void push(t_stack *dest, t_stack *src)
{
	if (!dest || !src || src->lenght < 1)
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
	
	if(!stack)
		return;
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
	
	if(!stack)
		return;
	i = stack->lenght -1;
	while(i > 0)
	{
		swap_values(&stack->list[i], &stack->list[i - 1]);
		i--;
	}
}

void exec_move(char *move, ...)
{
	va_list 					args;
	bool						double_move;
	t_stack						*target;
	static t_stack_compose 		*stack;
	void 						(*move_ptr)(t_stack *stack);

	if(ft_strcmp(move, "init") == 0)
	{
		va_start(args, move);
		stack = va_arg(args, t_stack_compose *);
		return;
	}
	double_move = false;
	if(ft_strchr(move, 'a'))
		target = stack->a;
	else if(ft_strchr(move, 'b'))
		target = stack->b;
	else double_move = true;
	if(MOVE_IS("pa"))
	{
		/***/
	}
	else if (MOVE_IS("pb"))
	{
		/***/
	}
	else
	move_ptr = select_move(move, stack, double_move);
	
}

void (*select_move(char *move, t_stack_compose *stack, bool double_move))(t_stack *ptr)
{
	if(double_move)
	{
		if(MOVE_IS("ss"))
		{
			swap(stack->a);
			swap(stack->b);
		}

	}
	if(MOVE_IS("sa"))
		push(stack->a);
	else if(MOVE_IS(""))
}

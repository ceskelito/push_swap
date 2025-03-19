#include "../headers/push_swap.h"
#include <stdarg.h>

void exit_error(void)
{
	ft_printf("Error");
	exit(EXIT_FAILURE);
}

void swap_values(long *a, long *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

t_stack *get_address(int stack_name, ...)
{
	static t_stack	*stack_a;
	static t_stack	*stack_b;
	char			stack_to_set;
	va_list			args;

	if(stack_name == 's')
	{
		va_start(args, stack_name);
		stack_to_set = va_arg(args, int);
		if(stack_to_set == 'a')
			stack_a = va_arg(args, t_stack *);
		else if (stack_to_set == 'b')
			stack_b = va_arg(args, t_stack *);
		else
		{
			va_end(args);
			exit_error();
		}
			
		va_end(args);
		return NULL;
	}
	if(stack_name == 'a' && stack_a)
		return stack_a;
	if(stack_name == 'b' && stack_b)
		return stack_b;
	exit_error();
	return NULL;
}

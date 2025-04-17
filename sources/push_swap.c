/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:20 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/17 20:09:21 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

void	DEBUG_PRINT(char name)
{
	t_stack *stack = get_address(name);
	ft_printf("\n----start----\n");
	/* ft_printf("%c.lenght = %i\n", name, stack->lenght);
	ft_printf("%c.size = %i\n", name, stack->size); */
	for (int i = 0; i < stack->lenght; i++)
		ft_printf("%c[%i] = %i\n", name, i, stack->list[i]);
	ft_printf("-----end-----\n");
}

static void free_stack(t_stack_compose *stack)
{
	if (stack->a)
	{
		if (stack->a->list)
			free(stack->a->list);
		free(stack->a);
	}
	if (stack->b)
	{
		if (stack->b->list)
			free(stack->b->list);
		free(stack->b);
	}
}

int	main(int argc, char **argv)
{
	t_stack_compose	stack;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	stack = new_stack_compose();
	free(stack.a);
	stack.a = create_stack(argv);
	stack.a->swap = sa;
	stack.a->push = pa;
	stack.a->rotate = ra;
	stack.a->rev_rotate = rra;
	get_address('s', 'a', stack.a);
	stack.b->list = ft_calloc(stack.a->size, sizeof(long));
	stack.b->size = stack.a->size;
	stack.b->lenght = 0;
	// DEBUG_PRINT('a');
	// DEBUG_PRINT('b');
	mechanical_turk(&stack, stack.a, stack.b);
	DEBUG_PRINT('a');
	DEBUG_PRINT('b');
	free_stack(&stack);
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:20 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 15:51:18 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

// void	DEBUG_PRINT(char name)
// {
// 	t_stack *stack = get_address(name);
// 	ft_printf("\n---%c---%c---%c---\n", name, name, name);
// 	/* ft_printf("%c.length = %i\n", name, stack->length);
// 	ft_printf("%c.size = %i\n", name, stack->size); */
// 	for (int i = 0; i < stack->length; i++)
// 		ft_printf("%c[%i] = %i\n", name, i, stack->list[i]);
// 	ft_printf("---%c---%c---%c---\n", name, name, name);
// }

static void	free_stack(t_stack_compose *stack)
{
	if (!stack)
		return ;
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
	if (!stack.a || !stack.b)
		exit_msg("Error\n\n");
	free(stack.a);
	stack.a = create_stack(argv);
	if (!stack.a)
		exit_msg("Error\n\n");
	stack.b->list = ft_calloc(stack.a->size, sizeof(long));
	stack.b->size = stack.a->size;
	stack.b->length = 0;
	mechanical_turk(&stack, stack.a, stack.b);
	free_stack(&stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:20 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/19 14:32:20 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

char	**get_stack_as_a_string_array(char **args)
{
	int		i;
	char	**string_stack;

	string_stack = (char **)malloc(sizeof(char *));
	if (!string_stack)
		exit(EXIT_FAILURE);
	*string_stack = (char *)malloc(sizeof(1));
	if (!*string_stack)
	{
		free(string_stack);
		exit(EXIT_FAILURE);
	}
	*string_stack = "\0";
	i = 0;
	while (args[++i])
		*string_stack = ft_strjoin_multi(3, *string_stack, args[i], " ");
	i = 0;
	while ((*string_stack)[i])
	{
		if (!(ft_isdigit((*string_stack)[i]) || ft_isspace((*string_stack)[i])
				|| (*string_stack)[i] == '-' || (*string_stack)[i] == '+'))
			exit_error();
		i++;
	}
	return (ft_split(*string_stack, ' '));
}

void	set_stack_list(char **string_stack, t_stack *stack)
{
	int	i;
	int	j;

	stack->list = malloc(ft_strlen((char *)string_stack) * sizeof(long int));
	i = 0;
	while (string_stack[i])
	{
		stack->list[i] = ft_atol(string_stack[i]);
		j = i;
		if (stack->list[i] != (int)stack->list[i] || stack->list[i] < 0)
			exit_error();
		while (--j >= 0)
			if (stack->list[i] == stack->list[j])
				exit_error();
		i++;
	}
	stack->lenght = i;
	stack->size = i;
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		exit_error();
	stack->list = NULL;
	stack->size = 0;
	stack->lenght = 0;
	return (stack);
}

t_stack_compose	new_stack_compose(void)
{
	t_stack_compose	stack;

	stack.ss = ss;
	stack.rr = rr;
	stack.rrr = rrr;
	stack.a = new_stack();
	get_address('s', 'a', stack.a);
	stack.a->swap = sa;
	stack.a->push = pa;
	stack.a->rotate = ra;
	stack.a->rev_rotate = rra;
	stack.b = new_stack();
	get_address('s', 'b', stack.b);
	stack.b->swap = sb;
	stack.b->push = pb;
	stack.b->rotate = rb;
	stack.b->rev_rotate = rrb;
	return (stack);
}

void	DEBUG_PRINT(t_stack *stack, char name)
{
	ft_printf("\n----start----\n");
	ft_printf("%c.lenght = %i\n", name, stack->lenght);
	ft_printf("%c.size = %i\n", name, stack->size);
	for (int i = 0; i < stack->lenght; i++)
		ft_printf("%c[%i] = %i\n", name, i, stack->list[i]);
	ft_printf("-----end-----\n");
}

int	main(int ac, char **av)
{
	char					**string_stack;
	static t_stack_compose	stack;

	if (ac <= 1)
		exit(EXIT_SUCCESS);
	stack = new_stack_compose();
	string_stack = get_stack_as_a_string_array(av);
	set_stack_list(string_stack, stack.a);
	DEBUG_PRINT(stack.a, 'a');
	stack.b->push();
	stack.b->push();
	DEBUG_PRINT(stack.a, 'a');
	DEBUG_PRINT(stack.b, 'b');
}

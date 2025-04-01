/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:20 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/28 12:00:45 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

char	**get_stack_as_a_string_array(char **args)
{
	int		i;
	char	*formatted_args;
	char	**string_array;
	char	*ptr;

	formatted_args = ft_calloc(1, sizeof(char));
	if (!formatted_args)
		exit(EXIT_FAILURE);
	*formatted_args = '\0';
	i = 0;
	while (args[++i])
	{
		ptr = formatted_args;
		formatted_args = ft_strjoin_multi(3, formatted_args, args[i], " ");
		free(ptr);
	}
	i = 0;
	while (formatted_args[i])
	{
		if (!(ft_isdigit(formatted_args[i]) || ft_isspace(formatted_args[i])
				|| formatted_args[i] == '-' || formatted_args[i] == '+'))
		{
			free(formatted_args);
			exit_error();
		}
		i++;
	}
	string_array = ft_split(formatted_args, ' ');
	if(formatted_args)
		free(formatted_args);
	return (string_array);
}

static int count_words(char **array)
{
    int i;

    i = 0;
    while(array[i])
        i++;
    return (i);
}

void	init_stacks(char **string_stack, t_stack_compose *stack)
{
	int	i;
	int	j;

	stack->a->list = malloc(count_words(string_stack) * sizeof(long int));
	stack->b->list = malloc(count_words(string_stack) * sizeof(long int));
	if (!stack->a->list || !stack->b->list)
        exit_error();
	i = 0;
	while (string_stack[i])
	{
		stack->a->list[i] = ft_atol(string_stack[i]);
		if (stack->a->list[i] < 0 || stack->a->list[i] > INT_MAX)
			exit_error();
		j = i;
		while (--j >= 0)
			if (stack->a->list[i] == stack->a->list[j])
				exit_error();
		i++;
	}
	stack->a->size = i;
	stack->a->lenght = i;
	stack->b->size = i;
	stack->b->lenght = 0;

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

static void free_string_stack(char **string_stack)
{
	int	i;

	i = 0;
	while(string_stack[i])
	{
		free(string_stack[i]);
		i++;
	}
	if(string_stack)
		free(string_stack);
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

int	main(int ac, char **av)
{
	char					**string_stack;
	static t_stack_compose	stack;

	if (ac <= 1)
		exit(EXIT_SUCCESS);
	stack = new_stack_compose();
	string_stack = get_stack_as_a_string_array(av);
	init_stacks(string_stack, &stack);
	free_string_stack(string_stack);
	DEBUG_PRINT(stack.a, 'a');
	mechanical_turk(&stack, stack.a, stack.b);
	free_stack(&stack);
	
}

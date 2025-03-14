/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:20 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/14 17:36:00 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	exit_error(void)
{
	ft_printf("Error");
	exit(EXIT_FAILURE);
}

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
		if (!(ft_isdigit((*string_stack)[i]) || ft_isspace((*string_stack)[i]) || 
			(*string_stack)[i] == '-' || (*string_stack)[i] == '+'))
			exit_error();
		i++;
	}
	return (ft_split(*string_stack, ' '));
}

t_stack	get_stack(char **string_stack)
{
	int				i;
	int				j;
	t_stack	stack;

	stack.list = malloc(ft_strlen((char *)string_stack) * sizeof(long int));
	i = 0;
	while (string_stack[i])
	{
		stack.list[i] = ft_atol(string_stack[i]);
		j = i;
		if (stack.list[i] != (int)stack.list[i] || stack.list[i] < 0)
			exit_error();
		while (--j >= 0)
			if (stack.list[i] == stack.list[j])
				exit_error();
		i++;
	}
	stack.lenght = i;
	stack.size = i;
	return (stack);
}


t_stack *new_stack()
{
	t_stack *stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->list = NULL;
	stack->size = 0;
	stack->lenght = 0;
	return (stack);
}

void DEBUG_PRINT(t_stack *stack, char name)
{
	ft_printf("\n----start----\n");
	ft_printf("%c.lenght = %i\n", name, stack->lenght);
	ft_printf("%c.size = %i\n", name, stack->size);
	for(int i = 0; i < stack->lenght; i++)
		ft_printf("%c[%i] = %i\n", name, i, stack->list[i]);
	ft_printf("-----end-----\n");

}

int	main(int ac, char **av)
{
	char					**string_stack;
	static t_stack_compose	stack;
	if (ac <= 1)
		exit(EXIT_SUCCESS);
	stack.a = new_stack();
	stack.b = new_stack();
	string_stack = get_stack_as_a_string_array(av);
	*stack.a = get_stack(string_stack);
	
	DEBUG_PRINT(stack.a, 'a');
	DEBUG_PRINT(stack.b, 'b');
	
#ifdef MOVE
	MOVE(NULL);
	DEBUG_PRINT(stack.a, 'a');
	DEBUG_PRINT(stack.b, 'b');
#endif

}

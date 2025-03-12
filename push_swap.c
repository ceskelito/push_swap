/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:20 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/12 15:30:36 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!(ft_isdigit((*string_stack)[i]) || ft_isspace((*string_stack)[i])))
			exit_error();
		i++;
	}
	return (ft_split(*string_stack, ' '));
}

t_stack_single	get_stack(char **string_stack)
{
	int				i;
	int				j;
	t_stack_single	stack;

	stack.list = malloc(ft_strlen((char *)string_stack) * sizeof(long int));
	i = 0;
	while (string_stack[i])
	{
		stack.list[i] = ft_atol(string_stack[i]);
		j = i;
		if (stack.list[i] != (int)stack.list[i])
			exit_error();
		while (--j >= 0)
			if (stack.list[i] == stack.list[j])
				exit_error();
		i++;
	}
	stack.size = i;
	stack.capacity = i;
	return (stack);
}

int	main(int ac, char **av)
{
	int						i;
	char					**string_stack;
	static t_stack_compose	stack;

	if (ac <= 1)
		exit(EXIT_SUCCESS);
	string_stack = get_stack_as_a_string_array(av);
	i = 0;
	stack.a = get_stack(string_stack);
	stack.b.list = ft_calloc(1, sizeof(stack.a));
	i = 0;
	while (stack.a.list[i])
	{
		ft_printf("stack_a[%i] = %i\t\t\t", i, stack.a.list[i]);
		ft_printf("stack_b[%i] = %i\n", i, stack.b.list[i]);
		i++;
	}
}

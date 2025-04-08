/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:26:42 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/08 11:22:47 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

static char *join_args(char **args)
{
	char	*str;
	char	*tmp;
	int		i;

	str = ft_calloc(1, sizeof(char));
	i = 0;
	while (args[++i])
	{
		tmp = str;
		str = ft_strjoin_multi(3, str, args[i], " ");
		free(tmp);
	}
	return (str);
}

static void free_string_array(char **string_stack, int exit)
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
	if(exit)
		exit_error();
}

static int count_and_check(char **stack)
{
	int	i;
	int	j;

	i = 0;
	while(stack[i])
	{
		j = 0;
		while(stack[i][j])
		{
			if(!(ft_isdigit(stack[i][j]) || 
				stack[i][j] == '+' || stack[i][j] == '-'))
			{
				free_string_array(stack, 0);
				exit_error();
			}
			j++;
		}
		i++;
	}
	return (i);
}

static void fill_stack(t_stack *stack, char **string_stack)
{
	int i;
	int j;
	int len;

	len = count_and_check(string_stack);
	stack->list = ft_calloc(len, sizeof(long));
	if(!stack->list)
		exit(EXIT_FAILURE);
	i = 0;
	while(string_stack[i])
	{
		stack->list[i] = ft_atol(string_stack[i]);
		if(stack->list[i] != (int)stack->list[i])
			free_string_array(string_stack, 1);
		j = i;
		while (--j >= 0)
			if (stack->list[i] == stack->list[j])
				free_string_array(string_stack, 1);
		i++;
	}
	stack->size = len;
	stack->lenght = len;
}

t_stack *create_stack(char **args)
{
	char 	**string_stack;
	char	*joined;
	t_stack	*stack;

	stack = new_stack();
	joined = join_args(args);
	string_stack = ft_split(joined, ' ');
	free(joined);
	fill_stack(stack, string_stack);
	free_string_array(string_stack, 0);
	return (stack);
}
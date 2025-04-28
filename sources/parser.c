/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:26:42 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/26 16:42:32 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

static void free_exit(char *string, char **string_array, t_stack_compose *stack)
{
	if(string)
		free(string);
	if(string_array)
		free_string_array(string_array);
	if(stack)
		free_stack(stack);
	exit_error();
}

static char	*join_args(char **args, t_stack_compose *stack_c)
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
	i = -1;
	while (str[++i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] && !ft_isdigit(str[i + 1]))
				free_exit(str, NULL, stack_c);
			if (i > 0 && !ft_isspace(str[i - 1]))
				free_exit(str, NULL, stack_c);
		}
	}
	return (str);
}


static int	count_and_check(char **stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = 0;
		while (stack[i][j])
		{
			if (!(ft_isdigit(stack[i][j]) || stack[i][j] == '+'
					|| stack[i][j] == '-'))
			{
				free_string_array(stack);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (i);
}

static void	fill_stack(t_stack *stack, char **string_stack, t_stack_compose *stack_c)
{
	int	i;
	int	j;
	int	len;

	len = count_and_check(string_stack);
	if(len < 0)
		free_exit(NULL, NULL, stack_c);
	stack->list = ft_calloc(len, sizeof(long));
	if (!stack->list)
		exit(EXIT_FAILURE);
	i = 0;
	while (string_stack[i])
	{
		stack->list[i] = ft_atol(string_stack[i]);
		if (stack->list[i] != (int)stack->list[i])
			free_exit(NULL, string_stack, stack_c);
		j = i;
		while (--j >= 0)
			if (stack->list[i] == stack->list[j])
				free_exit(NULL, string_stack, stack_c);
		i++;
	}
	stack->size = len;
	stack->length = len;
}

t_stack	*create_stack(char **args, t_stack_compose *stack_c)
{
	char	**string_stack;
	char	*joined;
	t_stack	*stack;

	stack = new_stack('a');
	stack_c->a = stack;
	joined = join_args(args, stack_c);
	string_stack = ft_split(joined, ' ');
	free(joined);
	fill_stack(stack, string_stack, stack_c);
	free_string_array(string_stack);
	return (stack);
}

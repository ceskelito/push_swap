/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:08:20 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/12 13:08:42 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **get_stack_as_a_string_array(char **args)
{
	int			i;
	char		**string_stack;
	
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
	while(args[++i])
	{
		*string_stack = ft_strjoin(*string_stack, args[i]);
		*string_stack = ft_strjoin(*string_stack, " ");
	}
	i = 0;
	while((*string_stack)[i])
	{
		if(!(ft_isdigit((*string_stack)[i]) || ft_isspace((*string_stack)[i])))
		{
			ft_printf("Error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return(ft_split(*string_stack, ' '));
}

long int *get_num_stack(char **string_stack)
{
	int		i;
	int		j;
	long 	*stack;

	stack = malloc(ft_strlen((char *)string_stack) * sizeof(long int));
	i = 0;
	while(string_stack[i])
	{
		stack[i] = ft_atol(string_stack[i]);
		j = i;
		while(j-- >= 0)
			if((i != j && stack[i] == stack[j]) || stack[i] != (int)stack[i])
			{
				ft_printf("Error");
				exit(EXIT_FAILURE);
			}
		i++;
	}
	return (stack);
}

int main(int ac, char **av)
{
	int				i;
	char			**string_stack;
	static t_stack	stack;

	if(ac <= 1)
		exit(EXIT_SUCCESS);
	string_stack = get_stack_as_a_string_array(av);
	i = 0;
	stack.a = get_num_stack(string_stack);
	stack.b = ft_calloc(1, sizeof(stack.a));
	i = 0;
	while(stack.a[i])
	{
		ft_printf("stack_a[%i] = %i\n", i, stack.a[i]);
		ft_printf("stack_b[%i] = %i\n", i, stack.b[i]);
		i++;
	}
}

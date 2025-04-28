/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:43 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 18:25:18 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdarg.h>
#include <stdbool.h>

void	free_string_array(char **string_stack)
{
	int	i;

	i = 0;
	while (string_stack[i])
	{
		free(string_stack[i]);
		i++;
	}
	if (string_stack)
		free(string_stack);
}

void	free_stack(t_stack_compose *stack)
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

void	exit_error(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

/*******ORDERING********/

t_moves_single	*get_moves_to_top(int index_from, int length)
{
	t_moves_single	*moves;

	moves = new_moves();
	if (index_from > length / 2)
	{
		moves->count = length - index_from;
		moves->dir = 1;
	}
	else
	{
		moves->count = index_from;
		moves->dir = 0;
		if (length % 2 == 0 && index_from == length / 2)
			moves->dir = 2;
	}
	return (moves);
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack)
		return (true);
	i = 0;
	while (i < stack->length - 1)
	{
		if (stack->list[i] > stack->list[i + 1])
			return (false);
		i++;
	}
	return (true);
}

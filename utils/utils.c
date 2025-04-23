/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:43 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 14:17:39 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdarg.h>
#include <stdbool.h>

void	exit_msg(char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	else
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

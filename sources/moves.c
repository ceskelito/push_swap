/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:36:02 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/27 13:11:53 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void expand_list(t_stack *stack)
{
	long	*new_list;
	int		i;

	new_list = ft_calloc(stack->size + 1, sizeof(long));
	i = 0;
	while(i < stack->lenght)
	{
		new_list[i] = stack->list[i];
		i++;
	}
	free(stack->list);
	stack->list = new_list;
	stack->size++;
}

void	swap(t_stack *stack)
{
	if (!stack || stack->lenght < 2)
		return ;
	swap_values(&stack->list[0], &stack->list[1]);
}

void	push(t_stack *dest, t_stack *src)
{
	if (!dest || !src || src->lenght < 1)
		return ;
	if (dest->size == dest->lenght)
		expand_list(dest);
	rev_rotate(dest);
	dest->list[0] = src->list[0];
	src->list[0] = 0;
	rotate(src);
	src->lenght--;
	dest->lenght++;
}

void	rotate(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (i < stack->lenght - 1)
	{
		swap_values(&stack->list[i], &stack->list[i + 1]);
		i++;
	}
}

void	rev_rotate(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = stack->lenght - 1;
	while (i > 0)
	{
		swap_values(&stack->list[i], &stack->list[i - 1]);
		i--;
	}
}

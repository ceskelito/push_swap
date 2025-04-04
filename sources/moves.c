/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:36:02 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/28 11:23:57 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap_values(long *a, long *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
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
	dest->lenght++;
	rev_rotate(dest);
	dest->list[0] = src->list[0];
	src->list[0] = 0;
	rotate(src);
	src->lenght--;
	
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

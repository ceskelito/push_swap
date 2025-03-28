/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:53 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/28 11:26:22 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

void	sa(void)
{
	swap(get_address('a'));
}

void	pa(void)
{
	push(get_address('a'), get_address('b'));
}

void	ra(void)
{
	rotate(get_address('a'));
}

void	rra(void)
{
	rev_rotate(get_address('a'));
}

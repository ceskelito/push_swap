/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:50 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/04 14:57:11 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

void	sb(void)
{
	swap(get_address('b'));
}

void	pb(void)
{
	push(get_address('b'), get_address('a'));
}

void	rb(void)
{
	rotate(get_address('b'));
}

void	rrb(void)
{
	rev_rotate(get_address('b'));
}

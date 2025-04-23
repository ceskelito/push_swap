/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:50 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 15:24:24 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	c_sb(void)
{
	swap(get_address('b'));
}

void	c_pb(void)
{
	push(get_address('b'), get_address('a'));
}

void	c_rb(void)
{
	rotate(get_address('b'));
}

void	c_rrb(void)
{
	rev_rotate(get_address('b'));
}

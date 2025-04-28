/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:53 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 15:16:22 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	c_sa(void)
{
	swap(get_address('a'));
}

void	c_pa(void)
{
	push(get_address('a'), get_address('b'));
}

void	c_ra(void)
{
	rotate(get_address('a'));
}

void	c_rra(void)
{
	rev_rotate(get_address('a'));
}

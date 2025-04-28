/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_twin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:47 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 15:24:28 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	c_ss(void)
{
	swap(get_address('a'));
	swap(get_address('b'));
}

void	c_rr(void)
{
	rotate(get_address('a'));
	rotate(get_address('b'));
}

void	c_rrr(void)
{
	rev_rotate(get_address('a'));
	rev_rotate(get_address('b'));
}

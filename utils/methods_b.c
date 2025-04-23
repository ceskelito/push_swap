/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:50 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 12:27:22 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sb(void)
{
	swap(get_address('b'));
	ft_printf("sb\n");
}

void	pb(void)
{
	push(get_address('b'), get_address('a'));
	ft_printf("pb\n");
}

void	rb(void)
{
	rotate(get_address('b'));
	ft_printf("rb\n");
}

void	rrb(void)
{
	rev_rotate(get_address('b'));
	ft_printf("rrb\n");
}

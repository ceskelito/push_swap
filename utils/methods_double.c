/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:47 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/07 15:13:22 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"


void	ss(void)
{
	swap(get_address('a'));
	swap(get_address('b'));
	ft_printf("ss\n");
}

void	rr(void)
{
	rotate(get_address('a'));
	rotate(get_address('b'));
	ft_printf("rr\n");
}

void	rrr(void)
{
	rev_rotate(get_address('a'));
	rev_rotate(get_address('b'));
	ft_printf("rrr\n");
}

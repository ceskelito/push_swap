/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:27:59 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/28 13:16:00 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
#include "../headers/push_swap.h"
#include "../headers/stack_utils.h"

void (*find_cheapest_move(t_stack *a, t_stack *b))(void)
{

}

void mechanical_turk(t_stack *a, t_stack *b)
{
	void (*cheapest_move)(void);

	if(a->list[0] > b->list[0])
		b->push();
	else
		cheapest_move = find_cheapest_move(a, b);
}
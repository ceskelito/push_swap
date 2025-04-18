/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:43 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/18 17:26:48 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdarg.h>
#include <stdbool.h>

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
#include <stdbool.h>

bool is_sorted(t_stack *stack)
{
    int i;

    if (!stack)
        return true;
    i = 0;
	while(i < stack->lenght - 1)
	{
        if (stack->list[i] > stack->list[i + 1])
            return false;
		i++;
	}
	return true;
}
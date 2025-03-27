/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:35:43 by rceschel          #+#    #+#             */
/*   Updated: 2025/03/27 14:53:29 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdarg.h>

void	exit_error(void)
{
	ft_printf("Error");
	exit(EXIT_FAILURE);
}

void	swap_values(long *a, long *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

/*	GET ADDRESS
If called with one argument only, return the address of the stack named
as the argument says.

If the first arg is 's' (means "set"), so the selected by name stack address
is setted in function of the third argument (the stack address).

This function is used in order to call the moves specifically on a stack
without passing any argument.
*/
t_stack	*get_address(int stack_name, ...)
{
	static t_stack	*stack_a;
	static t_stack	*stack_b;
	char			stack_to_set;
	va_list			args;

	if (stack_name == 's')
	{
		va_start(args, stack_name);
		stack_to_set = va_arg(args, int);
		if (stack_to_set == 'a')
			stack_a = va_arg(args, t_stack *);
		else if (stack_to_set == 'b')
			stack_b = va_arg(args, t_stack *);
		va_end(args);
		if((stack_to_set == 'a' && !stack_a) ||
			(stack_to_set == 'b' && !stack_b))
			exit_error();
		return (NULL);
	}
	if (stack_name == 'a' && stack_a)
		return (stack_a);
	else if (stack_name == 'b' && stack_b)
		return (stack_b);
	exit_error();
	return (NULL);
}

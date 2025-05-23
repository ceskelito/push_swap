/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:33:54 by rceschel          #+#                */
/*   Updated: 2025/04/23 16:22:07 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	(*select_move(char *buff))(void)
{
	if (!buff)
		return (NULL);
	if (!ft_strcmp(buff, "sa\n"))
		return (c_sa);
	if (!ft_strcmp(buff, "pa\n"))
		return (c_pa);
	if (!ft_strcmp(buff, "ra\n"))
		return (c_ra);
	if (!ft_strcmp(buff, "rra\n"))
		return (c_rra);
	if (!ft_strcmp(buff, "sb\n"))
		return (c_sb);
	if (!ft_strcmp(buff, "pb\n"))
		return (c_pb);
	if (!ft_strcmp(buff, "rb\n"))
		return (c_rb);
	if (!ft_strcmp(buff, "rrb\n"))
		return (c_rrb);
	if (!ft_strcmp(buff, "ss\n"))
		return (c_ss);
	if (!ft_strcmp(buff, "rr\n"))
		return (c_rr);
	if (!ft_strcmp(buff, "rrr\n"))
		return (c_rrr);
	return (NULL);
}

static void	(*get_move())(void)
{
	char	*buff;
	void	(*move)(void);

	buff = get_next_line(STDIN_FILENO);
	move = select_move(buff);
	free(buff);
	return (move);
}

void	init_b(t_stack_compose *stack)
{
	stack->b->list = ft_calloc(stack->a->size, sizeof(long));
	stack->b->size = stack->a->size;
	stack->b->length = 0;
}

int	main(int argc, char **argv)
{
	t_stack_compose	stack;
	void			(*move)(void);

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	stack = new_stack_compose();
	free(stack.a);
	stack.a = create_stack(argv, &stack);
	if (!stack.a || !stack.b)
		exit_error();
	stack.b->list = ft_calloc(stack.a->size, sizeof(long));
	stack.b->size = stack.a->size;
	stack.b->length = 0;
	move = get_move();
	while (move)
	{
		move();
		move = get_move();
	}
	if (is_sorted(stack.a))
		write(1, "OK\n", 2);
	else
		write(1, "KO\n", 2);
	free_stack(&stack);
}

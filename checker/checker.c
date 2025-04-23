/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:33:54 by rceschel          #+#    #+#             */
/*   Updated: 2025/04/23 15:46:11 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void (*select_move(char *buff))(void)
{

    if(!ft_strcmp(buff, "sa"))
        return (c_sa);
    if(!ft_strcmp(buff, "pa"))
        return (c_pa);
    if(!ft_strcmp(buff, "ra"))
        return (c_ra);
    if(!ft_strcmp(buff, "rra"))
        return (c_rra);
    if(!ft_strcmp(buff, "sb"))
        return (c_sb);
    if(!ft_strcmp(buff, "pb"))
        return (c_pb);
    if(!ft_strcmp(buff, "rb"))
        return (c_rb);
    if(!ft_strcmp(buff, "rrb"))
        return (c_rrb);
    if(!ft_strcmp(buff, "ss"))
        return (c_ss);
    if(!ft_strcmp(buff, "rr"))
        return (c_rr);
    if(!ft_strcmp(buff, "rrr"))
        return (c_rrr);
    return (NULL);
}


static void (*get_move())(void)
{
    int     r;
    int     i;
    char    c;
    char    buff[5];

    i = 0;
    c = 0;
    while(c != '\n')
    {
        r = read(1, &c, 1);
        if(r <= 0)
            break;
        buff[i] = c;
        i++;
    }
    return (select_move(buff));
}

static void	free_stack(t_stack_compose *stack)
{
	if (!stack)
		return ;
	if (stack->a)
	{
		if (stack->a->list)
			free(stack->a->list);
		free(stack->a);
	}
	if (stack->b)
	{
		if (stack->b->list)
			free(stack->b->list);
		free(stack->b);
	}
}

int main(int argc, char **argv)
{
    t_stack_compose stack;
    void (*move)(void);
    
    if (argc <= 1)
		exit(EXIT_SUCCESS);  
	stack = new_stack_compose();
	if (!stack.a || !stack.b)
		exit_msg("Error\n");
	free(stack.a);
	stack.a = create_stack(argv);
	if (!stack.a)
		exit_msg("Error\n");
    stack.b->list = ft_calloc(stack.a->size, sizeof(long));
	stack.b->size = stack.a->size;
	stack.b->length = 0;  
	move = get_move();
    while(move){
        move();
        move = get_move();
    }
    if(is_sorted(stack.a))
        write(1, "OK", 2);
    else
        write(1, "KO", 2);
    free_stack(&stack);
}

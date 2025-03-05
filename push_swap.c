#include "LIBFT/headers/libft.h"
#include <stdio.h>
#include <unistd.h>

//da eliminare 
static long     ft_atol(char *str)
{
        long    num;
        int     sign;

        num = 0;
        sign = 1;
        if (*str == '-')
        {
                sign = -sign;
                str++;
        }
        while (*str)
        {
                num *= 10;
                num += (*str - '0');
                str++;
        }
        return (num * sign);
}
//da eliminare

char **get_stack_as_a_string_array(char **args)
{
	int			i;
	char		**string_stack;

	string_stack = NULL;
	
	string_stack = (char **)malloc(sizeof(char *));
	if (!string_stack)
		exit(EXIT_FAILURE);
	
	*string_stack = (char *)malloc(sizeof(1));
	if (!*string_stack)
	{
		free(string_stack);
		exit(EXIT_FAILURE);
	}
	
	*string_stack = "\0";
	i = 0;
	while(args[++i])
	{
		*string_stack = ft_strjoin(*string_stack, args[i]);
		*string_stack = ft_strjoin(*string_stack, " ");
	}
	i = 0;
	while((*string_stack)[i])
	{
		if(!(ft_isdigit((*string_stack)[i]) || ft_isspace((*string_stack)[i])))
		{
			ft_printf("Error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return(ft_split(*string_stack, ' '));
}

long int *get_num_stack(char **string_stack)
{
	int			i;
	int			j;
	long int	*stack;

	stack = malloc(ft_strlen((char *)string_stack) * sizeof(long int));
	i = 0;
	while(string_stack[i])
	{
		stack[i] = ft_atol(string_stack[i]);
		j = i;
		while(--j >= 0)
			if(stack[i] == stack[j] || stack[i] != (int)stack[i])
			{
				ft_printf("Error");
				exit(EXIT_FAILURE);
			}
		i++;
	}
	return (stack);
}

int main(int ac, char **av)
{
	int			i;
	char		**string_stack;
	long int	*stack;

	string_stack = get_stack_as_a_string_array(av);
	
	i = 0;
	stack = get_num_stack(string_stack);
	i = 0;
	while(stack[i])
	{
		ft_printf("stack[%i] = %i\n", i, stack[i]);
		i++;
	}
}

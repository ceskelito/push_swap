#include "LIBFT/headers/libft.h"

int fill_stack(const char ***list, long int **stack, int is_allocd)
{
	int			i;
	int			j;
	int			n;
	
	i = 0;
	n = 0;
	while(list[i])
	{
		j = 0;
		while(list[i][j])
		{
			if(is_allocd)
			{
				(*stack)[n] = ft_atoi(list[i][j]);
				//ft_printf("stack[%i] = %i\n", n, (*stack)[n]);
			}
			j++;
			n++;
		}
		i++;
	}
	if(!is_allocd)
	{
		*stack = malloc(n * sizeof(int));
		if(!stack)
			return 0;		
		fill_stack(list, stack, 1);
	}
	return 1;
}

int main(int ac, char **av)
{
	int			i;
	int			j;
	long int	*stack;
	char		***list;

	i = 0;
	while(av[++i])
	{
		j = 0;
		while(av[i][j])
		{
			if(!(ft_isdigit(av[i][j]) || ft_isspace(av[i][j])))
			{
				ft_printf("Error");
				exit(EXIT_FAILURE);
			}
			j++;
		}
	}

	list = malloc((ac) * sizeof(char**));
	if(!list)
		exit(EXIT_FAILURE);
	i = 0;
	while(av[++i])
		list[i - 1] = ft_split(av[i], ' ');
	if(!fill_stack((const char ***)list, &stack, 0))
		exit(EXIT_FAILURE);
	i = 0;
	while(stack[i])
	{
		ft_printf("stack[%i] = %i\n", i, stack[i]);
		i++;
	}
}
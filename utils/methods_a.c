#include "../headers/push_swap.h"

void sa(void)
{
	swap(get_address('a'));
}

void pa(void)
{
	push(get_address('a'), get_address('b'));
}

void ra(void)
{
	rotate(get_address('a'));
}

void rra(void)
{
	rev_rotate(get_address('a'));
}
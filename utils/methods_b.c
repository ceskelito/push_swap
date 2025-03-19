#include "../headers/push_swap.h"

void sb(void)
{
	swap(get_address('b'));
}

void pb(void)
{
	push(get_address('b'), get_address('a'));
}

void rb(void)
{
	rotate(get_address('b'));
}

void rrb(void)
{
	rev_rotate(get_address('b'));
}
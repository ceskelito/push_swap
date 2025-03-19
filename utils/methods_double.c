#include "../headers/push_swap.h"

void ss(void)
{
	swap(get_address('a'));
	swap(get_address('b'));
}

void rr(void)
{
	rotate(get_address('a'));
	rotate(get_address('b'));
}

void rrr(void)
{
	rev_rotate(get_address('a'));
	rev_rotate(get_address('b'));
}
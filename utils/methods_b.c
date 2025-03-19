#include "../headers/push_swap.h"

void swap_b(void)
{
	swap(get_address('b'));
}

void push_b(void)
{
	push(get_address('b'), get_address('a'));
}

void rotate_b(void)
{
	rotate(get_address('b'));
}

void rev_rotate_b(void)
{
	rev_rotate(get_address('b'));
}
#include "ft_push_swap.h"

void rra(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return ;
	stack_a->head = (stack_a->head - 1 + stack_a->cap) % stack_a->cap;
	stack_a->data[indexer(stack_a, 0)] = stack_a->data[indexer(stack_a, stack_a->size - 1)];
	ft_printf(1, "rra\n");
}
#include "ft_push_swap.h"

void	rra(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return ;
	stack_a->head = (stack_a->head - 1 + stack_a->cap) % stack_a->cap;
	stack_a->data[indexer(stack_a, 0)]
		= stack_a->data[indexer(stack_a, stack_a->size)];
	ft_printf(1, "rra\n");
}

void	rrb(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return ;
	stack_b->head = (stack_b->head - 1 + stack_b->cap) % stack_b->cap;
	stack_b->data[indexer(stack_b, 0)]
		= stack_b->data[indexer(stack_b, stack_b->size)];
	ft_printf(1, "rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 2 && stack_a->size < 2)
		return ;
	if (stack_b->size >= 2)
	{
		stack_b->head = (stack_b->head - 1 + stack_b->cap) % stack_b->cap;
		stack_b->data[indexer(stack_b, 0)]
			= stack_b->data[indexer(stack_b, stack_b->size)];
	}
	if (stack_a->size >= 2)
	{
		stack_a->head = (stack_a->head - 1 + stack_a->cap) % stack_a->cap;
		stack_a->data[indexer(stack_a, 0)]
			= stack_a->data[indexer(stack_a, stack_a->size)];
	}
	ft_printf(1, "rrr\n");
}

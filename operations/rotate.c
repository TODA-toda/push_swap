#include "ft_push_swap.h"

void	ra(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return ;
	stack_a->data[indexer(stack_a, stack_a->size)]
		= stack_a->data[indexer(stack_a, 0)];
	stack_a->head = (stack_a->head + 1) % stack_a->cap;
	ft_printf(1, "ra\n");
}

void	rb(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return ;
	stack_b->data[indexer(stack_b, stack_b->size)]
		= stack_b->data[indexer(stack_b, 0)];
	stack_b->head = (stack_b->head + 1) % stack_b->cap;
	ft_printf(1, "rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 && stack_b->size < 2)
		return ;
	if (stack_a->size >= 2)
	{
		stack_a->data[indexer(stack_a, stack_a->size)]
			= stack_a->data[indexer(stack_a, 0)];
		stack_a->head = (stack_a->head + 1) % stack_a->cap;
	}
	if (stack_b->size >= 2)
	{
		stack_b->data[indexer(stack_b, stack_b->size)]
			= stack_b->data[indexer(stack_b, 0)];
		stack_b->head = (stack_b->head + 1) % stack_b->cap;
	}
	ft_printf(1, "rr\n");
}

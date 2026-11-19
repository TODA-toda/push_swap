#include "ft_push_swap.h"

static int	initial_stacks(t_stack *stack_a, t_stack *stack_b, int *nums, int size)
{
	stack_a->data = nums;
	stack_a->cap = size;
	stack_a->size = size;
	stack_a->head = 0;
	stack_b->data = malloc (sizeof(int) * size);
	if (!stack_b->data)
		return (0);
	stack_b->cap = stack_a->cap;
	stack_b->size = 0;
	stack_b->head = stack_a->head;
	return (1);
}

int	indexer(t_stack *stack_x, int i)
{
	return ((stack_x->head + i) % stack_x->cap);
}

int	push_swap(int *nums, int size, t_strategy strategy, int bench)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (!initial_stacks(&stack_a, &stack_b, nums, size))
	{
		free(stack_a.data);
		return (0);
	}

	return (1);
}

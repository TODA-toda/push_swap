#include "ft_push_swap.h"

static int	initial_stacks(t_stack *stack_a, t_stack *stack_b, int *nums,
		int size)
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

static float	calc_disorder(t_stack *stack_a)
{
	int	total_pairs;
	int	inverted_pairs;
	int	i;
	int	j;

	if (stack_a->size < 2)
		return (0.00f);
	total_pairs = 0;
	inverted_pairs = 0;
	i = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (stack_a->data[indexer(stack_a, i)] > stack_a->data[indexer(stack_a, j)])
				inverted_pairs++;
			total_pairs++;
			j++;
		}
		i++;
	}
	return ((float)inverted_pairs / total_pairs);
}

static int	free_it(t_stack *stack_a, t_stack *stack_b, int return_value)
{
	if (stack_a)
		free(stack_a->data);
	if (stack_b)
		free(stack_b->data);
	return (return_value);
}

int	ft_push_swap(int *nums, int size, t_strategy strategy, int bench)
{
	t_stack	stack_a;
	t_stack	stack_b;
	float	disorder;
	int	(*strategies[4])(t_stack *, t_stack *, float);

	(void)bench;
	if (!initial_stacks(&stack_a, &stack_b, nums, size))
		return (free_it(&stack_a, NULL, 0));
	strategies[ADAPTIVE] = adaptive_sort;
	strategies[SIMPLE] = selection_sort;
	strategies[MEDIUM] = chunk_sort;
	strategies[COMPLEX] = quick_sort;
	disorder = calc_disorder(&stack_a);
	if (disorder == 0.00f)
		return (free_it(&stack_a, &stack_b, 1));
	if (!strategies[strategy](&stack_a, &stack_b, disorder))
		return (free_it(&stack_a, &stack_b, 0));
	return (free_it(&stack_a, &stack_b, 1));
}

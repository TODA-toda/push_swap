#include "ft_push_swap.h"

static int	get_chunk_size(int	size)
{
	int	i;

	i = 0;
	while ((i + 1) <= size / (i + 1))
		i++;
	return (i);
}



static void	push_chunks
	(t_stack *stack_a, t_stack *stack_b, int *sorted_copy, int chunk_size)
{
	int	i;

	i = 0;
	while (stack_a->size)
	{
		
		i++;
	}
}

int	chunk_sort(t_stack *stack_a, t_stack *stack_b, float disorder)
{
	int	chunk_size;
	int	*sorted_copy;

	(void)disorder;
	chunk_size = get_chunk_size(stack_a->size);
	sorted_copy = get_sorted_copy(stack_a);
	if (!sorted_copy)
		return (0);
	push_chunks(stack_a, stack_b, sorted_copy, chunk_size);
}

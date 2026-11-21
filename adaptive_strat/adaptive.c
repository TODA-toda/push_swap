#include "ft_push_swap.h"

int	adaptive_sort(t_stack *stack_a, t_stack *stack_b, float disorder)
{
	if (disorder < 0.20f)
		return (selection_sort(stack_a, stack_b, disorder));
	else if (disorder < 0.50f)
		return (chunk_sort(stack_a, stack_b, disorder));
	return (quick_sort(stack_a, stack_b, disorder));
}

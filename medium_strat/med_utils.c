#include "ft_push_swap.h"

void	temp_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*get_sorted_copy(t_stack *stack_a)
{
	int	*copy;

	copy = malloc (sizeof(int) * stack_a->size);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, stack_a->data, sizeof(int) * stack_a->size);
	temp_sort(copy, stack_a->size);
	return (copy);
}

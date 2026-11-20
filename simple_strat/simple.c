#include "ft_push_swap.h"

static int	get_min_index(t_stack *stack_a)
{
	int	i;
	int	min;
	int	min_index;

	min = stack_a->data[indexer(stack_a, 0)];
	min_index = 0;
	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->data[indexer(stack_a, i)] < min)
		{
			min = stack_a->data[indexer(stack_a, i)];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

static void	move_to_top_push(t_stack *stack_a, t_stack *stack_b, int min_index)
{
	int	i;

	i = 0;
	if (min_index <= stack_a->size - min_index)
	{
		while (i < min_index)
		{
			ra(stack_a);
			i++;
		}
	}
	else
	{
		while (i < stack_a->size - min_index)
		{
			rra(stack_a);
			i++;
		}
	}
	pb(stack_a, stack_b);
}

static void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->data[indexer(stack_a, 0)];
	second = stack_a->data[indexer(stack_a, 1)];
	third = stack_a->data[indexer(stack_a, 2)];
	if (first < second && second > third && first < third)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first < second && second > third && first > third)
		rra(stack_a);
	else if (first > second && second > third && first > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
}

void	selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	if (stack_a->size == 2)
	{
		sa(stack_a);
		return ;
	}
	else if (stack_a->size == 1)
		return ;
	while (stack_a->size > 3)
	{
		min_index = get_min_index(stack_a);
		move_to_top_push(stack_a, stack_b, min_index);
	}
	sort_three(stack_a);
	while (stack_b->size)
		pa(stack_a, stack_b);
}

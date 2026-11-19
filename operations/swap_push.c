#include "ft_push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->data[indexer(stack_a, 0)];
	stack_a->data[indexer(stack_a, 0)] = stack_a->data[indexer(stack_a, 1)];
	stack_a->data[indexer(stack_a, 1)] = temp;
	ft_printf(1, "sa\n");
}

void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->data[indexer(stack_b, 0)];
	stack_b->data[indexer(stack_b, 0)] = stack_b->data[indexer(stack_b, 1)];
	stack_b->data[indexer(stack_b, 1)] = temp;
	ft_printf(1, "sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->size >= 2)
	{
		temp = stack_a->data[indexer(stack_a, 0)];
		stack_a->data[indexer(stack_a, 0)] = stack_a->data[indexer(stack_a, 1)];
		stack_a->data[indexer(stack_a, 1)] = temp;
	}
	if (stack_b->size >= 2)
	{
		temp = stack_b->data[indexer(stack_b, 0)];
		stack_b->data[indexer(stack_b, 0)] = stack_b->data[indexer(stack_b, 1)];
		stack_b->data[indexer(stack_b, 1)] = temp;
	}
	if (stack_a->size >= 2 || stack_b->size >= 2)
		ft_printf(1, "ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 0)
		return ;
	stack_a->head = (stack_a->head - 1 + stack_a->cap) % stack_a->cap;
	stack_a->data[indexer(stack_a, 0)] = stack_b->data[indexer(stack_b, 0)];
	stack_a->size++;
	stack_b->head = (stack_b->head + 1) % stack_b->cap;
	stack_b->size--;
	ft_printf(1, "pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		return ;
	stack_b->head = (stack_b->head - 1 + stack_b->cap) % stack_b->cap;
	stack_b->data[indexer(stack_b, 0)] = stack_a->data[indexer(stack_a, 0)];
	stack_b->size++;
	stack_a->head = (stack_a->head + 1) % stack_a->cap;
	stack_a->size--;
	ft_printf(1, "pb\n");
}
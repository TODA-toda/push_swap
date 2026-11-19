#include "ft_push_swap.h"

static int	free_it(char **arg, char **inputs, int print_err)
{
	size_t	i;

	i = 0;
	if (arg)
	{
		while (arg[i])
			free(arg[i++]);
		free(arg);
	}
	i = 0;
	if (inputs)
	{
		while (inputs[i])
			free(inputs[i++]);
		free(inputs);
	}
	if (print_err)
		ft_printf(2, "Error\n");
	return (1);
}

static int	split_join(int ac, char **av, char ***inputs)
{
	int			i;
	char		**arg;

	*inputs = NULL;
	i = 1;
	while (i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			return (free_it(NULL, *inputs, 1));
		*inputs = ft_arr_of_strjoin(*inputs, arg);
		if (!*inputs)
			return (1);
		i++;
	}
	return (0);
}

static t_strategy	get_strategy(char *str)
{
	if (!ft_strncmp(str, "--adaptive", 11))
		return (ADAPTIVE);
	if (!ft_strncmp(str, "--simple", 9))
		return (SIMPLE);
	if (!ft_strncmp(str, "--medium", 9))
		return (MEDIUM);
	if (!ft_strncmp(str, "--complex", 10))
		return (COMPLEX);
	return (UNSET);
}

static int	get_flags(char **inputs, t_strategy *strategy, int *bench)
{
	int	i;

	*bench = 0;
	i = 0;
	while (inputs[i] && !ft_strncmp(inputs[i], "--", 2))
	{
		if (!ft_strncmp(inputs[i], "--bench", 8))
		{
			if (*bench == 1)
				return (-1);
			*bench = 1;
		}
		else
		{
			if (*strategy != UNSET)
				return (-1);
			*strategy = get_strategy(inputs[i]);
			if (*strategy == UNSET)
				return (-1);
		}
		i++;
	}
	if (*strategy == UNSET)
		*strategy = ADAPTIVE;
	return (i);
}

int	main(int ac, char **av)
{
	int			start_size;
	char		**inputs;
	t_strategy	strategy;
	int			bench;
	int			*nums;

	if (ac == 1)
		return (0);
	if (split_join(ac, av, &inputs) == 1)
		return (1);
	strategy = UNSET;
	start_size = get_flags(inputs, &strategy, &bench);
	if (start_size == -1)
		return (free_it(NULL, inputs, 1));
	nums = ft_get_nums(inputs, start_size, &start_size);
	free_it(NULL, inputs, 0);
	if (!nums)
		return (free_it(NULL, NULL, 1));
	if (!ft_push_swap(nums, start_size, strategy, bench))
		return (free_it(NULL, NULL, 1));
	return (0);
}

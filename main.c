#include "libft_push_swap.h"

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

int main(int ac, char **av)
{
	int		i;
	char	**arg;
	char	**inputs;

	inputs = NULL;
	i = 1;
	while (i < ac)
	{
		arg = ft_split(av[i], ' ');
		if (!arg)
			return (free_it(NULL, inputs, 1));
		inputs = ft_arr_of_strjoin(inputs, arg);
		if (!inputs)
			return (free_it(arg, inputs, 1));
		i++;
	}
	free_it(NULL, inputs, 0);
	return (0);
}

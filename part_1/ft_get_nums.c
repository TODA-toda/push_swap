#include "libft_push_swap.h"

static int	check_dup(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_overflow(char *str)
{
	int	i;
	int	len;
	int	sign;

	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	len = ft_strlen(str + i);
	if (len < 10)
		return (0);
	else if (len > 10)
		return (1);
	if (sign == -1)
		return (ft_strncmp(str + i, "2147483648", 10) > 0);
	return (ft_strncmp(str + i, "2147483647", 10) > 0);
}

static int	check_if_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (check_overflow(str))
		return (0);
	return (1);
}

int	*ft_get_nums(char **inputs, int start, int *size)
{
	int	*nums;
	int	i;

	i = start;
	if (!inputs[i])
		return (NULL);
	while (inputs[i])
	{
		if (!check_if_valid(inputs[i++]))
			return (NULL);
	}
	*size = i - start;
	nums = malloc (sizeof (int) * (*size));
	if (!nums)
		return (NULL);
	i = -1;
	while (++i < *size)
		nums[i] = ft_atoi(inputs[start + i]);
	if (check_dup(nums, *size))
	{
		free(nums);
		return (NULL);
	}
	return (nums);
}

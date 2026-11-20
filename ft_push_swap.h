#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

typedef enum e_strategy
{
	UNSET = -1,
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_stack
{
	int	*data;
	int	cap;
	int	size;
	int	head;
}	t_stack;

int		ft_printf(int fd, const char *format, ...);
int		ft_print_percent(int fd, va_list args);
int		ft_print_character(int fd, va_list args);
int		ft_print_string(int fd, va_list args);
int		ft_print_integer(int fd, va_list args);
int		ft_print_uinteger(int fd, va_list args);
int		ft_print_lowhex(int fd, va_list args);
int		ft_print_upphex(int fd, va_list args);
int		ft_print_hex(int fd, va_list args);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_arr_of_strjoin(char **s1, char **s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_push_swap(int *nums, int size, t_strategy strategy, int bench);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *s);
int		*ft_get_nums(char **inputs, int start, int *size);
int		ft_isdigit(int c);
int		indexer(t_stack *stack_x, int i);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	selection_sort(t_stack *stack_a, t_stack *stack_b);

#endif

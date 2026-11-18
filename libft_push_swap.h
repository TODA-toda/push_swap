#ifndef LIBFT_PUSH_SWAP_H
# define LIBFT_PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

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
char	**ft_arr_of_strjoin(char const **s1, char const **s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);

#endif
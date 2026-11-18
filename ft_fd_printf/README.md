*This project has been created as part of the 42 curriculum by souait-s.*

# ft_printf

## Description

A re-implementation of the C `printf()` function, built to learn how variadic functions work. It produces `libftprintf.a`, which contains:

```c
int ft_printf(const char *format, ...);
```

Supported conversions: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`. It writes with `write`, returns the number of characters printed (or `-1` on error), and has no buffer management, like the subject asks.

## Instructions

```bash
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and the library
make re       # rebuilds everything
```

Usage:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

## Resources

- `man 3 stdarg`, `man 3 printf`, `man 2 write`
- GeeksforGeeks, "Variadic functions in C"
- The `ft_printf` subject and the 42 Norm

**Use of AI:** AI tools were used as a learning and support resource throughout this project.

They were used to:

- Clarify concepts related to variadic arguments (`va_list`, `va_start`, `va_arg`, and `va_end`).
- Explain C functions, data types, pointers, and format specifiers.
- Help understand the behavior of the standard `printf` function.

All code was written and implemented by me. AI assistance was used to improve my understanding of the concepts rather than to generate the project implementation.

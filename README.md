*This project has been created as part of the 42 curriculum by rrohrer.*

# ft_printf

A custom implementation of the C standard library function `printf()`, built from scratch using variadic functions.

## Description

ft_printf is a project from the 42 common core where the goal is to recode `printf()` from libc. The function takes a format string and a variable number of arguments, parses the format string for conversion specifiers (`%c`, `%s`, `%d`, etc.), and outputs the formatted result to stdout using `write()`.

The function supports the following conversions:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal with `0x` prefix |
| `%d` | Prints a decimal (base 10) number |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal number |
| `%x` | Prints a number in hexadecimal (lowercase) |
| `%X` | Prints a number in hexadecimal (uppercase) |
| `%%` | Prints a literal percent sign |

ft_printf returns the total number of characters printed, just like the real `printf()`.

## Algorithm and architecture

### Main loop and dispatcher

The core of ft_printf is a `while` loop that iterates through the format string character by character. When it encounters a regular character, it writes it directly with `write()`. When it encounters `%`, it reads the next character to determine which conversion to apply.

I chose a **dispatcher pattern** to route each specifier to the right function. The dispatcher is split into three sub-functions (`handle_basic`, `handle_numbers`, `handle_advanced`) mainly to stay within the 25-line norm limit per function. `handle_basic` covers `%c`, `%s`, and `%%`. `handle_numbers` covers `%d` and `%i`. `handle_advanced` covers `%u`, `%x`, `%X`, and `%p`.

### Number-to-string conversion

For `%d` and `%i`, I reuse `ft_itoa` from my libft which handles signed integers including `INT_MIN`. For `%u`, `%x`, `%X`, and `%p`, I wrote dedicated conversion functions (`ft_uitoa`, `ft_uitoa_hex_lower`, `ft_uitoa_hex_upper`, `ft_uitoa_ptr`) because these specifiers work with unsigned types and different bases.

The conversion algorithm is the same for all bases:
1. Calculate the number of digits by dividing repeatedly by the base (10 or 16)
2. Allocate a string of that length + 1 (for `\0`)
3. Fill the string from right to left using `nb % base` to get each digit and `nb / base` to remove it

For hex conversions I use a lookup string `"0123456789abcdef"` (or uppercase) so that `hex_chars[nb % 16]` directly gives the right character. This avoids having to handle the `a-f` range manually.

### Data types

- `%c`: read as `int` from `va_arg` (due to type promotion in variadic functions), then written as a single byte
- `%s`: read as `char *`, with a NULL check that prints `(null)`
- `%d`/`%i`: read as `int`
- `%u`/`%x`/`%X`: read as `unsigned int` (4 bytes)
- `%p`: read as `unsigned long` (8 bytes on 64-bit), cast to `void *` for the function prototype, then cast back to `unsigned long` for arithmetic. The `0x` prefix is written separately before the hex digits. NULL pointers print `(nil)`

### Memory management

Every conversion function that uses `malloc` (through `ft_itoa`, `ft_uitoa`, etc.) follows the same pattern: convert → check for NULL → get length → write → free → return length. No memory leaks.

## Instructions

### Compilation

```bash
make        # Compiles libftprintf.a
make clean  # Removes object files
make fclean # Removes object files and libftprintf.a
make re     # Full recompile
```

### Usage

Include the header and compile with the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old\n", "rrohrer", 22);
    ft_printf("Pointer: %p\n", &main);
    ft_printf("Hex: %x | Unsigned: %u\n", 255, 42);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -o test
./test
```

## Resources

### References

- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) — the manual page I kept open the entire time
- [man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html) — documentation for va_list, va_start, va_arg, va_end
- [man 2 write](https://man7.org/linux/man-pages/man2/write.2.html) — the write system call
- Peer discussions at 42 for debugging and understanding edge cases

### AI usage

I used AI (Claude) to help me with the following parts of the project:

- **This README**: I wrote the content and structure with AI assistance to make sure it covers all the required sections properly.
- **The Makefile**: I got help understanding the `ar rcs` command, the `%.o: %.c` pattern rule, and the approach of copying `libft.a` before adding the ft_printf object files.
- **Understanding concepts**: I used AI to clarify some concepts I was struggling with, specifically how variadic functions work (the type promotion rules, why `va_arg` uses `int` instead of `char`), how hexadecimal conversion works with the modulo/division algorithm, and how pointer addresses are stored as `unsigned long` on 64-bit systems.

The actual code implementation was done by me, using what I learned from these explanations and from working with peers.

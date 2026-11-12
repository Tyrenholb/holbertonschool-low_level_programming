# Pointers, Arrays, and Strings

Three groups of C exercises work with addresses, mutable strings, raw bytes,
and two-dimensional arrays. [`main.h`](main.h) collects the function prototypes.
The functions operate on caller-supplied storage rather than allocating it.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Functions

| Source | Behavior |
| --- | --- |
| [`0-reset_to_98.c`](0-reset_to_98.c) | Writes `98` through an integer pointer |
| [`1-swap.c`](1-swap.c) | Exchanges two pointed-to integers |
| [`2-strlen.c`](2-strlen.c) | Counts bytes before a string terminator |
| [`3-puts.c`](3-puts.c) | Prints a string and newline |
| [`4-print_rev.c`](4-print_rev.c) | Prints a string in reverse without modifying it |
| [`5-rev_string.c`](5-rev_string.c) | Reverses a string in place |
| [`6-puts2.c`](6-puts2.c) | Prints characters at even indices and a newline |
| [`7-puts_half.c`](7-puts_half.c) | Prints from index `(length + 1) / 2` through the end |
| [`8-print_array.c`](8-print_array.c) | Prints integers separated by comma-space |
| [`9-strcpy.c`](9-strcpy.c) | Copies a string including its terminator |
| [`100-atoi.c`](100-atoi.c) | Converts the first digit sequence, tracking preceding minus signs |
| [`0-strcat.c`](0-strcat.c) | Appends a string and terminator |
| [`1-strncat.c`](1-strncat.c) | Appends up to `n` source bytes and a terminator |
| [`2-strncpy.c`](2-strncpy.c) | Copies up to `n` bytes, padding with zero bytes when the source is shorter |
| [`3-strcmp.c`](3-strcmp.c) | Returns the difference of the first unmatched characters |
| [`4-rev_array.c`](4-rev_array.c) | Reverses `n` integers in place |
| [`5-string_toupper.c`](5-string_toupper.c) | Converts lowercase English letters to uppercase in place |
| [`6-cap_string.c`](6-cap_string.c) | Capitalizes the first letter and letters after its listed separators |
| [`7-leet.c`](7-leet.c) | Replaces A/E/O/T/L, in either case, with 4/3/0/7/1 |
| [`0-memset.c`](0-memset.c) | Fills `n` bytes with a constant byte |
| [`1-memcpy.c`](1-memcpy.c) | Copies `n` bytes forward |
| [`2-strchr.c`](2-strchr.c) | Finds the first matching character, including a terminator search |
| [`3-strspn.c`](3-strspn.c) | Counts the initial prefix made entirely of accepted bytes |
| [`4-strpbrk.c`](4-strpbrk.c) | Finds the first byte belonging to an accepted set |
| [`5-strstr.c`](5-strstr.c) | Finds the first matching substring; an empty needle returns the haystack |
| [`7-print_chessboard.c`](7-print_chessboard.c) | Prints an 8-by-8 character array |
| [`8-print_diagsums.c`](8-print_diagsums.c) | Prints both diagonal sums of a contiguous square integer matrix |

[`_putchar.c`](_putchar.c) provides byte output for the character-printing helpers.

## Build

No source defines `main`. From the repository root, check the numbered exercises:

```bash
cd pointers_arrays_strings
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only [0-9]*.c
```

The local `_putchar.c` calls `write` without including `<unistd.h>` and fails
strict compilation on its own. To explore functions that need it without
changing the source, an explicit build workaround is:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -include unistd.h -fsyntax-only _putchar.c
```

For a runnable program, link a caller with only the implementations it needs.
The example below does not depend on `_putchar`.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c main.h
betty-doc *.c main.h
```

The current files pass the installed Betty checkers locally. That does not
resolve the helper's missing system-header declaration.

## Usage

Save this caller as `main.c`:

```c
#include "main.h"

int main(void)
{
    int values[] = {1, 2, 3};

    reverse_array(values, 3);
    print_array(values, 3);
    return (0);
}
```

Build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c 4-rev_array.c 8-print_array.c -o reverse_example
./reverse_example
```

Output:

```text
3, 2, 1
```

## Buffer and input limits

- Provide valid pointers and bounds. Mutating functions require writable
  arrays; string literals must not be passed for modification.
- Copying and concatenation do not check destination capacity. `_strncpy` does
  not add a terminator when the source has at least `n` bytes.
- Byte-copying is a forward loop, not `memmove`; use non-overlapping regions.
- Search functions return borrowed pointers into the input or a null pointer.
  Do not free a returned interior pointer.
- `cap_string` starts examining index `1` even when the input is empty; avoid
  empty strings with this current implementation.
- `_atoi` and diagonal sums do not provide complete range/overflow checks.
  Character transformations assume the target's ASCII-compatible encoding.

## Clean up

```bash
rm -f reverse_example
```

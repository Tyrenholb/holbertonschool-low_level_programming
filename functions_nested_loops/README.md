# Functions and Nested Loops

Introductory C exercises covering reusable functions, character tests, integer
operations, and nested loops for formatted output. [`main.h`](main.h) declares
the public functions and the externally supplied `_putchar` helper.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Programs and functions

| Source | Behavior |
| --- | --- |
| [`0-putchar.c`](0-putchar.c) | Standalone `main` that prints `_putchar` and a newline |
| [`1-alphabet.c`](1-alphabet.c) | `print_alphabet`: prints lowercase letters and a newline |
| [`2-print_alphabet_x10.c`](2-print_alphabet_x10.c) | Prints the lowercase alphabet ten times |
| [`3-islower.c`](3-islower.c) | Returns `1` for `a`–`z`, otherwise `0` |
| [`4-isalpha.c`](4-isalpha.c) | Returns `1` for an uppercase or lowercase English letter |
| [`5-sign.c`](5-sign.c) | Prints `+`, `0`, or `-` and returns `1`, `0`, or `-1` |
| [`6-abs.c`](6-abs.c) | Returns the absolute value of an integer |
| [`7-print_last_digit.c`](7-print_last_digit.c) | Prints and returns the non-negative last decimal digit |
| [`8-24_hours.c`](8-24_hours.c) | Prints every minute from `00:00` through `23:59` |
| [`9-times_table.c`](9-times_table.c) | Prints products for rows and columns `0` through `9` |
| [`10-add.c`](10-add.c) | Returns the sum of two integers |
| [`11-print_to_98.c`](11-print_to_98.c) | Prints integers from the starting value to `98`, ascending or descending |

## Build

From the repository root:

```bash
cd functions_nested_loops
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only *.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-putchar.c ../function_pointers/_putchar.c -o putchar_example
```

This directory declares but does not implement `_putchar`. The runnable build
uses the existing [helper in `function_pointers`](../function_pointers/_putchar.c).
`0-putchar.c` contains `main`; the other exercises require a caller and must
not be linked with a second `main`.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c main.h
betty-doc *.c main.h
```

The current sources and header pass both installed checkers locally.

## Usage

```console
$ ./putchar_example
_putchar
```

To run a reusable function, save a caller such as this as `main.c`:

```c
#include "main.h"

int main(void)
{
    print_to_98(95);
    return (0);
}
```

Build and run only the needed implementation:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c 11-print_to_98.c -o to_98_example
./to_98_example
```

Output:

```text
95, 96, 97, 98
```

## Behavior and limits

- Character checks use explicit English-letter ranges, not locale-aware rules.
- `print_sign` and `print_last_digit` do not append a newline themselves.
- `_abs` cannot represent the absolute value of `INT_MIN`; `add` does not check
  for integer overflow. Use inputs whose results fit in an `int`.
- The time and multiplication-table exercises print generated data; they do
  not read the system clock or accept user input.

## Clean up

Remove executables created by the examples:

```bash
rm -f putchar_example to_98_example
```

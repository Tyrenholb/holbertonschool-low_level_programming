# More Functions and Nested Loops

C exercises combining character tests, arithmetic, repeated number printing,
and text shapes. A separate FizzBuzz program demonstrates ordered divisibility
checks.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Programs and functions

| Source | Behavior |
| --- | --- |
| [`0-isupper.c`](0-isupper.c) | Returns `1` for `A`–`Z`, otherwise `0` |
| [`1-isdigit.c`](1-isdigit.c) | Returns `1` for `0`–`9`, otherwise `0` |
| [`2-mul.c`](2-mul.c) | Returns the product of two integers |
| [`3-print_numbers.c`](3-print_numbers.c) | Prints `0123456789` and a newline |
| [`4-print_most_numbers.c`](4-print_most_numbers.c) | Prints the same range without `2` and `4` |
| [`5-more_numbers.c`](5-more_numbers.c) | Prints concatenated numbers `0` through `14`, ten lines total |
| [`6-print_line.c`](6-print_line.c) | Prints `n` underscores and a newline |
| [`7-print_diagonal.c`](7-print_diagonal.c) | Prints a backslash on each line with increasing leading spaces |
| [`8-print_square.c`](8-print_square.c) | Prints a square of `#` characters |
| [`9-fizz_buzz.c`](9-fizz_buzz.c) | Standalone program printing FizzBuzz for `1` through `100` |
| [`10-print_triangle.c`](10-print_triangle.c) | Prints a right-aligned triangle of `#` characters |

[`main.h`](main.h) declares the reusable functions and `_putchar`.

## Build

From the repository root:

```bash
cd more_functions_nested_loops
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only *.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 9-fizz_buzz.c -o fizzbuzz_example
```

Only `9-fizz_buzz.c` defines `main`. The other functions need a caller. Their
printing routines also need an implementation of `_putchar`, which is declared
but not defined here. The existing
[helper in `function_pointers`](../function_pointers/_putchar.c) can be linked
for local examples.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c main.h
betty-doc *.c main.h
```

The current sources and header pass both installed checkers locally.

## Usage

```bash
./fizzbuzz_example
```

It prints one space-separated line. Multiples of three become `Fizz`, multiples
of five become `Buzz`, and multiples of both become `FizzBuzz`.

To try a shape function, save this caller as `main.c`:

```c
#include "main.h"

int main(void)
{
    print_square(3);
    return (0);
}
```

Build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c 8-print_square.c ../function_pointers/_putchar.c -o square_example
./square_example
```

Output:

```text
###
###
###
```

## Behavior and limits

- Line, diagonal, square, and triangle functions print a single newline for
  non-positive dimensions.
- Character tests use explicit character ranges, not locale-aware rules.
- `mul` does not check overflow; use inputs whose product fits in an `int`.
- None of the functions reads terminal input. Callers supply sizes and values.

## Clean up

```bash
rm -f fizzbuzz_example square_example
```

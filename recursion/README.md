# Recursion

Seven C exercises express string traversal and integer calculations through
recursive calls. Each function reduces its input toward a base case rather
than using a loop. [`main.h`](main.h) declares the public functions and helpers.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Functions

| Source | Behavior and base cases |
| --- | --- |
| [`0-puts_recursion.c`](0-puts_recursion.c) | Prints a string; the terminator triggers a newline and return |
| [`1-print_rev_recursion.c`](1-print_rev_recursion.c) | Reaches the terminator first, then prints characters as calls return; adds no newline |
| [`2-strlen_recursion.c`](2-strlen_recursion.c) | Returns `0` at the terminator, otherwise one plus the suffix length |
| [`3-factorial.c`](3-factorial.c) | Returns `n!`; `0` returns `1`, negative input returns `-1` |
| [`4-pow_recursion.c`](4-pow_recursion.c) | Returns `x` raised to `y`; exponent zero returns `1`, negative exponent returns `-1` |
| [`5-sqrt_recursion.c`](5-sqrt_recursion.c) | Tries successive integer roots; returns the exact non-negative root or `-1` |
| [`6-is_prime_number.c`](6-is_prime_number.c) | Tries divisors from `2`; returns `1` for prime inputs, otherwise `0` |

[`_putchar.c`](_putchar.c) supplies character output for the string printers.
The square-root and primality implementations use `sqrt_helper` and
`prime_helper` respectively.

## Build

These sources do not define `main`. From the repository root:

```bash
cd recursion
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only *.c
```

Link a caller with the required source files. Character-printing callers must
also link `_putchar.c`.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c main.h
betty-doc *.c main.h
```

The installed documentation checker passes locally. The style checker reports
missing final newlines in `_putchar.c` and `main.h`.

## Usage

Save this caller as `main.c`:

```c
#include "main.h"
#include <stdio.h>

int main(void)
{
    printf("%d\n", factorial(5));
    printf("%d\n", _pow_recursion(2, 4));
    printf("%d\n", _sqrt_recursion(81));
    printf("%d\n", is_prime_number(17));
    return (0);
}
```

Build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c 3-factorial.c 4-pow_recursion.c 5-sqrt_recursion.c 6-is_prime_number.c -o recursion_example
./recursion_example
```

Output:

```text
120
16
9
1
```

## Input limits

- String functions require valid null-terminated strings; they do not check
  for null pointers.
- Every recursive call consumes stack space. Long strings, large exponents,
  and large search ranges can exhaust the stack.
- Arithmetic uses `int` without overflow protection. This includes factorial,
  powers, and the squared guesses/divisors in the search helpers. Use small
  inputs whose intermediate values fit in an `int`.
- `_pow_recursion(0, 0)` returns `1` because exponent zero is its base case.

## Clean up

```bash
rm -f recursion_example
```

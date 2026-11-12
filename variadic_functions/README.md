# Variadic Functions

Four C functions use `<stdarg.h>` to process variable-length argument lists.
The caller supplies a count or a format string; each function uses `va_start`,
`va_arg`, and `va_end` to traverse the supplied values.
[`variadic_functions.h`](variadic_functions.h) declares the interfaces.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Functions

| Source | Behavior |
| --- | --- |
| [`0-sum_them_all.c`](0-sum_them_all.c) | Adds `n` integer arguments; returns `0` when `n` is zero |
| [`1-print_numbers.c`](1-print_numbers.c) | Prints `n` integers with the supplied separator between them |
| [`2-print_strings.c`](2-print_strings.c) | Prints `n` strings with a separator; null strings become `(nil)` |
| [`3-print_all.c`](3-print_all.c) | Uses `c`, `i`, `f`, and `s` format characters to print mixed argument types |

All three printing functions end with a newline. A null separator suppresses
separators for `print_numbers` and `print_strings`.

## Build

These files have no `main`. From the repository root, check compilation without
generating object files:

```bash
cd variadic_functions
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only *.c
```

Link the functions with a caller to run them.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c variadic_functions.h
betty-doc *.c variadic_functions.h
```

The current sources and header pass both installed checkers locally.

## Usage

Save this caller as `main.c`:

```c
#include "variadic_functions.h"
#include <stdio.h>

int main(void)
{
    printf("%d\n", sum_them_all(3, 10, 20, 30));
    print_numbers(", ", 3, 1, 2, 3);
    print_strings(" / ", 3, "C", (char *)0, "Betty");
    print_all("cifs", 'A', 42, 3.5, "hello");
    return (0);
}
```

Build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c [0-3]-*.c -o variadic_example
./variadic_example
```

Output:

```text
60
1, 2, 3
C / (nil) / Betty
A, 42, 3.500000, hello
```

## Format and input limits

| `print_all` character | Expected variadic type | Output |
| --- | --- | --- |
| `c` | `int` after character promotion | Character |
| `i` | `int` | Decimal integer |
| `f` | `double`, including promoted `float` | Floating-point value with `%f` |
| `s` | `char *` | String, or `(nil)` for a null pointer |

- `print_all` separates recognized values with comma-space. Unknown format
  characters are ignored without consuming an argument; it does not use
  `printf`-style percent directives. A null or empty format prints only a newline.
- Counts and format characters must match the types and number of arguments.
  The compiler cannot fully validate these custom variadic calls; mismatches
  can cause undefined behavior.
- Pass a typed null string pointer, such as `(char *)0`, rather than an integer
  zero through the variadic interface.
- Non-null strings must be terminated and remain valid during the call.
  `sum_them_all` uses `int` and does not check overflow.

## Clean up

```bash
rm -f variadic_example
```

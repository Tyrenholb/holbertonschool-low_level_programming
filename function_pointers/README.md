# Function Pointers

C exercises passing functions as callbacks and selecting arithmetic operations
from a table of function pointers. The directory contains three reusable
callback functions and a standalone command-line calculator.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Files

| Source | Purpose |
| --- | --- |
| [`0-print_name.c`](0-print_name.c) | Calls a supplied name-printing function when both the name and callback are non-null |
| [`1-array_iterator.c`](1-array_iterator.c) | Calls an action once for each integer in an array |
| [`2-int_index.c`](2-int_index.c) | Returns the first index whose comparison callback returns nonzero, or `-1` for no match or invalid input |
| [`3-main.c`](3-main.c) | Validates calculator arguments and invokes the selected operation |
| [`3-get_op_func.c`](3-get_op_func.c) | Maps `+`, `-`, `*`, `/`, and `%` to functions using an `op_t` table |
| [`3-op_functions.c`](3-op_functions.c) | Implements the five integer operations |
| [`_putchar.c`](_putchar.c) | Character-output helper |

[`function_pointers.h`](function_pointers.h) declares the callback helpers.
[`3-calc.h`](3-calc.h) defines the operation-table type and calculator API.

## Build

From the repository root:

```bash
cd function_pointers
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only [0-2]-*.c _putchar.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-get_op_func.c 3-op_functions.c -o calculator_example
```

The callback exercises need a separate caller containing `main`. The calculator
is built under a new name to preserve the existing `calc` executable.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c *.h
betty-doc *.c *.h
```

The current C sources and headers pass both installed Betty checkers locally.

## Usage

Run the calculator with two integers separated by an operator:

```console
$ ./calculator_example 12 + 5
17
$ ./calculator_example 12 '*' 5
60
$ ./calculator_example 12 / 5
2
$ ./calculator_example 12 % 5
2
```

Quote `*` so the shell passes the operator instead of expanding filenames.
Division uses integer arithmetic.

| Exit status | Condition |
| --- | --- |
| `0` | Successful operation |
| `98` | Argument count is not three after the program name |
| `99` | Operator is not one of the five supported single-character strings |
| `100` | Division or remainder with a zero second operand |

All calculator error cases above print `Error` to standard output.

## Callback and input limits

- `array_iterator` does not validate the array or action pointer. Provide valid
  pointers and a size within the array bounds.
- `int_index` returns `-1` for a null array/callback or non-positive size.
- Calculator numbers are converted with `atoi` without numeric or range
  validation. Arithmetic overflow is not checked. Use small representable
  integers; do not treat this calculator as a robust input parser.
- `op_div` and `op_mod` themselves do not check for zero; the command-line
  caller performs that check before invoking them.

## Clean up

```bash
rm -f calculator_example
```

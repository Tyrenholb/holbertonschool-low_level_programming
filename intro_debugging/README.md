# Introduction to Debugging

Three small C programs practice following loops, checking loop bounds, and
tracking accumulated values. Each source includes a fixed demonstration `main`
below a comment marking code that should not be modified for the exercise.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Programs

| Source | Functions | Demonstration result |
| --- | --- | --- |
| [`sum_to_n.c`](sum_to_n.c) | `sum_to_n` adds integers from `1` through `n` | `sum_to_n(10)` prints `55` |
| [`multiplication_table.c`](multiplication_table.c) | `print_table` prints products for rows and columns `1` through `size` | A 4-by-4 multiplication table |
| [`row_sums.c`](row_sums.c) | `row_sum` adds products across one row; `total_sum` accumulates rows | `total_sum(3, 3)` prints `36` |

## Build

Each source contains `main`, so compile the programs separately. From the
repository root:

```bash
cd intro_debugging
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 sum_to_n.c -o sum_example
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 multiplication_table.c -o table_example
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 row_sums.c -o rows_example
```

The current sources compile with these flags locally. For interactive GDB
stepping, add `-g -O0` to the relevant build command and open its executable
with `gdb`.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c
betty-doc *.c
```

The current files do not pass Betty: local checks report formatting issues
and missing function documentation. Compiling successfully does not imply
compliance with the style and documentation requirements.

## Usage

```console
$ ./sum_example
55
$ ./table_example
1 2 3 4
2 4 6 8
3 6 9 12
4 8 12 16
$ ./rows_example
36
```

The table program prints a space after the last number on each row as well.
These programs take no input; the demonstration values are fixed in `main`.

## Debugging focus

- Check inclusive loop bounds: `sum_to_n` must include `n`, and table indices
  start at `1`.
- Follow both nested-loop counters in `print_table`; the column counter is
  reset for each new row.
- Inspect `current` and `total` in `total_sum`. For the 3-by-3 example, row
  sums are `6`, `12`, and `18`, giving `36`.
- The helpers use `int` without overflow checks. Non-positive loop bounds
  produce no iterations in the corresponding loop; these are arithmetic
  exercises rather than validated input-processing APIs.

## Clean up

Remove only the executables created above:

```bash
rm -f sum_example table_example rows_example
```

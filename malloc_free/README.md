# Dynamic Allocation: `malloc` and `free`

Five C functions practice allocating arrays, copying and concatenating strings,
and creating a zero-initialized two-dimensional integer grid. The caller owns
successful allocations and must release them when finished.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Functions

| Source | Behavior | Failure behavior |
| --- | --- | --- |
| [`0-create_array.c`](0-create_array.c) | Allocates `size` characters filled with `c` | Returns `NULL` for size zero or allocation failure |
| [`1-strdup.c`](1-strdup.c) | `_strdup` copies a string including its null terminator | Returns `NULL` for a null input or allocation failure |
| [`2-str_concat.c`](2-str_concat.c) | Allocates a joined string; treats null inputs as empty strings | Returns `NULL` on allocation failure |
| [`3-alloc_grid.c`](3-alloc_grid.c) | Allocates `height` separate rows of `width` integers, initialized to zero | Returns `NULL` for non-positive dimensions or allocation failure; frees partial allocations |
| [`4-free_grid.c`](4-free_grid.c) | Frees each row and the row-pointer array | Accepts `NULL` as a no-op |

[`main.h`](main.h) declares all five functions.

## Build

These exercises do not include `main`. From the repository root, check them
without creating object files:

```bash
cd malloc_free
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only *.c
```

Link the required sources with your own caller to run them.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c main.h
betty-doc *.c main.h
```

The current sources and header pass both installed checkers locally.

## Usage

Save this caller as `main.c` in this directory:

```c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *joined;

    joined = str_concat("Hello, ", "memory!");
    if (joined == NULL)
        return (1);
    puts(joined);
    free(joined);
    return (0);
}
```

Build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c 2-str_concat.c -o concat_example
./concat_example
```

Output:

```text
Hello, memory!
```

For grids, use `alloc_grid(width, height)`, index cells as `grid[row][column]`,
and call `free_grid(grid, height)` with the same height.

## Ownership and limits

- `create_array` allocates exactly `size` bytes and does not append a string
  terminator. Do not print its result with `%s` unless you provide termination.
- `_strdup` and `str_concat` return independent, null-terminated copies that
  should each be released with `free`.
- Grid rows are separate allocations, not one contiguous matrix. Use
  `free_grid` rather than freeing only the outer pointer.
- Provide valid null-terminated strings and dimensions small enough for
  allocation-size and index arithmetic; these implementations do not perform
  complete overflow checks.

## Clean up

```bash
rm -f concat_example
```

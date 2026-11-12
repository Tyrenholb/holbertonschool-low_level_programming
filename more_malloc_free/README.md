# More Dynamic Allocation

Four C helpers practice allocation failure handling, bounded string
concatenation, zero-filled memory, and building inclusive integer ranges.
[`main.h`](main.h) declares their interfaces.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Functions

| Source | Behavior | Failure behavior |
| --- | --- | --- |
| [`0-malloc_checked.c`](0-malloc_checked.c) | Allocates `b` bytes with `malloc` | Terminates the process with status `98` if allocation returns `NULL` |
| [`1-string_nconcat.c`](1-string_nconcat.c) | Copies all of `s1` and at most `n` bytes of `s2` into a terminated string | Returns `NULL` on allocation failure; treats null inputs as empty strings |
| [`2-calloc.c`](2-calloc.c) | `_calloc` allocates `nmemb * size` bytes and explicitly clears them | Returns `NULL` for zero dimensions or allocation failure |
| [`3-array_range.c`](3-array_range.c) | Allocates integers from `min` through `max`, inclusive | Returns `NULL` if `min > max` or allocation fails |

## Build

These sources have no `main`. From the repository root, check compilation
without producing object files:

```bash
cd more_malloc_free
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only *.c
```

Link the required implementation with your own caller to run it.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c main.h
betty-doc *.c main.h
```

The current sources and header pass both installed checkers locally.

## Usage

Save this caller as `main.c`:

```c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *values;
    int i;

    values = array_range(3, 5);
    if (values == NULL)
        return (1);
    for (i = 0; i < 3; i++)
        printf("%d\n", values[i]);
    free(values);
    return (0);
}
```

Build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c 3-array_range.c -o range_example
./range_example
```

Output:

```text
3
4
5
```

## Ownership and limits

- Free every successful allocation with `free` when finished.
- `malloc_checked` returns uninitialized memory. A zero-byte request follows
  the platform's `malloc(0)` behavior and may lead to exit status `98`.
- `string_nconcat` counts bytes, not Unicode characters, and requires valid
  null-terminated strings for non-null inputs.
- `_calloc` does not check multiplication overflow. `array_range` does not
  check overflow in `max - min + 1`. String allocation arithmetic is also
  unchecked. Keep sizes and ranges small enough for the implementation's
  integer types and available memory.

## Clean up

```bash
rm -f range_example
```

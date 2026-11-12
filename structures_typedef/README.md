# Structures and `typedef`

C exercises grouping related fields in `struct dog`, then introducing `dog_t`
as a type alias. The functions contrast initializing an existing structure
with allocating a structure that owns copies of its strings.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Types and functions

[`dog.h`](dog.h) defines `struct dog` with `char *name`, `float age`, and
`char *owner`, plus the equivalent alias `dog_t`.

| Source | Behavior |
| --- | --- |
| [`1-init_dog.c`](1-init_dog.c) | Assigns fields in an existing structure without copying strings; a null structure is ignored |
| [`2-print_dog.c`](2-print_dog.c) | Prints name, age, and owner; null strings are shown as `(nil)` and a null structure is ignored |
| [`4-new_dog.c`](4-new_dog.c) | Allocates a structure and separate copies of name/owner; returns `NULL` and cleans up on allocation failure |
| [`5-free_dog.c`](5-free_dog.c) | Frees both string fields and the structure; accepts `NULL` |

## Build

There is no `main` in this directory. From the repository root, check the
implementations without generating object files:

```bash
cd structures_typedef
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only *.c
```

Link the required sources with a caller to run them.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c dog.h
betty-doc *.c dog.h
```

The current sources and header pass both installed checkers locally.

## Usage

Save this caller as `main.c`:

```c
#include "dog.h"
#include <stddef.h>

int main(void)
{
    dog_t *dog;

    dog = new_dog("Poppy", 3.5, "Sam");
    if (dog == NULL)
        return (1);
    print_dog(dog);
    free_dog(dog);
    return (0);
}
```

Build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c 2-print_dog.c 4-new_dog.c 5-free_dog.c -o dog_example
./dog_example
```

Output:

```text
Name: Poppy
Age: 3.500000
Owner: Sam
```

## Ownership and limits

- `init_dog` borrows the name and owner pointers. Keep those strings alive
  while the initialized structure uses them.
- `new_dog` requires non-null, terminated name and owner strings. It copies
  both, so the original inputs do not need to outlive the returned object.
- Use `free_dog` for objects returned by `new_dog`. Do not use it for a stack
  structure initialized with borrowed strings: it frees every field and the
  structure itself.
- Age values are stored directly without validation. String lengths use
  `int` and are not checked for overflow.

## Clean up

```bash
rm -f dog_example
```

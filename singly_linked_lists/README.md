# Singly Linked Lists

Five C functions build and traverse a string list. Each `list_t` node owns a
copied string, stores its length, and points to the next node.
[`lists.h`](lists.h) defines the node structure and function prototypes.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Functions

| Source | Behavior | Return value |
| --- | --- | --- |
| [`0-print_list.c`](0-print_list.c) | Prints each node as `[length] string`, or `[0] (nil)` for a null string | Number of nodes printed |
| [`1-list_len.c`](1-list_len.c) | Traverses the list | Number of nodes |
| [`2-add_node.c`](2-add_node.c) | Allocates a node, duplicates its string, and prepends it | New node, or `NULL` on allocation failure |
| [`3-add_node_end.c`](3-add_node_end.c) | Allocates a node, duplicates its string, and appends it | New node, or `NULL` on allocation failure |
| [`4-free_list.c`](4-free_list.c) | Frees each copied string and node | Nothing |

## Build

These files have no `main`. From the repository root, check compilation
without generating object files:

```bash
cd singly_linked_lists
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only *.c
```

The add functions use `strdup`, available in the target GNU/POSIX environment.
Link the functions with a caller to run them.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c lists.h
betty-doc *.c lists.h
```

The current sources and header pass both installed checkers locally.

## Usage

Save this caller as `main.c`:

```c
#include "lists.h"

int main(void)
{
    list_t *head = NULL;

    if (add_node(&head, "Hello") == NULL)
        return (1);
    if (add_node_end(&head, "Betty") == NULL)
    {
        free_list(head);
        return (1);
    }
    print_list(head);
    free_list(head);
    head = NULL;
    return (0);
}
```

Build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c [0-4]-*.c -o list_example
./list_example
```

Output:

```text
[5] Hello
[5] Betty
```

## Ownership and limits

- Represent an empty list with a head variable containing `NULL`. Counting
  or printing an empty list returns `0`; freeing it is a no-op.
- Add functions require a valid pointer to the head variable and a non-null,
  terminated string. They do not validate those inputs.
- Each successful add makes an independent string copy. Releasing the list
  frees those copies, not the caller's original strings.
- `free_list` cannot reset the caller's head variable. Set it to `NULL` before
  reuse; pointers to freed nodes or their strings become invalid.
- Traversals assume an acyclic list with valid links. Prepending is constant
  time; appending scans to the tail.

## Clean up

```bash
rm -f list_example
```

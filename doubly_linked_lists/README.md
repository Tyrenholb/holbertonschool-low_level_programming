# Doubly Linked Lists

Nine C functions implement an integer list with links in both directions.
Each `dlistint_t` node stores an integer `n`, a `prev` pointer, and a `next`
pointer. [`lists.h`](lists.h) defines the node type and public functions.

## Functions

| Source | Behavior | Return value |
| --- | --- | --- |
| [`0-print_dlistint.c`](0-print_dlistint.c) | Prints each integer on its own line | Number of nodes printed |
| [`1-dlistint_len.c`](1-dlistint_len.c) | Counts nodes | List length |
| [`2-add_dnodeint.c`](2-add_dnodeint.c) | Allocates and prepends a node | New node, or `NULL` on allocation failure |
| [`3-add_dnodeint_end.c`](3-add_dnodeint_end.c) | Allocates and appends a node | New node, or `NULL` on allocation failure |
| [`4-free_dlistint.c`](4-free_dlistint.c) | Releases every node | Nothing |
| [`5-get_dnodeint.c`](5-get_dnodeint.c) | Finds a node by zero-based index | Node, or `NULL` when out of range |
| [`6-sum_dlistint.c`](6-sum_dlistint.c) | Adds the stored integers | Sum, or `0` for an empty list |
| [`7-insert_dnodeint.c`](7-insert_dnodeint.c) | Inserts at a zero-based index, including immediately after the last node | New node, or `NULL` on failure |
| [`8-delete_dnodeint.c`](8-delete_dnodeint.c) | Unlinks and frees an indexed node | `1` on success, `-1` on failure |

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Build

These functions form a library of exercises rather than a standalone program.
From the repository root, check compilation without adding object files to the
working tree:

```bash
cd doubly_linked_lists
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only [0-8]-*.c
```

Link the numbered sources with a caller containing `main` to run them. The
included [`test_size.c`](test_size.c) is only a small `size_t` experiment; it
does not exercise the list functions.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style [0-8]-*.c lists.h
betty-doc [0-8]-*.c lists.h
```

The separate `test_size.c` experiment uses a one-line function and has no
function documentation; it is not a Betty-compliant example.

## Usage

A caller includes `lists.h` and owns the head pointer. For example:

```c
#include "lists.h"

int main(void)
{
    dlistint_t *head = NULL;

    if (add_dnodeint(&head, 10) == NULL)
        return (1);
    if (add_dnodeint_end(&head, 20) == NULL)
    {
        free_dlistint(head);
        return (1);
    }
    print_dlistint(head);
    free_dlistint(head);
    head = NULL;
    return (0);
}
```

Save this example as `main.c` in this directory, then build and run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c [0-8]-*.c -o list_example
./list_example
```

Output:

```text
10
20
```

## Ownership and limits

- Pass the address of a valid head variable to the prepend and append
  functions; they do not check for a `NULL` outer pointer. An empty list is
  represented by a head variable containing `NULL`.
- Insertion and deletion update both neighboring links and may change the
  head. An insertion index may equal the list length; a deletion index must
  identify an existing node.
- `free_dlistint` releases nodes but cannot clear the caller's head variable.
  Set it to `NULL` before reusing it. Pointers to deleted nodes become dangling.
- Traversal assumes a valid, acyclic list. The sum uses `int` without overflow
  checks.

## Clean up

If you created the example above, remove its executable when finished:

```bash
rm -f list_example
```

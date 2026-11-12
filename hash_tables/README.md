# Hash Tables

A string-to-string hash table in C using djb2 hashing and separate chaining.
Each array bucket holds a linked list of `hash_node_t` nodes. Keys and values
are copied into owned allocations; setting an existing key replaces its value.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Functions and examples

| Source | Function and result |
| --- | --- |
| [`0-hash_table_create.c`](0-hash_table_create.c) | Allocates a table with a nonzero bucket count; returns `NULL` on failure |
| [`1-djb2.c`](1-djb2.c) | Computes an unsigned long djb2 hash |
| [`2-key_index.c`](2-key_index.c) | Maps a hash to a bucket with modulo |
| [`3-hash_table_set.c`](3-hash_table_set.c) | Inserts or updates a pair; returns `1` on success, `0` on failure |
| [`4-hash_table_get.c`](4-hash_table_get.c) | Returns the stored value or `NULL` when absent/invalid |
| [`5-hash_table_print.c`](5-hash_table_print.c) | Prints pairs in bucket and chain order |
| [`6-hash_table_delete.c`](6-hash_table_delete.c) | Frees copied strings, nodes, buckets, and the table |

[`hash_tables.h`](hash_tables.h) defines the types and prototypes.
The seven `0-main.c` through `6-main.c` files are separate demonstration
programs for creation, hashing, indexing, insertion, lookup, printing, and
cleanup. They must not all be linked into one executable.

## Build

From the repository root, build the cleanup demonstration:

```bash
cd hash_tables
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 6-main.c *hash_table*.c 1-djb2.c 2-key_index.c -o hash_example
```

The source glob selects the implementation files, not the demonstration mains.
Replace `6-main.c` with another numbered main to run that example separately.
The implementation uses `strdup`, available in the target GNU/POSIX environment.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c hash_tables.h
betty-doc *.c hash_tables.h
```

The installed documentation checker passes locally. The full style check
reports issues in the supplied demonstration mains, including space indentation.

## Usage

```bash
./hash_example
```

The cleanup demonstration inserts several keys, replaces values for `98` and
`hetairas`, prints the table, and releases it. Its output includes entries such
as `'98': 'Battery Street'` and `'hetairas': 'Bob Z Chu'`.
Output order follows bucket indices and collision chains, not insertion order
or alphabetical order.

## Ownership and limits

- Use a nonzero table size. `key_index` does not guard against division by
  zero and requires a valid null-terminated key.
- Set/get reject null or empty keys; set also rejects a null value. Empty
  value strings are allowed.
- `hash_table_get` returns a borrowed pointer. Do not free it; updating that
  key or deleting the table invalidates it.
- `hash_table_delete` does not clear the caller's table pointer. Do not reuse
  it after deletion without assigning a new valid value.
- Some earlier demonstration mains omit cleanup. `4-main.c` also passes a
  missing key's null result to `%s`, which is not portable C. Use the cleanup
  example above as the runnable entry point, and check lookup results before
  printing them in your own caller.
- There is no automatic resizing; long collision chains increase lookup cost.

## Clean up

```bash
rm -f hash_example
```

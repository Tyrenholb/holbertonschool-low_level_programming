# C - Hash Tables

A basic hash table implementation written in C.

This project covers creating a hash table, hashing keys with djb2, handling collisions with linked lists, retrieving values, and freeing allocated memory.

## Functions

* `hash_table_create` - creates an empty hash table
* `hash_djb2` - generates a hash from a string
* `key_index` - converts a hash into an array index
* `hash_table_set` - adds or updates a key/value pair
* `hash_table_get` - retrieves a value by its key
* `hash_table_print` - prints the table
* `hash_table_delete` - frees the table and its nodes

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

# Session Storage and Ownership

A command-driven C program stores sessions in a linked list. Each session owns
an identifier string and a byte buffer. The exercise explores copying input,
transferring ownership, updating allocations, and releasing sessions on deletion
or shutdown.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Files

| File | Purpose |
| --- | --- |
| [`main.c`](main.c) | Parses commands from standard input and prints responses |
| [`session.h`](session.h) | Defines `session_t` and its allocation/update/destruction API |
| [`session.c`](session.c) | Copies identifiers and data, updates buffers with `realloc`, and frees sessions |
| [`store.h`](store.h) | Defines linked-list nodes, the store, and store operations |
| [`store.c`](store.c) | Adds, retrieves, removes, and destroys stored sessions |
| [`Makefile`](Makefile) | Builds `secure_store` with the required flags and debug symbols |

## Build

GNU Make is required in addition to GCC. From the repository root:

```bash
cd secure_data_handling
make
```

The Makefile uses `-std=gnu89 -Wall -Wextra -Werror -pedantic -g`.
The `-g` option adds debug symbols. `make re` cleans and rebuilds.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c *.h
betty-doc *.c *.h
```

The current sources compile locally, but do not pass Betty. Reports include
brace/return formatting, long functions, and missing function/type documentation.

## Commands

Commands are case-sensitive and read one per line. IDs are space-delimited;
ADD and SET consume the remaining text as data.

| Command | Behavior | Response |
| --- | --- | --- |
| `ADD <id> <uid> <data>` | Creates a session unless that ID already exists | `OK` or `NO` |
| `GET <id>` | Finds a session without exposing its data bytes | `FOUND <id> <uid> <data_len>` or `NOTFOUND` |
| `SET <id> <data>` | Replaces an existing session's data | `OK` or `NO` |
| `DEL <id>` | Removes and destroys the session | `OK` or `NO` |
| `CLEAR` | Destroys all sessions and reinitializes the store | `OK` |
| `EXIT` | Leaves the command loop and destroys remaining sessions | No response |

Unknown commands print `NO`. Empty lines are ignored. Command failures are
reported in the response text; `main` returns `0` on normal completion.

## Usage

From this directory after building:

```bash
./secure_store <<'EOF'
ADD alpha 42 hello
GET alpha
SET alpha goodbye
GET alpha
DEL alpha
GET alpha
EXIT
EOF
```

Output:

```text
OK
FOUND alpha 42 5
OK
FOUND alpha 42 7
OK
NOTFOUND
```

## Ownership and limits

- `session_create` copies the ID and data, so they outlive reuse of the input
  line. The data buffer is length-delimited and need not be null-terminated.
- `store_add` takes ownership of a non-null session: on success it stores it;
  on failure it destroys it. Do not destroy the session again after calling it.
- `store_get` returns a borrowed session pointer. Deletion, clearing, or store
  destruction invalidates that pointer.
- `store_delete(st, id, &out)` transfers the removed session to the caller,
  who must destroy it. Passing `NULL` for `out`, as the CLI does, destroys it
  immediately.
- The CLI reads into a 512-byte line buffer, uses space-based tokenization,
  and does not validate UID range or full numeric conversion with `strtoul`.
  Long lines may be processed as multiple input fragments.
- This lab does not implement persistence, authentication, encryption, or
  guaranteed erasure of sensitive bytes before releasing memory.

## Clean up

```bash
make clean
```

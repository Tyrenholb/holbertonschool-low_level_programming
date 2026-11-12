# File Input and Output

C exercises using POSIX file descriptors and `open`, `read`, `write`, and
`close`. Three reusable functions handle text files; a standalone copy program
moves file contents in 1,024-byte chunks.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Programs and functions

| Source | Behavior | Return value |
| --- | --- | --- |
| [`0-read_textfile.c`](0-read_textfile.c) | Reads up to `letters` bytes and writes them to standard output | Bytes written, or `0` on failure |
| [`1-create_file.c`](1-create_file.c) | Creates or truncates a file, then writes the supplied text; requests mode `0600` for a new file | `1` on success, `-1` on failure |
| [`2-append_text_to_file.c`](2-append_text_to_file.c) | Appends text to an existing file without creating it | `1` on success, `-1` on failure |
| [`3-cp.c`](3-cp.c) | Copies a source to a destination, creating or truncating the destination | `0` on success; error codes below |

[`main.h`](main.h) declares the three reusable functions. A `NULL` text pointer
means no text for create/append; a `NULL` filename is rejected. New-file modes
are subject to the process umask; existing file permissions are preserved.

## Build

From the repository root:

```bash
cd file_io
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -fsyntax-only [0-2]-*.c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-cp.c -o copy_file
```

The first command checks the reusable functions without creating object files.
To use them, include `main.h` in a caller and link the relevant source files
with that caller's `main`.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c main.h
betty-doc *.c main.h
```

Local checks found that the sources compile and pass the documentation checker.
The style checker reports that `main` in `3-cp.c` exceeds Betty's function-length
limit. These are local checks, not a run on the Ubuntu 20.04 submission system.

## Usage

Use disposable sample files to try the copy program:

```bash
printf 'Hello, file I/O!\n' > sample_from.txt
./copy_file sample_from.txt sample_to.txt
cmp sample_from.txt sample_to.txt
cat sample_to.txt
```

Expected text:

```text
Hello, file I/O!
```

A successful `cmp` prints nothing and returns `0`.

| Exit status | Error reported on standard error |
| --- | --- |
| `97` | `Usage: cp file_from file_to` for the wrong argument count |
| `98` | `Error: Can't read from file NAME` |
| `99` | `Error: Can't write to NAME` |
| `100` | `Error: Can't close fd NUMBER` |

## Behavior and limits

- The destination is opened with `O_TRUNC`; existing contents are replaced.
  Do not use the same file as both source and destination: this implementation
  does not detect that case and can truncate the source.
- Copying requests mode `0664` when creating a new destination.
- The text helpers use single reads/writes rather than retrying interrupted
  calls or partial writes. `read_textfile` reads at most the requested amount,
  not necessarily the entire file.
- Text lengths are calculated up to the first null terminator. These helpers
  are not general binary-buffer APIs; the copy program works with byte counts.

## Clean up

Remove the executable and sample files created above:

```bash
rm -f copy_file sample_from.txt sample_to.txt
```

# Dynamic Analysis with GDB

A C debugging exercise centered on an obfuscated numeric-input validator.
[`source.c`](source.c) reads a line from standard input, parses it with
`strtoul`, derives a key, computes a target, and compares two 16-bit signatures.
It prints `OK` and returns `0` when validation succeeds; otherwise it prints
`NO` and returns `1`.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Files

| File | Purpose |
| --- | --- |
| [`source.c`](source.c) | Input handling, tag decoding, integer mixing, key derivation, and validation |
| [`gdb_fundamentals.txt`](gdb_fundamentals.txt) | Saved hexadecimal values from the exercise, without explanatory labels |
| [`gdb_vsc.txt`](gdb_vsc.txt) | Additional saved hexadecimal values, without explanatory labels |
| `gdb_test` | Existing compiled executable; rebuild from source for the debug session below |

## Build

Install GDB as well as GCC for interactive debugging. From the repository root:

```bash
cd dynamic_analysis
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g -O0 source.c -o validator_debug
```

`-g` adds debug symbols and `-O0` makes source-level stepping easier. The new
executable name keeps the existing `gdb_test` artifact intact.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style source.c
betty-doc source.c
```

The current source compiles with the required flags but fails Betty checks,
including indentation, return-statement formatting, and missing function
comments. Compilation and style validation are separate checks.

## Usage

Supply the candidate on standard input, rather than as a command-line argument:

```bash
printf '1234\n' | ./validator_debug
```

The output is `OK` or `NO`; inspect `echo $?` immediately afterward for the
exit status. Non-numeric text is rejected:

```console
$ printf 'hello\n' | ./validator_debug
NO
```

## Debugging workflow

Start an interactive session from this directory:

```bash
gdb ./validator_debug
```

Example GDB commands:

```text
break validate
run
```

Enter a numeric candidate when the program waits for input. At the breakpoint:

```text
print user_pin
next
print k
next
print tgt
step
bt
continue
quit
```

`next` executes a source line without entering its calls; `step` can enter a
called function. `print` inspects values and `bt` shows the active call stack.
Useful additional breakpoints include `derive_key` and `compute_target`.
The saved hexadecimal notes do not identify their variables or inputs, so they
should not be treated as a reproducible trace or a documented accepted PIN.

## Input and implementation limits

- Input is read into a 128-byte buffer. Only a trailing newline is removed.
- `strtoul` requires that the remaining string be fully consumed, but the code
  does not check `errno` or the range before converting to `unsigned int`.
  It also inherits `strtoul` handling of leading whitespace and signs.
- The rotation helper assumes 32-bit unsigned integers. A zero rotation makes
  its expression shift by 32, which is undefined on a 32-bit `unsigned int`.
  Such a rotation can occur in this source, so observed results should not be
  treated as portable guarantees.
- This is a debugging exercise, not a production authentication mechanism.

## Clean up

Remove the executable created above:

```bash
rm -f validator_debug
```

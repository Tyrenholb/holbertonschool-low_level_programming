# Command-Line Arguments: `argc` and `argv`

Five standalone C programs introduce command-line arguments: printing the
program name, counting and listing arguments, and using arguments in simple
arithmetic.

`argc` counts the arguments, including the program name. `argv` holds the
argument strings: `argv[0]` is the program name used for invocation, and
`argv[1]` is the first argument supplied after it.

## Programs

| Source | Behavior | Exit status |
| --- | --- | --- |
| [`0-whatsmyname.c`](0-whatsmyname.c) | Prints `argv[0]`, followed by a newline | `0` |
| [`1-args.c`](1-args.c) | Prints the number of arguments, excluding the program name | `0` |
| [`2-args.c`](2-args.c) | Prints every argument on its own line, including the program name | `0` |
| [`3-mul.c`](3-mul.c) | Multiplies two values converted with `atoi`; prints `Error` if exactly two arguments are not supplied | `0` on success; `1` for the wrong argument count |
| [`4-add.c`](4-add.c) | Adds arguments containing only decimal digits; prints `0` when no arguments are supplied | `0` on success; `1` if an argument contains a non-digit character |

## Build

Requirements: GCC and a shell. Each source defines its own `main`, so compile
the programs separately.

From the repository root:

```bash
cd argc_argv
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-whatsmyname.c -o whatsmyname
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 1-args.c -o nargs
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 2-args.c -o args
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 3-mul.c -o mul
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 4-add.c -o add
```

## Usage

Run these commands from `argc_argv` after building:

```console
$ ./whatsmyname
./whatsmyname
$ ./nargs hello world
2
$ ./args hello world
./args
hello
world
$ ./mul 6 7
42
$ ./add 10 20 3
33
$ ./add
0
```

The shell determines how arguments are separated. Quoting keeps a string with
spaces together as one argument:

```console
$ ./nargs "hello world"
1
```

### Error examples

```console
$ ./mul 6
Error
$ ./add 10 two
Error
$ ./add -5 10
Error
```

Each command above returns status `1`. Run `echo $?` immediately after a
command to inspect its exit status.

## Input limits

- `mul` checks the number of arguments, but does not validate their numeric
  content before calling `atoi`. For example, `./mul hello 7` prints `0`
  and returns success.
- `add` accepts digit strings, including `0`, but rejects signs, decimal
  points, and spaces. An empty quoted argument (`""`) also passes its character
  check and contributes `0`.
- Neither arithmetic program checks the range of converted values or prevents
  signed integer overflow. Use small values whose conversion and arithmetic
  results fit in an `int`.

## Clean up

Remove the executables created by the build commands:

```bash
rm -f whatsmyname nargs args mul add
```

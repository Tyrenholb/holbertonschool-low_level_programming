# C — Low-Level Programming

This repository contains my C projects and exercises from Holberton School.
It covers the basics of compiling and writing C, then moves into pointers,
memory allocation, data structures, file handling, debugging, and benchmarking.

The [simple calculator](simple-calculator/README.md) was my first C project,
which I presented for a code review. The other folders contain focused
exercises and labs, each with its own README explaining the code and how to
build or use it.

## Project folders

The folders below are listed alphabetically. Follow a link for the project's
functions, build commands, examples, and current limitations.

| Folder | What it covers |
| --- | --- |
| [`ai_memory_visualizer_valgrind_tracer`](ai_memory_visualizer_valgrind_tracer/README.md) | Stack-frame and heap-memory examples, deliberate leaks and invalid accesses, Valgrind traces, memory maps, and crash analysis. Includes reviews of AI-generated explanations against source and recorded results. |
| [`argc_argv`](argc_argv/README.md) | Reading command-line arguments, printing the program name, counting and listing arguments, and using them for multiplication and addition. |
| [`benchmarking`](benchmarking/README.md) | Measuring CPU time with `clock()`, comparing nested and single-pass workloads, and timing build/process/reduce stages. Reports discuss measurement limits and runtime as an estimate of energy use. |
| [`doubly_linked_lists`](doubly_linked_lists/README.md) | Integer nodes with previous and next links. Functions print, count, prepend, append, find, sum, insert, delete, and free nodes. |
| [`dynamic_analysis`](dynamic_analysis/README.md) | Using GDB to follow a numeric-input validator, inspect derived values, set breakpoints, and step through function calls. |
| [`file_io`](file_io/README.md) | POSIX file descriptors, reading text, creating and appending to files, and a standalone file-copy program. |
| [`function_pointers`](function_pointers/README.md) | Passing callbacks, applying a function to array elements, searching with a comparison callback, and selecting calculator operations through function pointers. |
| [`functions_nested_loops`](functions_nested_loops/README.md) | Character checks, signs, absolute values, integer addition, alphabet output, multiplication tables, and nested loops that print every minute of a day. |
| [`hash_tables`](hash_tables/README.md) | A string-to-string hash table using djb2 and linked collision chains. Covers creation, insertion, replacement, lookup, printing, and cleanup. |
| [`hello_world`](hello_world/README.md) | The compilation pipeline: preprocessing, object files, assembly output, and linking. Also introduces `puts`, `printf`, and type sizes. |
| [`intro_debugging`](intro_debugging/README.md) | Following loop bounds and accumulated values in a sum-to-n program, a multiplication table, and row-sum calculations. |
| [`malloc_free`](malloc_free/README.md) | Allocating character arrays, copying and concatenating strings, creating a zero-filled integer grid, and freeing owned memory. |
| [`more_functions_nested_loops`](more_functions_nested_loops/README.md) | More character tests and arithmetic, repeated number output, line/square/triangle shapes, and a standalone FizzBuzz program. |
| [`more_malloc_free`](more_malloc_free/README.md) | Checked allocation, bounded string concatenation, zero-filled allocation, and inclusive integer ranges. |
| [`pointers_arrays_strings`](pointers_arrays_strings/README.md) | Pointer updates, string copying and transformation, array reversal, byte operations, searches, and two-dimensional array output. |
| [`recursion`](recursion/README.md) | Recursive string printing and length, factorials, powers, exact integer square roots, and primality checks. |
| [`secure_data_handling`](secure_data_handling/README.md) | An in-memory session store with add/get/set/delete commands. Focuses on copying data, transferring ownership, updating buffers, and releasing allocations. |
| [`simple-calculator`](simple-calculator/README.md) | My first C code-review project: a menu-driven integer calculator with addition, subtraction, multiplication, division, and a division-by-zero check. |
| [`singly_linked_lists`](singly_linked_lists/README.md) | String nodes with one next link. Functions print and count nodes, add at either end, and free copied strings and nodes. |
| [`structures_typedef`](structures_typedef/README.md) | Defining a structure and type alias, initializing and printing fields, allocating string copies, and distinguishing borrowed from owned data. |
| [`variables_if_else_while`](variables_if_else_while/README.md) | Variables, conditions, remainders, and loops through random-number classification, alphabet output, and digit sequences. |
| [`variadic_functions`](variadic_functions/README.md) | Variable-length argument lists with `va_start`, `va_arg`, and `va_end`, including integer sums and printing mixed types. |

## Requirements

The shared requirements for the C tasks were:

- Compile on Ubuntu 20.04 LTS using GCC.
- Use `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Follow Betty style, checked with
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

Some labs also use GNU Make, GDB, or Valgrind. Their READMEs explain which tools
are needed and any additional compiler options.

These are the project requirements, not a claim that every checked-in file
currently passes them. Folder READMEs document known build exceptions and
Betty findings. Local verification is separate from testing on the Ubuntu
20.04 submission environment.

## Build and use a project

The repository is a collection of independent exercises, not one application.
There is no single build command for every folder. Some C files define their
own `main`; others provide functions that need a caller or an output helper.

For example, from the repository root, build the argument-based multiplication
program:

```bash
cd argc_argv
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-mul.c -o multiply_example
./multiply_example 6 7
```

Output:

```text
42
```

Remove that example executable when finished:

```bash
rm -f multiply_example
```

For other projects, use the build instructions in their folder README.
Compiling every `.c` file together can link multiple `main` functions or miss
required helpers.

## Betty checks

With Betty installed and its commands on your `PATH`, run the checkers on the
C sources and headers for the project you are working on. For example, from
the repository root:

```bash
betty-style argc_argv/*.c
betty-doc argc_argv/*.c
```

Betty checks coding style and documentation. Compile and run the programs
separately to check their behavior. Debugging labs may contain deliberate
memory errors or crashes; read their instructions before running the examples.

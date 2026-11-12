# AI Memory Visualizer + Valgrind Tracer

A C laboratory project exploring stack frames, heap ownership, pointer aliasing,
and memory errors. Four small programs provide examples to inspect, run under
Valgrind, and explain with memory maps and crash analysis.

The analysis reports also review AI-generated explanations against the source
code and observed results, identifying incorrect claims about object lifetimes,
leaks, and the cause of a crash.

## Programs

| Program | What it demonstrates | Expected behavior |
| --- | --- | --- |
| [`stack_example.c`](programs/stack_example.c) | Recursion, local variables, and stack-frame lifetimes | Prints values and addresses during recursive entry and return; no deliberate memory error |
| [`heap_example.c`](programs/heap_example.c) | Separate allocations for a structure and its name | Deliberately frees Alice's structure without freeing her name, leaving a memory leak |
| [`aliasing_example.c`](programs/aliasing_example.c) | Two pointers referring to one heap allocation | Frees the allocation, then reads and writes through a dangling alias |
| [`crash_example.c`](programs/crash_example.c) | An unchecked null return value | Requests zero elements, receives `NULL`, and dereferences it; the recorded Linux run terminated with `SIGSEGV` |

The memory errors are intentional teaching examples. Use-after-free and null
pointer dereferences have undefined behavior: a program may print plausible
values, crash, or behave differently between runs.

## Requirements

- GCC and GNU Make to build the programs.
- Valgrind with Memcheck to reproduce the memory-tracing analysis.
- A Linux environment is used in the recorded reports.

## Build

From the repository root:

```bash
cd ai_memory_visualizer_valgrind_tracer/programs
make
```

The Makefile builds all four executables with:

```text
-Wall -Wextra -Werror -pedantic -std=gnu89 -g
```

Debug symbols (`-g`) let Valgrind associate errors with source locations.

### If GCC rejects the deliberate use-after-free

The [memory maps report](analysis/memory_maps.md#build-note) records that GCC
13.3.0 stopped the build at `aliasing_example.c`: `-Werror` promoted the
use-after-free warning to an error. If you encounter that diagnostic, build the
other examples and demote only that warning for the aliasing target:

```bash
make stack_example heap_example crash_example
make aliasing_example CFLAGS='-Wall -Wextra -Werror -pedantic -std=gnu89 -g -Wno-error=use-after-free'
```

This preserves the deliberate bug for analysis without changing the source.

## Run

From the `programs` directory after building:

```bash
./stack_example
./heap_example
./aliasing_example
./crash_example
```

`stack_example` prints local addresses and values across recursion depths.
Addresses can vary between executions. `heap_example` can finish normally while
leaking memory, and `aliasing_example` can appear to work despite invalid
accesses. `crash_example` deliberately reaches a null-pointer dereference;
the recorded Linux run exited with status `139` after a segmentation fault.

## Trace memory errors with Valgrind

From the same `programs` directory:

```bash
valgrind --leak-check=full --show-leak-kinds=all \
    --track-origins=yes ./heap_example

valgrind --leak-check=full --show-leak-kinds=all \
    --track-origins=yes ./aliasing_example
```

These options show detailed leak records, include every leak category, and
request origin information when undefined values are used.

The [recorded Valgrind analysis](analysis/valgrind_analysis.md), produced with
Valgrind 3.26.0, reports:

| Program | Recorded finding | Cause |
| --- | --- | --- |
| `heap_example` | 6 bytes in one block definitely lost | The separately allocated `Alice` string is never freed |
| `aliasing_example` | Two invalid reads and one invalid write; no remaining heap allocations | `b` is used after `free(a)` ends the shared allocation's lifetime |

A clean leak summary does not establish that all memory accesses are valid.
Exact addresses and diagnostic formatting may differ on your system.

## Analysis reports

- [Memory maps](analysis/memory_maps.md): stack-frame lifetimes, recursive calls,
  pointer aliases, and the effect of freeing a shared allocation.
- [Valgrind analysis](analysis/valgrind_analysis.md): leak classification,
  invalid-access traces, and checks against the source code.
- [Crash report](analysis/crash_report.md): the null-pointer failure path,
  recorded crash, review of AI suggestions, and a proposed return-value check.

## Clean up

From `programs`, remove the generated executables with:

```bash
make clean
```

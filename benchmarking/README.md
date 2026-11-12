# Benchmarking and Instrumentation

Three standalone C programs explore CPU timing: measuring a repeated loop,
comparing nested and single-pass traversal, and timing individual processing
stages. The accompanying reports record measurements and discuss the limits
of using runtime to reason about energy efficiency.

## Programs

| Source | Behavior | Output |
| --- | --- | --- |
| [`baseline_loop.c`](baseline_loop.c) | Performs 100,000,000 iterations, accumulating `i % 3` into a volatile result | Iteration count and CPU time in seconds |
| [`comparison_algorithms.c`](comparison_algorithms.c) | Initializes 50,000 integers, then times nested-prefix counting and single-pass counting of even values | Each count and its CPU time |
| [`instrumentation_lab.c`](instrumentation_lab.c) | Builds a seeded dataset of 50,000 integers, processes it, and computes a checksum | Total CPU time and separate build, process, and reduce times |

All three programs take no command-line input and return `0` on normal
completion. Dataset sizes and the seed are defined in the source files.

## Requirements

- The school compilation target is Ubuntu 20.04 LTS using GCC.
- Required compiler options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow the Betty style and pass both
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

### Current source limitations

`baseline_loop.c` uses `unsigned long long`, which triggers a diagnostic under
`-pedantic -std=gnu89` and fails with `-Werror` in local verification. Its
[recorded build](baseline_loop-metrics.md) adds `-Wno-long-long`. The command
below reproduces that workaround; it is an exception to the required flags,
not evidence that the source passes the strict school compilation command.

The current sources also fail Betty checks, including indentation errors and
missing function documentation. The requirements above describe the submission
standard; the existing files do not yet satisfy it.

## Build

Each source defines its own `main`, so compile the programs separately.
From the repository root:

```bash
cd benchmarking
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long baseline_loop.c -o baseline_loop
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 comparison_algorithms.c -o comparison_algorithms
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 instrumentation_lab.c -o instrumentation_lab
```

## Betty checks

With Betty installed and its commands available on your `PATH`, run these
checks from `benchmarking` before submitting:

```bash
betty-style *.c
betty-doc *.c
```

Compile and run the programs separately to check their behavior.

## Usage

From `benchmarking` after building:

```bash
./baseline_loop
./comparison_algorithms
./instrumentation_lab
```

The baseline prints `Iterations: 100000000` and an execution time.
The comparison prints a naive count of `625025000` and a single-pass count of
`25000`, each followed by its timing. The instrumentation program prints
`TOTAL`, `BUILD_DATA`, `PROCESS`, and `REDUCE` times in seconds; it computes
but normally does not print its checksum.

For repeated measurements, for example:

```bash
for run in 1 2 3; do
    ./comparison_algorithms
done
```

## Interpreting the measurements

- Timing uses `clock()` from `<time.h>`, which measures process CPU time rather
  than elapsed wall time. Results vary with the machine, compiler options,
  timer resolution, and execution conditions.
- The naive traversal is quadratic: it scans every prefix of the array and
  counts the same even elements repeatedly. The single-pass traversal is
  linear and counts each even element once. Their different results mean this
  is not a comparison of equivalent implementations of the same calculation.
- The recorded comparison reports averages of `0.473592` seconds and
  `0.000019667` seconds, approximately a 24,081-fold timing difference. These
  are historical measurements of these workloads, not a guaranteed speedup
  for an equivalent algorithm replacement.
- Very short stages may approach the timer's resolution. Repeat runs and keep
  build options consistent when comparing measurements.
- No program measures power or energy directly. Runtime alone does not
  establish an energy saving.

## Analysis reports

- [Baseline loop metrics](baseline_loop-metrics.md): the recorded compiler
  workaround and four timing samples.
- [Comparison metrics](comparison_algorithms-metrics.md): three runs, average
  timings, and the reported timing ratio.
- [Green efficiency analysis](green_efficiency_analysis.md): measurement
  methodology, runtime observations, and discussion of energy estimation.

## Clean up

From `benchmarking`, remove the executables with:

```bash
rm -f baseline_loop comparison_algorithms instrumentation_lab
```

`instrumentation_lab` is currently tracked in Git. Running this cleanup marks
that executable as deleted in your working tree.

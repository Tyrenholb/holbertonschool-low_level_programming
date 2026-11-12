# Variables, Conditions, and Loops

Ten standalone C programs practice integer and character variables, conditional
branches, remainders, and repeated output. The first two classify pseudorandom
numbers; the rest print fixed character sequences.

## Requirements

- Compilation target: Ubuntu 20.04 LTS using GCC.
- Required options: `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Code must follow Betty style and pass
  [`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
  and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Programs

| Source | Behavior |
| --- | --- |
| [`0-positive_or_negative.c`](0-positive_or_negative.c) | Generates an integer and reports whether it is positive, negative, or zero |
| [`1-last_digit.c`](1-last_digit.c) | Reports the signed last digit and whether it is greater than `5`, zero, or less than `6` and nonzero |
| [`2-print_alphabet.c`](2-print_alphabet.c) | Prints lowercase `a` through `z` |
| [`3-print_alphabets.c`](3-print_alphabets.c) | Prints lowercase then uppercase letters on one line |
| [`4-print_alphabt.c`](4-print_alphabt.c) | Prints lowercase letters excluding `e` and `q` |
| [`5-print_numbers.c`](5-print_numbers.c) | Prints decimal digits `0` through `9` |
| [`6-print_numberz.c`](6-print_numberz.c) | Also prints decimal digits using a character loop |
| [`7-print_tebahpla.c`](7-print_tebahpla.c) | Prints lowercase letters in reverse |
| [`8-print_base16.c`](8-print_base16.c) | Prints hexadecimal digits `0123456789abcdef` |
| [`9-print_comb.c`](9-print_comb.c) | Prints decimal digits separated by comma-space |

Every program appends a newline, takes no input, and returns `0`.

## Build

Each source defines `main`; compile them separately. From the repository root:

```bash
cd variables_if_else_while
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-positive_or_negative.c -o sign_example
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-last_digit.c -o last_digit_example
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-print_alphabet.c -o alphabet_example
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 9-print_comb.c -o digits_example
```

Use another source from the table to build its example separately. These names
avoid overwriting the existing compiled artifacts stored beside the sources.

## Betty checks

With Betty installed, run from this directory:

```bash
betty-style *.c
betty-doc *.c
```

The current sources compile and pass both installed Betty checkers locally.

## Usage

```console
$ ./alphabet_example
abcdefghijklmnopqrstuvwxyz
$ ./digits_example
0, 1, 2, 3, 4, 5, 6, 7, 8, 9
```

For variable output:

```bash
./sign_example
./last_digit_example
```

The first prints a generated value followed by `is positive`, `is negative`,
or `is zero`. The second prints `Last digit of ...` with its classification.
There is no fixed expected random value.

## Behavior and limits

- Both random-number programs seed `rand` with `time(0)`. Runs started within
  the same second can repeat the same value on the same platform.
- In C, a negative dividend can give a negative remainder. The last-digit
  program uses `n % 10` directly rather than taking an absolute value.
- The character loops rely on the target's ASCII-compatible character ranges.
  They are introductory exercises, not locale-aware text processing.
- The loops in the checked-in implementations use `for`, despite the broader
  project title mentioning `while`.

## Clean up

Remove the executables created above:

```bash
rm -f sign_example last_digit_example alphabet_example digits_example
```

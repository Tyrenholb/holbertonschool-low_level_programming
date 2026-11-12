# Simple Calculator

This was my first project in C, which I presented for a code review.
It is a simple calculator that displays a menu of basic mathematical operations.
The project helped me practise variables, user input, conditions, and loops.

## Features

- Displays a menu with addition, subtraction, multiplication, and division.
- Prompts the user to enter two integer values: A and B.
- Displays the result before returning to the main menu.
- Checks for division by zero and displays an error instead of dividing.
- Continues running until the user selects `0` to exit.

## How the code works

The program is written in [`calculator.c`](calculator.c). All the calculator
logic is inside `main`; the operations are handled by `if` and `else if`
branches rather than separate functions.

| Part | What it does |
| --- | --- |
| `main` | Starts the program, displays the menu, and handles the selected operation |
| `menu` | Stores the user's choice and controls the `while` loop |
| `A` and `B` | Store the two integers used in the calculation |
| `printf` | Displays the menu, prompts, results, and error messages |
| `scanf` | Reads the menu choice and integer values from the user |
| `while (menu != 0)` | Keeps the calculator running until the user chooses to quit |

## Menu options

| Choice | Operation | Calculation |
| --- | --- | --- |
| `1` | Addition | `A + B` |
| `2` | Subtraction | `A - B` |
| `3` | Multiplication | `A * B` |
| `4` | Division | `A / B`, provided B is not zero |
| `0` | Quit | Prints `Bye!` and exits successfully |

Choosing another integer displays `Invalid choice` and returns to the menu.

## Requirements

The C project requirements were Ubuntu 20.04 LTS, GCC, and the following
compiler options:

```text
-Wall -Werror -Wextra -pedantic -std=gnu89
```

Code was also required to follow Betty style, checked using
[`betty-style.pl`](https://github.com/hs-hq/Betty/blob/master/betty-style.pl)
and [`betty-doc.pl`](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl).

## Build and run

From the repository root:

```bash
cd simple-calculator
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator_example
./calculator_example
```

This builds a new executable without replacing the existing `calculator` file.

## How to use it

1. Enter the number for the operation you want to perform.
2. Enter an integer when prompted for A.
3. Enter an integer when prompted for B.
4. Read the result, then choose another operation or enter `0` to quit.

For example, select `1`, enter `12` for A, and enter `5` for B. The calculator
prints:

```text
Result: 17
```

For division, selecting `4` with A set to `12` and B set to `5` prints
`Result: 2`. The calculator uses integer arithmetic, so it discards the
fractional part. If B is `0`, it prints `Error: division by zero` and returns
to the menu.

## Betty checks

With Betty installed, run these commands from this directory:

```bash
betty-style calculator.c
betty-doc calculator.c
```

The current source compiles with the required flags and passes the installed
documentation checker locally. The style checker reports that `main` exceeds
Betty's function-length limit.

## Current limitations

- The program does not check whether `scanf` successfully read an integer.
  Entering non-numeric input can leave that input unread and cause the menu
  to repeat indefinitely. A crash is not guaranteed.
- Decimal input is not supported. It can leave characters unread and cause
  the same input problem.

## Clean up

Remove the executable created above when finished:

```bash
rm -f calculator_example
```

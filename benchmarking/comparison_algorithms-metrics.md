# Comparison Algorithms Metrics

## Run 1

tyren@NewPC:~/holbertonschool-low_level_programming/benchmarking$ ./comparison_algorithms
Naive algorithm result: 625025000
Naive algorithm time: 0.475517 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000019 seconds

## Run 2

tyren@NewPC:~/holbertonschool-low_level_programming/benchmarking$ ./comparison_algorithms
Naive algorithm result: 625025000
Naive algorithm time: 0.472340 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000020 seconds

## Run 3

tyren@NewPC:~/holbertonschool-low_level_programming/benchmarking$ ./comparison_algorithms
Naive algorithm result: 625025000
Naive algorithm time: 0.472918 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000020 seconds

## Average Execution Times

Naive algorithm:

(0.475517 + 0.472340 + 0.472918) / 3
= 0.473592 seconds

Single-pass algorithm:

(0.000019 + 0.000020 + 0.000020) / 3
= 0.000019667 seconds

## Relative Difference

0.473592 / 0.000019667
= approximately 24081

The naive algorithm was approximately 24,081 times slower than the single-pass algorithm.

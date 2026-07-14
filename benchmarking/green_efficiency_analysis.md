Green Efficiency Analysis

Measurement Methodology

For this project I compiled each program using the required compiler flags and ran the programs multiple times. The baseline program was executed three times to observe how much the execution time changed between runs. The algorithm comparison program was also executed three times. I recorded the execution times from each run and calculated the average execution time for both algorithms. For the instrumentation task, I used `clock()` from `<time.h>` to measure the total runtime as well as the time spent in the build, process, and reduce stages. All tests were run on the same computer to keep the results as consistent as possible.

Observed Performance Differences

The baseline program produced similar execution times on each run, although the times were not exactly the same. This shows that small differences can happen even when the program does the same work.

The algorithm comparison showed a much larger difference. The naive algorithm took about **0.473592 seconds** on average. The single-pass algorithm took about **0.000019667 seconds** on average. This means the naive algorithm was about **24,081 times slower** than the single-pass algorithm. The measurements clearly show that choosing a better algorithm can greatly improve performance.

Relation Between Runtime and Energy Consumption

This experiment did not measure electricity usage directly. Instead, runtime was used as an estimate of CPU activity. A program that runs for a longer time generally keeps the processor busy for longer. Based on the recorded measurements, the naive algorithm would likely use more energy than the single-pass algorithm because it spends much more time running.

Limitations of the Experiment

One limitation is that the execution time changed slightly between runs even though the program was the same. This can happen because the operating system is running other tasks in the background. Another limitation is that this experiment measured execution time instead of actual power consumption. Because of this, the results only estimate energy efficiency rather than measuring it directly.

Practical Engineering Takeaway

This project showed that writing efficient algorithms can have a large impact on performance. A better algorithm can finish much faster while producing the required result. It also showed the importance of measuring code instead of guessing which version is faster. Using simple timing tools such as `clock()` helps identify where a program spends most of its time and can guide future improvements.

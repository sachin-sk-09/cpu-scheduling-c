# cpu-scheduling-c
A C program collection that simulates three CPU scheduling algorithms from Operating Systems.

## Algorithms
- FCFS (First Come First Served) - fcfs.c
- SJF (Shortest Job First, non-preemptive) - sjf.c
- Round Robin - round_robin.c

## How to run
gcc fcfs.c -o fcfs
./fcfs

(Same steps for sjf.c and round_robin.c. Round Robin also asks for the time quantum.)

## Sample input
P1: arrival 0, burst 8
P2: arrival 1, burst 4
P3: arrival 2, burst 2
(Round Robin quantum = 2)

## Result (average waiting time)
| Algorithm   | Average waiting time |
|-------------|----------------------|
| FCFS        | 5.67                 |
| SJF         | 5.00                 |
| Round Robin | 4.33                 |

## What I learned
(Write 1-2 lines in your own words here.)

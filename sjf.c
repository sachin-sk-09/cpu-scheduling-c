#include <stdio.h>

int main() {
    int n;
    printf("Number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], done[n];
    for (int i = 0; i < n; i++) {
        printf("P%d arrival time, burst time: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        done[i] = 0;
    }

    int time = 0, finished = 0;
    float total = 0;
    while (finished < n) {
        int pick = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time) {
                if (pick == -1 || bt[i] < bt[pick])
                    pick = i;
            }
        }
        if (pick == -1) { time++; continue; }
        wt[pick] = time - at[pick];
        time += bt[pick];
        total += wt[pick];
        done[pick] = 1;
        finished++;
    }

    printf("\nProcess  Waiting\n");
    for (int i = 0; i < n; i++)
        printf("P%d       %d\n", i + 1, wt[i]);
    printf("Average waiting time = %.2f\n", total / n);
    return 0;
}

#include <stdio.h>

int main() {
    int n;
    printf("Number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n];
    for (int i = 0; i < n; i++) {
        printf("P%d arrival time, burst time: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    int time = 0;
    float total = 0;
    for (int i = 0; i < n; i++) {
        if (time < at[i]) time = at[i];
        wt[i] = time - at[i];
        time += bt[i];
        total += wt[i];
    }

    printf("\nProcess  Waiting\n");
    for (int i = 0; i < n; i++)
        printf("P%d       %d\n", i + 1, wt[i]);
    printf("Average waiting time = %.2f\n", total / n);
    return 0;
}

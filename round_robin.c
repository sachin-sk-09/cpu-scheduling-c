#include <stdio.h>

int main() {
    int n, q;
    printf("Number of processes: ");
    scanf("%d", &n);
    printf("Time quantum: ");
    scanf("%d", &q);

    int at[n], bt[n], rem[n], wt[n], inq[n];
    for (int i = 0; i < n; i++) {
        printf("P%d arrival time, burst time: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem[i] = bt[i];
        inq[i] = 0;
    }

    int queue[1000], front = 0, rear = 0;
    int time = 0, finished = 0;
    float total = 0;

    while (finished < n) {
        for (int i = 0; i < n; i++)
            if (!inq[i] && rem[i] > 0 && at[i] <= time) {
                queue[rear++] = i;
                inq[i] = 1;
            }
        if (front == rear) { time++; continue; }

        int p = queue[front++];
        int run = rem[p] < q ? rem[p] : q;
        time += run;
        rem[p] -= run;

        for (int i = 0; i < n; i++)
            if (!inq[i] && rem[i] > 0 && at[i] <= time) {
                queue[rear++] = i;
                inq[i] = 1;
            }

        if (rem[p] > 0) {
            queue[rear++] = p;
        } else {
            wt[p] = time - at[p] - bt[p];
            total += wt[p];
            finished++;
        }
    }

    printf("\nProcess  Waiting\n");
    for (int i = 0; i < n; i++)
        printf("P%d       %d\n", i + 1, wt[i]);
    printf("Average waiting time = %.2f\n", total / n);
    return 0;
}

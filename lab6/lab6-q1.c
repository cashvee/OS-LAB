#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

// ---------- Function Prototypes ----------
void preemptiveSJF(int n, int bt[], int at[]);
void roundRobin(int n, int bt[], int tq);
void nonPreemptivePriority(int n, int bt[], int priority[]);

int main() {
    int choice;
    while (1) {
        printf("\n--- Process Scheduling Menu ---\n");
        printf("1. Preemptive Shortest Job First (SJF)\n");
        printf("2. Round Robin (RR)\n");
        printf("3. Non-Preemptive Priority Scheduling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        int n;
        printf("Enter number of processes: ");
        scanf("%d", &n);

        int bt[n], at[n], priority[n], tq;

        printf("Enter burst time for each process:\n");
        for (int i = 0; i < n; i++) {
            printf("P%d: ", i + 1);
            scanf("%d", &bt[i]);
        }

        if (choice == 1) {
            printf("Enter arrival time for each process:\n");
            for (int i = 0; i < n; i++) {
                printf("P%d: ", i + 1);
                scanf("%d", &at[i]);
            }
            preemptiveSJF(n, bt, at);
        } else if (choice == 2) {
            printf("Enter time quantum: ");
            scanf("%d", &tq);
            roundRobin(n, bt, tq);
        } else if (choice == 3) {
            printf("Enter priority for each process (lower number = higher priority):\n");
            for (int i = 0; i < n; i++) {
                printf("P%d: ", i + 1);
                scanf("%d", &priority[i]);
            }
            nonPreemptivePriority(n, bt, priority);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// ---------------- PREEMPTIVE SJF ----------------
void preemptiveSJF(int n, int bt[], int at[]) {
    int rt[n], complete = 0, t = 0, shortest = 0, minm, finish_time;
    int check = 0;
    float wt = 0, tat = 0;

    for (int i = 0; i < n; i++) rt[i] = bt[i];

    printf("\nGantt Chart (Preemptive SJF):\n\n|");

    int timeline[100], proc[100], time_index = 0;

    while (complete != n) {
        minm = INF;
        check = 0;
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] < minm && rt[i] > 0) {
                minm = rt[i];
                shortest = i;
                check = 1;
            }
        }
        if (!check) {
            t++;
            continue;
        }

        rt[shortest]--;
        proc[time_index] = shortest + 1;
        timeline[time_index++] = t;
        t++;

        if (rt[shortest] == 0) {
            complete++;
            finish_time = t;
            tat += finish_time - at[shortest];
            wt += finish_time - at[shortest] - bt[shortest];
        }
    }
    timeline[time_index] = t;

    // Print Gantt chart
    for (int i = 0; i < time_index; i++)
        printf(" P%d |", proc[i]);
    printf("\n");
    for (int i = 0; i <= time_index; i++)
        printf("%-4d", timeline[i]);
    printf("\n");

    printf("\nAverage Turnaround Time: %.2f\n", tat / n);
    printf("Average Waiting Time: %.2f\n", wt / n);
}

// ---------------- ROUND ROBIN ----------------
void roundRobin(int n, int bt[], int tq) {
    int rt[n];
    for (int i = 0; i < n; i++) rt[i] = bt[i];

    int t = 0, done;
    int timeline[100], proc[100], time_index = 0;

    printf("\nGantt Chart (Round Robin, TQ = %d):\n\n|", tq);

    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                proc[time_index] = i + 1;
                timeline[time_index++] = t;
                if (rt[i] > tq) {
                    t += tq;
                    rt[i] -= tq;
                } else {
                    t += rt[i];
                    rt[i] = 0;
                }
                printf(" P%d |", i + 1);
            }
        }
    } while (!done);

    timeline[time_index] = t;
    printf("\n");
    for (int i = 0; i <= time_index; i++)
        printf("%-4d", timeline[i]);
    printf("\n\nRound Robin scheduling done.\n");
}

// ---------------- NON-PREEMPTIVE PRIORITY ----------------
void nonPreemptivePriority(int n, int bt[], int priority[]) {
    int order[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) order[i] = i;

    // Sort by priority (lower = higher)
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (priority[order[j]] < priority[order[i]]) {
                int tmp = order[i];
                order[i] = order[j];
                order[j] = tmp;
            }

    int t = 0;
    float avg_wt = 0, avg_tat = 0;
    printf("\nGantt Chart (Non-Preemptive Priority):\n\n|");

    for (int i = 0; i < n; i++) {
        wt[i] = t;
        for (int k = 0; k < bt[order[i]]; k++)
            printf(" ");
        printf(" P%d |", order[i] + 1);
        t += bt[order[i]];
    }
    printf("\n");

    int time = 0;
    for (int i = 0; i < n; i++) {
        printf("%-4d", time);
        time += bt[order[i]];
    }
    printf("%-4d\n", time);

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[order[i]];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
    printf("Average Turnaround Time: %.2f\n", avg_tat / n);
}

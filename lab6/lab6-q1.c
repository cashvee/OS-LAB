#include <stdio.h>
#include <stdlib.h>
#define INF 1e9

void preemptiveSJF(int n, int bt[], int at[]);
void roundRobin(int n, int bt[], int tq);
void nonPreemptivePriority(int n, int bt[], int priority[]);

int main() {
    int choice;
    while (1) {
        printf("\n1. Preemptive SJF  2. Round Robin  3. Non-Preemptive Priority  4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 4) break;

        int n;
        printf("Number of processes: "); scanf("%d", &n);
        int bt[n], at[n], priority[n], tq;

        for (int i = 0; i < n; i++) { printf("P%d burst time: ", i+1); scanf("%d",&bt[i]); }

        if (choice == 1) {
            for (int i = 0; i < n; i++) { printf("P%d arrival time: ", i+1); scanf("%d",&at[i]); }
            preemptiveSJF(n, bt, at);
        } else if (choice == 2) {
            printf("Time quantum: "); scanf("%d",&tq);
            roundRobin(n, bt, tq);
        } else if (choice == 3) {
            for (int i = 0; i < n; i++) { printf("P%d priority: ", i+1); scanf("%d",&priority[i]); }
            nonPreemptivePriority(n, bt, priority);
        }
    }
    return 0;
}

void preemptiveSJF(int n, int bt[], int at[]) {
    int rt[n]; for(int i=0;i<n;i++) rt[i]=bt[i];
    int t=0, complete=0, shortest, minm; float wt=0, tat=0;
    printf("\nGantt Chart: |");
    while(complete<n){
        minm=INF; int check=0;
        for(int i=0;i<n;i++) if(at[i]<=t && rt[i]<minm && rt[i]>0){ minm=rt[i]; shortest=i; check=1;}
        if(!check){ t++; continue; }
        rt[shortest]--; printf(" P%d |", shortest+1); t++;
        if(rt[shortest]==0){ complete++; tat += t-at[shortest]; wt += t-at[shortest]-bt[shortest]; }
    }
    printf("\nAverage TAT: %.2f, Average WT: %.2f\n", tat/n, wt/n);
}

void roundRobin(int n, int bt[], int tq){
    int rt[n]; for(int i=0;i<n;i++) rt[i]=bt[i];
    int t=0, done; printf("\nGantt Chart (RR): |");
    do{
        done=1;
        for(int i=0;i<n;i++){
            if(rt[i]>0){
                done=0; printf(" P%d |", i+1);
                if(rt[i]>tq){ rt[i]-=tq; t+=tq; } else { t+=rt[i]; rt[i]=0; }
            }
        }
    } while(!done);
    printf("\nTotal time: %d\n", t);
}

void nonPreemptivePriority(int n, int bt[], int priority[]){
    int order[n], wt[n], tat[n]; for(int i=0;i<n;i++) order[i]=i;
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++)
        if(priority[order[j]]<priority[order[i]]) { int tmp=order[i]; order[i]=order[j]; order[j]=tmp; }
    int t=0; float avg_wt=0, avg_tat=0;
    printf("\nGantt Chart: |");
    for(int i=0;i<n;i++){ printf(" P%d |", order[i]+1); wt[i]=t; t+=bt[order[i]]; }
    printf("\n");
    for(int i=0;i<n;i++){ tat[i]=wt[i]+bt[order[i]]; avg_wt+=wt[i]; avg_tat+=tat[i]; }
    printf("Average WT: %.2f, Average TAT: %.2f\n", avg_wt/n, avg_tat/n);
}
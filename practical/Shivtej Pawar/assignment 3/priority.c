#include <stdio.h>
#include <string.h>

struct process {
    char pname[10];
    int AT, BT, ST, FT, TT, WT, BT1, PR;
} p[15];
struct process t;
int n;

void get_data() {
    printf("Enter number of Processes: ");
    scanf("%d", &n);
    printf("Enter process details for %d process(es):\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter process name, arrival time, CPU burst time, priority: ");
        scanf("%s %d %d %d", p[i].pname, &p[i].AT, &p[i].BT, &p[i].PR);
        p[i].BT1 = p[i].BT;
    }
}

void put_data() {
    printf("\n\nProcesses are as below:\n");
    printf("\nProcess Name\tArrival Time\tCPU Burst Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("\n%s\t\t%d\t\t%d\t\t%d", p[i].pname, p[i].AT, p[i].BT, p[i].PR);
    }
}

void arrivalsort() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].AT > p[j].AT) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

void priority_sort(int start) {
    for (int i = start; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].PR > p[j].PR && p[j].AT <= p[start].FT) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}
 
void avgTTWT() {
    float sumtt = 0, sumwt = 0;
    for (int i = 0; i < n; i++) {
        p[i].TT = p[i].FT - p[i].AT;
        p[i].WT = p[i].TT - p[i].BT1;
        sumtt += p[i].TT;
        sumwt += p[i].WT;
    }
    printf("\nProcess\tAT\tBT\tTT\tWT\tST\tFT\n");
    for (int i = 0; i < n; i++) {
        printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d", p[i].pname, p[i].AT, p[i].BT1, p[i].TT, p[i].WT, p[i].ST, p[i].FT);
    }
    printf("\n\nAverage Turnaround Time = %.2f/%d = %.2f\n", sumtt, n, sumtt / n);
    printf("\n\nAverage Waiting Time = %.2f/%d = %.2f\n", sumwt, n, sumwt / n);
}

void pr() {
    char GC[150] = "0|";
    char str[5];
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].AT > time) {
            time = p[i].AT;
            sprintf(str, "%d", time);
            strcat(GC, str);
            strcat(GC, "|");
        }
        p[i].ST = time;
        strcat(GC, p[i].pname);
        strcat(GC, " ");
        time += p[i].BT;
        p[i].FT = time;
        sprintf(str, "%d", time);
        strcat(GC, str);
        strcat(GC, "|");
        priority_sort(i + 1);
    }

    printf("\n\n\t\tGantt Chart\n\n");
    puts(GC);
    avgTTWT();
}

int main() {
    get_data();
    put_data();
    arrivalsort();
    put_data();
    pr();
    return 0;
}

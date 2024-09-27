#include <stdio.h>
#include <string.h>

struct process {
    char pname[10];
    int AT, BT, ST, FT, TT, WT, BT1;
} p[15];

struct process t;
int i, n, j, k, bt, tq;
char GC[250];

void get_data() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter process details for %d processes\n", n);
    for (i = 0; i < n; i++) {
        printf("\nEnter Process name, arrival time, CPU burst time\n");
        scanf("%s %d %d", p[i].pname, &p[i].AT, &p[i].BT);
        p[i].BT1 = p[i].BT;
    }
}

void put_data() {
    printf("\nProcesses are as below:\n");
    printf("Process name\tArrival time\tCPU burst time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\n", p[i].pname, p[i].AT, p[i].BT);
    }
}

void arrivalsort() {
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].AT > p[j].AT) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

void burstsort() {
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].BT > p[j].BT) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

void avgTTWT() {
    int sumtt = 0, sumwt = 0;
    for (i = 0; i < n; i++) {
        p[i].TT = p[i].FT - p[i].AT;
        p[i].WT = p[i].TT - p[i].BT1;
        sumtt += p[i].TT;
        sumwt += p[i].WT;
    }

    printf("\nProcess\tAT\tBT\tTT\tWT\tFT\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pname, p[i].AT, p[i].BT1, p[i].TT, p[i].WT, p[i].FT);
    }

    printf("\nAverage turn around time = %.2f\n", (float)sumtt / n);
    printf("\nAverage wait time = %.2f\n", (float)sumwt / n);
}

void pre_sjf() {
    char str[5];
    int time = 0;
    i = 0;
    tq = 1;
    strcpy(GC, "0|");

    while (1) {
        int all_done = 1;
        for (i = 0; i < n; i++) {
            if (p[i].BT != 0) {
                all_done = 0;
                if (p[i].AT <= time) {
                    if (p[i].BT == p[i].BT1) {
                        p[i].ST = time;
                    }

                    strcat(GC, p[i].pname);
                    time += tq;
                    p[i].BT -= tq;

                    if (p[i].BT <= 0) {
                        p[i].FT = time;
                        p[i].BT = 0;
                    }

                    sprintf(str, "%d", time);
                    strcat(GC, " ");
                    strcat(GC, str);
                    strcat(GC, "|");
                } else {
                    time++;
                    i--;
                }
            }
        }

        if (all_done) {
            break;
        }

        burstsort();
    }

    printf("\n\nGantt chart\n\n");
    puts(GC);
    avgTTWT();
}

int main() {
    get_data();
    put_data();
    arrivalsort();
    put_data();
    pre_sjf();
    return 0;
}

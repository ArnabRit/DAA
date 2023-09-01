#include <stdio.h>
typedef struct {
    char id;
    int deadline;
    int profit;
} Job;
int compare(Job a, Job b) {
    return (b.profit - a.profit);
}
int findMaxDeadline(Job jobs[], int n) {
    int maxDeadline = 0,i;
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    return maxDeadline;
}

void jobSequencing(Job jobs[], int n) {
	int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (compare(jobs[j], jobs[j + 1]) < 0) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    int maxDeadline = findMaxDeadline(jobs, n);
    char result[maxDeadline]; 
    int slot[maxDeadline];
    for (i = 0; i < maxDeadline; i++)
        slot[i] = -1;
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                result[j] = jobs[i].id;
                slot[j] = i;
                break;
            }
        }
    }
    printf("Job Sequence: ");
    for (i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            printf("%c ", result[i]);
    }
    printf("\n");
}

int main() {
    Job jobs[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}


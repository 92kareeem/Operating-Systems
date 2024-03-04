#include<stdio.h>
#include<stdlib.h>
int main() {
    int i, n, ts, count = 0, t = 0, twt = 0, ttat = 0;
    printf("Enter number of Processes: ");
    scanf("%d", &n);
    int BT[n], RT[n], WT[n], TAT[n], AT[n];
    printf("\nEnter Time Slice: ");
    scanf("%d", &ts);
    for (i = 0; i < n; i++) {
        printf("\nEnter AT and BT of Process %d: ", i + 1);
        scanf("%d %d", &AT[i], &BT[i]);
        RT[i] = BT[i];
    }
    while (1) {
        int flag = 0; 
        for (i = 0; i < n; i++) {
            if (RT[i] > 0 && AT[i] <= t) {
                flag = 1; 
                if (RT[i] > ts) {
                    t += ts;
                    RT[i] -= ts;
                } else {
                    t += RT[i];
                    RT[i] = 0;
                    TAT[i] = t - AT[i];
                    WT[i] = TAT[i] - BT[i];
                    count++;
                }
            }
        }
        if (flag == 0)
            t++;
        if (count == n) 
            break;
    }
    for (i = 0; i < n; i++) {
        twt += WT[i];
        ttat += TAT[i];
    }
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\n", i + 1, AT[i], BT[i], WT[i], TAT[i]);
    }
    float awt = (float)twt / n;
    float attat = (float)ttat / n;
    printf("\nAWT: %1.2f ATAT: %1.2f", awt, attat);
    return 0;
}

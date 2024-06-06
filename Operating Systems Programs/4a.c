#include<stdio.h>
#include<stdlib.h>
int main(){
int n,i;
printf("\nEnter number of processes: ");
scanf("%d",&n);
int BT[n],WT[n],TAT[n],total_tat=0,total_wt=0;
WT[0] = 0;
for(i=0;i<n;i++){
printf("\nEnter BT of Process %d: ",i+1);
scanf("%d",&BT[i]);
}
for(i=1;i<n;i++){
WT[i] = WT[i-1] + BT[i-1];
total_wt = total_wt + WT[i];
}
for(i=0;i<n;i++){
TAT[i] = WT[i] + BT[i];
total_tat = total_tat + TAT[i];
}
float avg_wt = total_wt/n;
float avg_tat = total_tat/n;
printf("\nProcess\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
printf("\nP%d\t%d\t%d\t%d\n",i+1,BT[i],WT[i],TAT[i]);
printf("\nAvg WT: %.2f\tAvg TAT: %.2f\n",avg_wt,avg_tat);
}


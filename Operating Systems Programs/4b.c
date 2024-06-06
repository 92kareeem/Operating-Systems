#include<stdio.h>
#include<stdlib.h>
int main(){
int n,i,j,pos=0;
printf("\nEnter number of processes: ");
scanf("%d",&n);
int BT[n],p[n],WT[n],TAT[n],total_tat=0,total_wt=0;
WT[0] = 0;
for(i=0;i<n;i++){
printf("\nEnter BT of Process %d: ",i+1);
scanf("%d",&BT[i]);
p[i] = i+1;
}
for(i=0;i<n-1;i++){
pos = i;
for(j=i+1;j<n;j++){
if(BT[j] < BT[pos])
pos = j;
}
int temp = BT[i];
BT[i] = BT[pos];
BT[pos] = temp;
temp = p[i];
p[i] = p[pos];
p[pos] = temp;
}
for(i=1;i<n;i++){
WT[i] = WT[i-1] + BT[i-1];
total_wt = total_wt + WT[i];
}
for(i=0;i<n;i++){
TAT[i] = WT[i] + BT[i];
total_tat = total_tat + TAT[i];
}
float avg_wt = (float)total_wt/n;
float avg_tat = (float)total_tat/n;
printf("\nProcess\tBT\tWT\tTAT\n");
for(i=0;i<n;i++){
printf("\nP%d\t%d\t%d\t%d\n",p[i],BT[i],WT[i],TAT[i]);
}
printf("\nAvg WT: %.2f\tAvg TAT: %.2f\n",avg_wt,avg_tat); 
}


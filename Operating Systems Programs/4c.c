#include<stdio.h>
#include<stdlib.h>
int main(){
int i,n,ts,count=0,t,twt,ttat;
printf("Enter number of Processes: ");
scanf("%d",&n);
int BT[n],RT[n],WT[n],TAT[n];
printf("\nEnter Time Slice: ");
scanf("%d",&ts);
for(i=1;i<=n;i++){
printf("\nEnter BT of Process %d: ",i+1);
scanf("%d",&BT[i]);
}
for(i=1;i<=n;i++){
RT[i] = BT[i];
}
while(1){
for(i=1;i<=n;i++){
if(RT[i] > 0){
if(RT[i] > ts){
t = t + ts;
RT[i] = RT[i] - ts;
}
else if(RT[i] <= ts){
t = t + RT[i];
RT[i] = 0;
TAT[i] = t;
WT[i] = t - BT[i];
count++;
}
}
}
if(count==n)
break;
}
for(i=1;i<=n;i++){
twt = twt + WT[i];
ttat = ttat + TAT[i];
}
printf("\nProcess\tBT\tWT\tTAT\n");
for(i=1;i<=n;i++){
printf("\nP%d\t%d\t%d\t%d\n",i,BT[i],WT[i],TAT[i]);
}
float awt = (float)twt/n;
float attat = (float)ttat/n;
printf("\nAWT: %1.2f ATAT: %1.2f",awt,attat);
}

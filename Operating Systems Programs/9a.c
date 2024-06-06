#include<stdio.h>
#include<math.h>
main(){
int diskreq[20],n,diskhdpos;
int i,j,k,totseek=0,max,diff;
float avgdiskmove;
printf ("Enter the number of disks read requests\n");
scanf("%d",&n);
printf ("Enter the [%d] disk read request positions \n",n);
for(i=0;i<n;i++)
scanf("%d",&diskreq[i]);
printf("Enter the initial disk head position\n");
scanf("%d",&diskhdpos);
totseek = abs(diskreq[0] -diskhdpos);
printf("Disk head movement from %d to %d is [%d] \n",diskhdpos,diskreq[0],totseek);
for(j=1;j<n;j++){
	diff=abs(diskreq[j]-diskreq[j-1]);
	totseek+=diff;
	printf("Disk head movement from %d to %d is [%d] \n",diskreq[j-1],diskreq[j],diff);
}
avgdiskmove = (float) totseek/n;
printf("Total seek time to process the above disk read requests is %d\n",totseek);
printf("Average seek time to process the above disk read requests is%f\n",avgdiskmove);
}


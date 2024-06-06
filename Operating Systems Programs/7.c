#include<stdio.h>
#include<stdlib.h>
int main(){
int max[10][10],need[10][10],allocation[10][10],available[10],finished[10],safeseq[10];
int pr_cnt,res_cnt,i,j,count=0,process;
system("clear");
printf("\nEnter the system state information\n");
printf("Enter the number of processes:");
scanf("%d",&pr_cnt);
for(i=0;i<pr_cnt;i++){
	finished[i]=0;
}
printf("\nEnter the number of resources:");
scanf("%d",&res_cnt);
printf("\nEnter the max matrix for all the processes:");
for(i=0;i<pr_cnt;i++){
	printf("Enter max info for process[%d]:",i+1);
	for(j=0;j<res_cnt;j++){
			scanf("%d",&max[i][j]);
	}
}
for(i=0;i<pr_cnt;i++){
	printf("Enter allocation info for process[%d]\n",i+1);
	for(j=0;j<res_cnt;j++){
		scanf("%d",&allocation[i][j]);
	}
}
printf("Enter the available resources in the system:\n");
for(i=0;i<res_cnt;i++){
	printf("\navailable[%d]=",i);
	scanf("%d",&available[i]);
}
for(i=0;i<pr_cnt;i++){
	for(j=0;j<res_cnt;j++){
		need[i][j]=max[i][j]-allocation[i][j];
	}
}
do{
	printf("\nAvailable resources are: \t");
	for(j=0;j<res_cnt;j++)
	printf("%d",available[j]);
	printf("\nmax matrix:\tallocation matrix:\n");
	for(i=0;i<pr_cnt;i++){
		for(j=0;j<res_cnt;j++){
			printf("%d",max[i][j]);
		}
		printf("\t");
		for(j=0;j<res_cnt;j++){
			printf("%d",allocation[i][j]);
		}
		printf("\n");
	}
	process=-1;
		for(i=0;i<pr_cnt;i++){
			if(finished[i]==0){
				process=i;
				for(j=0;j<res_cnt;j++){
					if(available[j]<need[i][j]){
						process=-1;
						break;
					}
				}
			}
			if(process!=-1)
			break;
		}
		if(process!=-1){
			safeseq[count]=process+1;
			count++;
			for(j=0;j<res_cnt;j++){
				available[j]+=allocation[process][j];
				allocation[process][j]=0;
				max[process][j]=0;
				finished[process]=1;
			}
		}
	}
	while(count!=pr_cnt && process!=-1);
	if(count==pr_cnt){
		printf("\nthe system is in a safe state\n");
		printf("\nSafe sequence:<");
		for(i=0;i<pr_cnt;i++)
		printf("%d",safeseq[i]);
		printf(">\n");
	}
	else{
		printf("\n The system is in unsafe state!!\n");
	}
}


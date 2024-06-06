#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
main(){
int shamid,*shmptr,nb,count,i;
system("clear");
printf("\nP:PID=%d\tPPID=%d\n",getpid(),getppid());
printf("Enter the no. of bytes\n");
scanf("%d",&nb);
shamid=shmget((key_t)95,nb*sizeof(int),IPC_CREAT|0666);
if(shamid==-1){
perror("SHM_ERR");
exit(1);
}
printf("\nMP:shmID is %u\n",shamid);
system("ipcs -m");
shmptr=(int *) shmat(shamid,0,0);
if(shmptr==NULL){
perror("SHM_ATT_ERR");
exit(1);
}
printf("\nMP:sMID is %u and shmptr is %u\n",shamid,shmptr);
system("ipcs -m");
printf("Enter no. of elements \n");
scanf("%d",&count);
for(i=0;i<count;i++){
printf(" Enter no. to write\n");
scanf("%d",(shmptr+i));
}
printf("The elemnts in shm are:\n");
for(i=0;i<count;i++){
printf("\nMP:Data Value[%d] is at loc [%d]",(*shmptr+i),(shmptr+i));
}
shmdt(shmptr);
shmctl(shamid,IPC_RMID,0);
system("ipc -m");
}


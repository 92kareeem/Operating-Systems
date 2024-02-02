#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    int pid,a[2];
    char str[20],buf[20];
    pipe(a);
    pid=fork();
if(pid == 0){
    strcpy(str,"Welcome");
    write(a[1],str,sizeof(str));
printf("\nMessage from child is: %s\n",str);
}
else if(pid > 0){
    read(a[0],buf,sizeof(buf));
    printf("\nMessage read from Parent is: %s",buf);
}
else{
    perror("CHILD NOT CREATED");
}
}
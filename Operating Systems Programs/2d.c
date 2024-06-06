#include<stdio.h>
#include<unistd.h>
int main(){
	char * args[]={"/bin/ls","-1",NULL};
	execvp("/bin/ls",args);
	perror("execvp");
	return 1;
}

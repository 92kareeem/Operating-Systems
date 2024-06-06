#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	pid_t pid;
	int status;

	pid=fork();
	if (pid<0){
		perror("Fork Failed");
		return 1;
	}
	if (pid==0){
		printf("Child Process exiting.\n");
		exit(42);
	}
	else{
		printf("Parent process(PID : %d),Child PID:%d\n",getpid(),pid);
		wait(&status);
		if (WIFEXITED(status)){
			printf("child process exited with status:%d\n",WEXITSTATUS(status));
		}
	}
	return 0;
}

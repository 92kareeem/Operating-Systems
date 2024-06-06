#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid;
	pid = fork();
	if (pid<0){
		perror("Fork Failed");
		return 1;
	}
	if (pid==0){
		printf("Child Process(PID:%d)\n",getpid());
	}
	else{
		printf("Parent process (PID:%d), Child PID:%d\n",getpid(),pid);
	}
	return 0;
}


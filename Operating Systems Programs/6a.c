#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum+N-1)%N
#define RIGHT (phnum)%N
int state[N];
int phil[N]={0,1,2,3,4};
sem_t mutex;
sem_t S[N];
void test(int phnum){
if(state[phnum]==HUNGRY &&state[LEFT]!=EATING &&
state[RIGHT]!=EATING){
state[phnum]=EATING;
sleep(2);
printf("Philosopher %d takes %d fork and %dfork\n",phnum,LEFT,RIGHT);
printf("%d is eating\n",phnum);
sem_post(&S[phnum]);
}
}
void takeFork(int phnum){
sem_wait(&mutex);
state[phnum]=HUNGRY;
printf("%d is hungry\n",phnum);
test(phnum);
sem_post(&mutex);
sem_wait(&S[phnum]);
sleep(1);
}
void putFork(int phnum){
sem_wait(&mutex);
state[phnum]=THINKING;
printf("philosopher %d putting fork %d and %d\n",phnum,LEFT,RIGHT);
	printf("philosopher %d is thinking\n",phnum);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}
void *philosopher(void *num){
	while(1){
		int *i=num;
		sleep(1);
		takeFork(*i);
		sleep(1);
		putFork(*i);
	}
}
int main(){
int i;
pthread_t tid[N];
sem_init(&mutex,0,1);
for(i=0;i<N;i++){
	sem_init(&S[i],0,0);
}
for(i=0;i<N;i++){
	pthread_create(&tid[i],NULL,philosopher,&phil[i]);
	printf("philosopher %d is thinking\n",phil[i]);
}
for(i=0;i<N;i++){
	pthread_join(tid[i],NULL);
}
} 

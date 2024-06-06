#include<stdio.h>
main(){
int i,j,n,a[50],frame[10],no,k,avail,count=0;
printf("Enter the length of ref string : ");
scanf("%d",&n);
printf("Enter reference string : \n");
for(i=1;i<=n;i++){
	scanf("%d",&a[i]);
}
printf("Enter frame size : ");
scanf("%d",&no);
for(i=0;i<no;i++)
frame[i]=-1;
j=0;
printf("\nref_str\tpageframe\n");
for(i=1;i<=n;i++){
	printf("%d\t",a[i]);
	avail=0;
	for(k=0;k<no;k++){
		if(frame[k]==a[i])
		avail=1;
	}
	if(avail==0){
		frame[j]=a[i];
		j=(j+1)%no;
		count++;
		for(k=0;k<no;k++)
		printf("%d\t",frame[k]);
	}
	printf("\n");
}
printf("no.  of page faults = %d\n",count);
}


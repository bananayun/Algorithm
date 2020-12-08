#include<stdio.h>
int main(){
	double s=0;
	int n,i;
	scanf("%d",&n);
	for(i=1;;i++) {
		s+=1.0/i;
		if(s>n) break;
	}
	printf("%d\n",i);
	return 0; 
} 

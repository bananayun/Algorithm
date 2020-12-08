#include<stdio.h>
int main(){
	int i;
	double s=0,n,t=2;
	scanf("%lf",&n);
	for(i=0;s<n;i++){
		s+=t;
		t*=0.98;
		
	}
	printf("%d",i);
	return 0;
}

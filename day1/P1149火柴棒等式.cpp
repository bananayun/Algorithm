#include<cstdio>
int main(){
	int n,a[2001]={6},b[10]={6,2,5,5,4,5,6,3,7,6},count=0,t;
	scanf("%d",&n);
	for(int i=0;i<=2000;i++){
			 t=i;
		while(t>0){
			a[i] += b[t%10];
			t/=10;
		}
	}
	for(int i=0;i<1001;i++){
		for(int j=0;j<=1000;j++)
		if(a[i]+a[j]+a[i+j]+4==n)count++;
	}
	printf("%d",count);
} 

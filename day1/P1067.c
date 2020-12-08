#include<stdio.h>
int main(){
	int n,i,m;
	scanf("%d",&n);
	for(i=n;i>=0;i--){
		scanf("%d",&m);
		if(m==0)
		continue;
		if(m>0&&i!=n)
		printf("+");
		if(m!=1&&m!=-1&&i!=0)
		printf("%d",m);
		else if(m==-1&&i!=0)
		printf("-");
		if(i>1)
		printf("x^%d",i);
		else if(i==1)
		printf("x");
		else if(m!=0)
		printf("%d",m);
		
	}
}

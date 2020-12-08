#include<stdio.h>
int main(){
	int x,n,i,j,s=0;
	scanf("%d%d",&x,&n);
	for(i=x,j=1;j<=n;j++,i++)
		if(i%7<=5&&i%7>0) s++;
	printf("%d",s*250);
}

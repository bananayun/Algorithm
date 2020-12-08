#include<stdio.h>
int main(){
	int i,n[10],t,s=0;
	for(i=0;i<10;i++)	scanf("%d",&n[i]);
	scanf("%d",&t);
	for(i=0;i<10;i++) if(t+30>=n[i]) s++;
	printf("%d",s);
	return 0; 
} 

#include<stdio.h>
#include<string.h>
int main(){
   int i;
   for(i=123;i<=329;i++){
   	int a[10],t=0,j;
   	memset(a,0,sizeof(a));
   	a[i%10]=a[i/10%10]=a[i/100]=a[i*2%10]=a[i*2/10%10]=a[i*2/100]=a[i*3%10]=a[i*3/10%10]=a[i*3/100]=1;
	for(j=1;j<10;j++)
	t+=a[j];
	if(t==9) printf("%d %d %d\n",i,i*2,i*3);
   }
}

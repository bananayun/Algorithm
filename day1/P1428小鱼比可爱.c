#include<stdio.h>
#include<string.h>
int main(){
	int a[101],b[101],i,j,n;
	scanf("%d",&n);
	memset(b,0,sizeof(b));

	for(i=0;i<n;i++){scanf("%d",&a[i]);
		for(j=0;j<i;j++)
		if(a[j]<a[i]) b[i]++;
		if(i<n-1) 
		printf("%d ",b[i]);
		else
		printf("%d",b[i]);
	}
	return 0;
}

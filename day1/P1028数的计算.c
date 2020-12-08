#include<stdio.h>
int main(){
	int n,i,j,c[10002];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i/2;j++) c[i]+=c[j];
		c[i]++;
	}
	printf("%d",c[n]);
	return 0;
}

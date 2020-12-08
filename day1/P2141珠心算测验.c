#include<stdio.h>
int a[20002],b[20002];
int main(){
	int n,i,j,s=0,c[101];
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&c[i]);
		a[c[i]]=1;
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			b[c[i]+c[j]]++;
		}
	}
	for(i=0;i<20002;i++)if(b[i]>0&&a[i])s++;
	printf("%d",s);
	return 0;
}

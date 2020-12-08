#include<stdio.h>
int a[100000000];
int main(){
	int n,i,max=1,s=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[i-1])max++;
		else if(max>s){
			s=max;
			max=1;
		}
		else
		max=1;
	}
	printf("%d",s);
	return 0;
}

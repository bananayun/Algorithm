#include<stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	int a[n][4],q,w,count=-1;
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	scanf("%d%d",&q,&w);
	for(i=0;i<n;i++){
		
			if(q>=a[i][0]&&q<=a[i][2]+a[i][0]&&w>=a[i][1]&&w<=a[i][3]+a[i][1])
			
			count=i+1;
	
	}
	printf("%d",count);
} 

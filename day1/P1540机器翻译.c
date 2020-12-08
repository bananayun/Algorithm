#include<stdio.h> 
int main(){
	int i,j,k,n,m,count=0;
	scanf("%d%d",&m,&n);
	int a[m],b[n];
	for(i=0;i<n;i++)scanf("%d",&b[i]);
	for(i=0;i<m;i++)a[i]=-1;
	for(i=0;i<n;i++){
		int flag=1;
		for(j=0;j<m;j++)
			if(a[j]==b[i]){
				flag=0;
				break;	
			}
		if(flag){
		for(k=0;k<m-1;k++)a[k]=a[k+1];
			a[k]=b[i];
			count++;
			
			}	 
	}
printf("%d",count);
}

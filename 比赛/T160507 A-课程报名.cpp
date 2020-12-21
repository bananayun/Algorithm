#include<cstdio>
int main(){
	int n,v,m,a,sum = 0;
	scanf("%d %d %d %d",&n,&v,&m,&a);
	//sum += v;//≥ı º∂®º€
	for(int i = 0;i < n;i++){
		if(i % m == 0 && i!=0)v += a;
		sum += v;
	} 
	printf("%d",sum);
	return 0;
} 

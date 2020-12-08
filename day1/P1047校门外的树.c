#include<stdio.h>
#include<string.h>
int main(){
	int L,M,i,s=0,w=0,a,b;
	scanf("%d %d",&L,&M);
	int c[L+10];
	memset(c,0,sizeof(c));
	while(M--){
		scanf("%d %d",&a,&b);
		c[a]++;
		c[b+1]--;
	}
	for(i=0;i<=L;i++){
		w+=c[i];
		if(w<=0) s++;
	}
	printf("%d",s);
} 

#include<stdio.h>
int main(){
	int x,n,i,s=0,t,w;
	scanf("%d %d",&n,&x);
	for(i=0;i<=n;i++){
		t=i;
		while(t!=0){
			w=t%10;
			if(w==x) s++;
			t/=10;
		}
	}
	printf("%d",s);
	return 0;
}

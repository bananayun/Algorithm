#include<stdio.h>
int main() {
	int i,sum,t,w;
	char  c[85];
	scanf("%d",&w);
	while(w--) {
		sum=0,t=0;
		scanf("%s",c);
		for(i=0; c[i]!='\0'; i++) {
			if(c[i]=='O') sum+=++t;
			else t=0;
		}
		printf("%d\n",sum);
	}
}

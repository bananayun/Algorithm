#include<stdio.h>
#include<string.h>
int main() {
	char c[85];
	int i,j,k,t=0,n;
	scanf("%d",&n);
	while(n--) {
		scanf("%s",c);
		int k1=1;
		for(i=1; i<=strlen(c)/2; i++) {
				 k1=1;
			for(k=0; k<i; k++) {
				for(j=i+k; j<strlen(c); j+=i) {
					if(c[k]!=c[j]) {
						k1=0;
						break;
					}
				}
				if(k1==0) break;
			}
			if(k1) {
				printf("%d",i);
				break;
			}
		}
		if(!k1)printf("%d",strlen(c));
	}
}

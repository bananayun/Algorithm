#include<stdio.h>
#include<string.h>
int main() {
	int a[10],i,t,n,x;
	scanf("%d",&n);
	getchar();
	while(n--) {
		scanf("%d",&x);
		memset(a,0,sizeof(a));
		for(i=1; i<=x; i++) {
			t=i;
			while(t>0) {
				a[t%10]++;
				t/=10;
			}
		}
		printf("%d",a[0]);
		for(i=1; i<10; i++) {
			printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}

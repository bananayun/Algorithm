#include<stdio.h>
#include<string.h>
int main() {
	int a[26],i,j,max;
	char b[100];
	memset(a,0,sizeof(a));
	for(i=0; i<4; i++) {
		gets(b);
		for(j=0; j<strlen(b); j++) {
			if(b[j]>='A'&&b[j]<='Z')
				a[b[j]-65]++;
		}
	}

	max=a[0];
	for(i=0; i<26; i++) if(max<a[i])max=a[i];

	for(i=max; i>0; i--) {
		for(j=0; j<26; j++) {
			if(a[j]>=i) printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
	for(i=0; i<26; i++) printf("%c ",65+i);
}

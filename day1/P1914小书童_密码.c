#include<stdio.h>
int main(){
	int n,i;
	char c[52];
	scanf("%d",&n);
	scanf("%s",c);
	for(i=0;c[i]!='\0';i++)
	putchar((c[i]-'a'+n)%26+'a');
	return 0;
}

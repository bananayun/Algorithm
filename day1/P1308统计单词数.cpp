#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[11],b[2000001];
int main(){
	
	int i,j,k,n=0,t,s=0,ss=0;
	gets(a);
	//gets(b);
	strcat(a," ");
	strcat(b," ");
	
	//转化为小写 
	for(i=0;i<strlen(a);i++)
		a[i]=tolower(a[i]);
				
	for(i=0;;i++){
		scanf("%c",&b[i]);
		b[i]=tolower(b[i]);
		if(b[i]==' '|| b[i]=='\n'){
			s=1;
			for(j=n,k=0;j<=i,a[k]!='\0';j++,k++){
				if(b[j]==a[k]) s*=1;
				else {
				s=0;
				break;
				}
			}
			if(s==1) ss++;
			if(ss==1&&s==1) t=n;
			n=i+1;
			if(b[i]=='\n') break;
		}
	}
	if(ss>=1) printf("%d %d",ss,t);
	else printf("%d",-1);
	return 0;
	
} 

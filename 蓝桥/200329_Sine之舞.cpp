#include<stdio.h>

void An(int n)
{
	int a=1;
	
	while(a<=n){
	if(n==a) 
		printf("sin(%d)",n); 
	else
	{
		printf("sin(%d",a);
		if(a%2==1)
			printf("-");
		else
			printf("+");
	}
	a++;
	}
	while(--n)	printf(")");
}
void Sin(int n)
{	int a=n,b=1;
	while(--a)printf("(");
	a=n;
	for(int i=n;i>0;i--){
		An(b++);
		if(i!=1)
		printf("+%d)",i);
		else printf("+%d",i);
	}

}
int main()
{
	int n;
	scanf("%d",&n);
	Sin(n);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

 
int f(int n)
{
    if(n==1 || n==2)
        return 1;
    else
        return  f(n-1)+f(n-2);
}
int fib(int n) {
    int first = 1,i,third=1;
    int second = 1;
	for(i = 3; i <= n; i++){
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}

void main()
{
    int a,sum=0,i;
    printf("ÇëÊäÈëNÖµ");
    scanf("%d",&a);
    for(i=1;i<=a;i++)sum+=f(i);
	printf("µİ¹é£º%d\n",sum);
	sum=0;
	for(i=1;i<=a;i++)sum+=fib(i);
    printf("Ñ­»·£º%d\n",sum);
}


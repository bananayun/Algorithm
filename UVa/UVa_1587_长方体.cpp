#include<iostream>
using namespace std;
int main()
{
	int a[6],b[6];
	while(1)
	{int c[10000],t=0;
		for(int i=0;i<6;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			c[a[i]]++; c[b[i]]++;
		}
		for(int i=0;i<6;i++)
		if(c[a[i]]%4 == c[b[i]]%4) t++;
		if(t==6)printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
}

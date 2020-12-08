#include<iostream>
#include<cstring>
#include<cstdio>
#define M 50
using namespace std;
typedef struct
{
	char data[M];
	int weight,p,L,R;
}HTNode;
typedef struct
{
	char cd[50];
	int start;
}HCode;
void Create(HTNode ht[],int n)
{
	int i,k,ln,rn,m1,m2;
	for(i = 0;i < 2*n-1;i++)
		ht[i].p = ht[i].L = ht[i].R = -1;
	for(i = n;i < 2*n-1;i++)
	{
		m1 = m2 = 32767;
		ln = rn = -1;
		for(k = 0;k < i;k++)
		{
			if(ht[k].p == -1)
			{
				if(ht[k].weight < m1)
				{
					m2 = m1;
					rn = ln;
					m1 = ht[k].weight;
					ln = k;
				}
				else if(ht[k].weight < m2)
				{
					m2 = ht[k].weight;
					rn = k;
				}
			}
			ht[i].weight = ht[ln].weight + ht[rn].weight;
			ht[i].L = ln;
			ht[i].R = rn;
			ht[ln].p = ht[rn].p = i;
		}
	}
}
void CreateHCode(HTNode ht[],HCode hcd[],int n)
{
	int i,f,c;
	HCode hc;
	for(i = 0;i < n;i++)
	{
		hc.start = n;
		c = i;
		//c = ht[i].weight;
		f = ht[i].p;
		while(f != -1)
		{
			if(ht[f].L == c)
				hc.cd[hc.start--] = '0';
			else
				hc.cd[hc.start--] = '1';
			c = f;
			f = ht[f].p;
		}
		hc.start++;
		hcd[i] = hc;
	}
}
void DispHCode(HTNode ht[],HCode hcd[],int n)
{
	int i,j,k,sum = 0,m = 0;                                                                                                                                                           
	cout<<"  输出哈夫曼编码：\n";
	for(i = 0;i < n;i++)
	{
		j = 0;
		cout<<"   "<<ht[i].data<<"\t";
		for(k = hcd[i].start;k <= n; k++)
		{
			cout<<hcd[i].cd[k];
			j++;
		}
		m += ht[i].weight;
		sum += ht[i].weight*j;
		cout<<endl;
	}
	cout<<"\n   平均长度="<<sum/m<<endl;
}
int main()
{
	int n = 8,i;
	char *str[] ={"a","b","c","d","e","f","g","h"};//{'a','b','c','d','e','f','g','h'};// 
	int fum[] = {7,19,2,6,32,3,21,1};
	HTNode ht[M];
	HCode hcd[50];
	for(i = 0;i < n;i++)
	{
		strcpy(ht[i].data,str[i]);
		ht[i].weight = fum[i];
	}
	cout<<endl;
	Create(ht,n);
	CreateHCode(ht,hcd,n);
	DispHCode(ht,hcd,n);
	cout<<endl;
}

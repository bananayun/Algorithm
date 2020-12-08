#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
bool comp(int a, int b){return a < b;}
int main() {
	int m,n,k,l,d,i;
	cin>>m>>n>>k>>l>>d;
	int a[d][4],fla=0,b[10000],c[10000],s=0,t=0;
	for(i=0; i<d; i++) 
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		
	for(i=0; i<d; i++) 
		if((a[i][0]+1==a[i][2]||a[i][0]-1==a[i][2])&&a[i][0]<=m&&a[i][2]<=m)	
		b[s++]=a[i][0]>a[i][2]?a[i][2]:a[i][0];
		
	for(i=0; i<d; i++) 
		if((a[i][1]+1==a[i][3]||a[i][1]-1==a[i][3])&&a[i][1]<=n&&a[i][3]<=n)
			c[t++]=a[i][1]>a[i][3]?a[i][3]:a[i][1];

	sort(b, b+s, comp);
	sort(c,c+t,comp);
	int u=b[0];
	cout<<b[0];
	for(i=1;i<s&&i<k;i++){
		
		if(u!=b[i]){
		cout<<" "<<b[i];
		u=b[i];
		}
	}
	cout<<endl;
	int y=c[0];
	cout<<c[0];
	for(i=1;i<t&&i<l;i++){
		if(y==c[i])
		l++;
		if(y!=c[i]){
		cout<<" "<<c[i];
		y=b[i];
		}
	}

}

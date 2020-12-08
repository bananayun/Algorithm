#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 
int main() {
	int m,n,num[205][205];
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>num[i][j];
	int k=m*n;
	for(int i=0;k>0;i++){
		for(int j=i;j<n-i;j++){
			if(k==0)break;
			cout<<num[j][i]<<" ";
			k--;
		}
		for(int j=i+1;j<m-i;j++){
			if(k==0)break;
			cout<<num[n-i-1][j]<<" ";
			k--;
		}
		for(int j=n-i-2;j>=i;j--){
			if(k==0)break;
			cout<<num[j][m-i-1]<<" ";
			k--;
		}
		for(int j=m-i-2;j>i;j--){
			if(k==0)break;
			cout<<num[i][j]<<" ";
			k--;
		}
	}
	return 0;
}


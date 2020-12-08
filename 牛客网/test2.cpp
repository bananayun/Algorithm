#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int vis[10][10];
int che[10][10];
int tot,n;

void search(int cur){
	int i,j;
	if(cur==n){
		tot++;
		return ;
	}
	else for(i=0;i<n;i++){
		if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n] && che[cur][i]){
			che[cur][i]=0;
			vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
			for(j=0;j<n;j++){
				if(!vis[0][j]&&!vis[1][cur+j]&&!vis[2][cur-j+n]&&che[cur][j]){
					vis[0][j]=vis[1][cur+j]=vis[2][cur-j+n]=1;
					break;
					//search(cur+1);
					//is[0][j]=vis[1][cur+j]=vis[2][cur-j+n]=0;
				}
			}
			search(cur+1);
			vis[0][j]=vis[1][cur+j]=vis[2][cur-j+n]=0;
			vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
			che[cur][i]=1;
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)cin>>che[i][j];
	tot=0;
	//memset(vis,0,sizeof(vis));
	search(0);
	cout<<"\nÓÐ£º"<<tot;
	return 0;
}


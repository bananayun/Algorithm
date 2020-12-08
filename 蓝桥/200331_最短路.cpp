#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 20001;
const int MAXL = 200001;
const int INF = INT_MAX;   
int dis[MAXN];
int vis[MAXN];
int head[MAXN];
int M;
queue<int> q;
struct{
	int er;
	int next;
	int value;
}rec[MAXL];
void add(int a,int er,int value){
	rec[M].er=er;
	rec[M].next=head[a];
	rec[M].value=value;
	head[a]=M++;
}
void SPFA(){
	dis[1]=0;vis[1]=1;
	q.push(1);
	while(q.size()){
		int a=q.front();
		q.pop();
		vis[a]=0;
		for(int i=head[a];i!=-1;i=rec[i].next){
			int s=rec[i].er;
			if(dis[s]>dis[a]+rec[i].value){
				dis[s]=dis[a]+rec[i].value;
				if(vis[s]==0){
					vis[s]=1;
					q.push(s);
				}
			}
		}
	}
}
int main(){
	memset(head,-1,sizeof(head));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	SPFA();
	for(int i=2;i<=n;i++)
		cout<<dis[i]<<endl;
	return 0;
}

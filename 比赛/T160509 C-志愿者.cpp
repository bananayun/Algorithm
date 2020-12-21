#include<cstdio>
#include<cmath> 
#include<algorithm>
using namespace std;
struct node{
	int id,t,s;
}vis[10000005];
bool cmp(const node&a,const node&b){
	if(a.s == b.s){
		if(a.t == b.t)return a.id < b.id;
		return a.t>b.t;
	}
	return a.s > b.s;
}
int main(){
	int n,t,k;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d %d",&t,&k);
		vis[i].id = i;
		vis[i].t = t;
		vis[i].s = t*k;
	}
	sort(vis+1,vis+1+n,cmp);
	for(int i=1;i<=n;i++){
		printf("%d%s",vis[i].id,i==n?"\n":" ");
	}
	return 0;
}

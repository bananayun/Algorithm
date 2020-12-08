#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
struct dee{
	int x,y;
}m[maxn];
bool cmp(dee a,dee b){
	if(a.x!=b.x) return a.x<b.x;
	else return a.y<b.y;
} 
int main(){
	int n;
	while(scanf("%d",&n),n!=0){
		for(int i=0;i<n;i++){
			scanf("%d%d",m[i].x,m[i].y);
		}
		sort(m,m+n,cmp);
		int ans=1,last=m[0].x;
		for(int i=1;i<n;i++){
			if(m[i].y<last){
				last=m[i].x;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
} 


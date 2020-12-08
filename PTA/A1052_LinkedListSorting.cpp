#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
	int ad,next,data;
	bool flag;
}node[100010];
bool cmp(Node a,Node b){
	if(a.flag==false||b.flag==false)
	return a.flag>b.flag;
	else
	return a.data<b.data;
}
int main(){
	for(int i=0;i<100010;i++) node[i].flag=false;
	int n,address;
	scanf("%d%d",&n,&address);
	int a,b,c;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a,&b,&c);
		node[a].data=b;
		node[a].next=c;
		node[a].ad=a;
	}
	int count = 0,p=address;
	while(p!=-1){
		node[p].flag=true;
		count++;
		p=node[p].next;
	}
	if(count==0) printf("0 -1");
	else{
		sort(node,node+100010,cmp);
		printf("%d %05d\n",count,node[0].ad);
		for(int i=0;i<count ;i++){
			if(i!=count-1)
			printf("%05d %d %05d\n",node[i].ad,node[i].data,node[i+1].ad);
			else
			printf("%05d %d -1\n",node[i].ad,node[i].data,node[i].next);
		}
	}
	return 0;
}

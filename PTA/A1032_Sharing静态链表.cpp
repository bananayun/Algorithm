#include<cstdio>
struct NODE{
	char data;
	int next;
	bool flag;
}node[100010]; 
int main(){
	for(int i=0;i<100010;i++)
	node[i].flag=false;
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int z,x;
	char w;
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&z,&w,&x);
		node[z].data=w;
		node[z].next=x;	
	}
	int p;
	for(p=a;p!=-1;p=node[p].next)
		node[p].flag=true;
	for(p=b;p!=-1;p=node[p].next)
		if(node[p].flag==true)break;
	if(p!=-1) printf("%05d",p);
	else printf("-1\n");
	return 0;
}

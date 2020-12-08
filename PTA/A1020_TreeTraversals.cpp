#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=50;
struct node{
	node* L;
	node* R;
	int data;
};
int pre[maxn],in[maxn],post[maxn];//先序，中序，后序
int n;//节点个数
node* create(int postL,int postR,int inL,int inR){
	if(postL>postR) return NULL;
	node* root=new node;
	root->data=post[postR];
	int i;
	for(i=inL;i<=inR;i++){
		if(in[i]==post[postR])
			break;
	}
	int numL=i-inL;//左节点个数
	root->L=create(postL,postL+numL-1,inL,i-1);
	root->R=create(postL+numL,postR-1,i+1,inR); 
	return root;
} 
int num=0;//已输出的结点个数
void BFS(node*root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n)printf(" ");
		if(now->L!=NULL)q.push(now->L);
		if(now->R!=NULL)q.push(now->R);
	}
} 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&post[i]);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	node*root=create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}

/*
//先序
void xianxu(node* root){
	if(root==NULL) return;
	printf("%d  ",root->data);
	xianxu(root->zuo);
	xianxu(root->you);
} 
//层序
void cengxu(node* root){
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		printf("%d ",now->data);
		if(now->zuo!=NULL)q.push(now->zuo);
		if(now->you!=NULL)q.push(now->you);
		
		
		
	}
} 
*/

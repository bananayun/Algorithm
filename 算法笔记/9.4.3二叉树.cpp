#include<cstdio>
#include<vector>
using namespace std;
struct node{
	int data;
	node *L,*R;
}; 
void insert(node* &root,int data){
	if(root==NULL){
		root=new node;
		root->data =data;
		root->L=root->R=NULL;
		return;
	}
	if(data<root->data) insert(root->L,data);
	else insert(root->R,data);
}
void apre(node* root,vector<int>&vi){//´¢´æÏÈÐò 
	if(root==NULL)return;
	vi.push_back(root->data);
	apre(root->L,vi);
	apre(root->R,vi);
}
void apreM(node* root,vector<int>&vi){//´¢´æÏÈÐò¾µÏñ 
	if(root==NULL)return;
	vi.push_back(root->data);
	apreM(root->R,vi);
	apreM(root->L,vi);
}
void apost(node*root,vector<int>&vi){//´¢´æºóÐò 
	if(root==NULL)return;
	apost(root->L,vi);
	apost(root->R,vi);
	vi.push_back(root->data);
}
void apostM(node*root,vector<int>&vi){//´¢´æ¾µÏñºóÐò 
	if(root==NULL)return;
	apostM(root->R,vi);
	apostM(root->L,vi);
	vi.push_back(root->data);
} 
vector<int> ori,pre,post,preM,postM;
int main(){
	int n,data;
	node*root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		ori.push_back(data);
		insert(root,data);
	}
	apre(root,pre);
	apreM(root,preM);
	apost(root,post);
	apostM(root,postM);
	if(ori==pre){
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
			if(i<post.size()-1)printf(" ");
		}
	}else if(ori==preM){
		printf("YES\n");
		for(int i=0;i<postM.size();i++){
			printf("%d",postM[i]);
			if(i<postM.size()-1)printf(" ");
		}
	}else{
		printf("NO\n");
	}
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

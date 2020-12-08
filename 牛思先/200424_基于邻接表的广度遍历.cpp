#include<iostream>
#include<cstdlib>
#include<cstring>
#define Max 100
using namespace std;
//邻接点的定义 
typedef struct Node
{
	int v;//下一个点的编号 
	int weight;//权值，有的话 
	Node *next;
}EdgeNode;
//顶点表头结点的定义
typedef struct 
{
	int data;//节点的值
	EdgeNode *to;//边表头指针 
}AdjList[Max]; 
//图结点的定义 
typedef struct 
{
	int n,e;//顶点数、边数
	AdjList adjList; 
}*Graph;
void CreateGraph(Graph G)
{
	EdgeNode *p;
	int n,e,i; 
//	输入顶点数，边数 
	cout<<"输入顶点数、边数：";
	cin>>n>>e;
	G->n = n;
	G->e = e;
	//初始化图
	for(i = 1;i <= n;i++)
		G->adjList[i].to = NULL;
	cout<<"\n输入顶点的值：";
	for(i = 1;i <= n;i++)
		scanf("%d",&(G->adjList[i].data));
	cout<<"\n输入边：\n";
	for(i = 1;i <= e;i++)
	{
		int r,t;
		cin>>r>>t;
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->v = t;
		p->next = G->adjList[r].to;
		G->adjList[r].to = p;
		//有向图则省略 
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->v = r;
		p->next = G->adjList[t].to;
		G->adjList[t].to = p;
	}
}
void BFS(Graph G)
{
	int vis[Max];//表示各顶点是否访问过 
	memset(vis,0,sizeof(vis));//0表示没有访问过
	int que[Max*2],L = 0,R = -1;//队列，队头，队尾
	que[++R] = 1;//入队 
	vis[1] = 1;//1表示访问过 
	while(L <= R)
	{
		int k =que[L++];//出队
		cout<<G->adjList[k].data<<" ";
		EdgeNode *p = G->adjList[k].to;
		while(p && vis[p->v] == 0)
		{
			que[++R] = p->v;//入队 
			vis[p->v] = 1;//访问过 
			p = p->next;
		}
	}
}
int main()
{
	Graph G;
	G = (Graph)malloc(sizeof(Graph));
	CreateGraph(G);
	BFS(G);
}


#include<cstdio>
#include<iostream>
#include<cstdlib>
#define MAX 100 
using namespace std;
typedef int DataType;
/***********邻接矩阵************/
typedef struct
{
	int n,e;//顶点数、边数
	DataType ege[MAX][MAX];//矩阵 
}MGraph;
/************邻接表*************/
//邻接点的定义 
typedef struct ANode
{
	int v;//下一点的编号 
	int weight;//权值，有的话
	ANode *next; 
}ArcNode;
//顶点表头的定义
typedef struct
{
	int data;//节点的值
	ArcNode *to;//表头指针 
}AdjList;
//图的定义
typedef struct
{
	int n,e;
	AdjList adjList[MAX];
}Graph;
/************创建图************/
//邻接矩阵 
void CreateMGraph(MGraph &G,int a[MAX][MAX],int n,int e)
{
	G.n = n;
	G.e = e;
	for(int i = 0;i < G.n;i++)
		for(int j = 0;j < G.n;j++)
			G.ege[i][j] = a[i][j];
}
//邻接表 
void CreateGraph(Graph *&G,int a[MAX][MAX],int n,int e)
{
	ArcNode *p;
	//初始化Graph 
	G = (Graph *)malloc(sizeof(Graph));
	for(int i = 0;i < n;i++)
		G->adjList[i].to = NULL;
	for(int i = 0;i < n;i++)
		for(int j = n-1;j > -1;j--)
		{
			if(a[i][j])
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));//创建一个节点p 
				p->v = j;
				p->weight = a[i][j];
				p->next = G->adjList[i].to;//头插法 
				G->adjList[i].to = p;
			}
		}
	G->n = n;
	G->e = e;
}
/*************输出图*************/ 
//邻接矩阵 
void DispMap(MGraph G) 
{
	for(int i = 0;i < G.n;i++)
	{
		cout<<"\t["<<i<<"]: ";
		for(int j = 0; j < G.n;j++)
			cout<<G.ege[i][j]<<" ";
		cout<<endl;
	}
}
//邻接表 
void DispAdj(Graph *G)
{
	ArcNode *p;
	for(int i = 0;i < G->n;i++)
	{
		p = G->adjList[i].to;
		cout<<"\t"<<i<<": ";
		while(p)
		{
			printf("%d[%d]→",p->v,p->weight);
			p = p->next;
			if(!p)cout<<"^";
		}
		cout<<endl;
	}
}
/**********DFS遍历*********/
 //DFS深度优先遍历算法 
//1.递归算法 
int visited[MAX]={0}; 
void DFS(Graph *G,int v)
{
	ArcNode *p;//int w;
	visited[v]=1;	//置已访问标记
	printf("%3d",v);		//输出被访问顶点的编号
	p=G->adjList[v].to;//p指向顶点v的第一条边的边头结点
	
	while(p!=NULL)
	{
		//w=p->adjvex;
		if(visited[p->v]==0)
			DFS(G,p->v);	//若p->adjvex顶点未访问，递归访问它
		p=p->next;	//p指向顶点v的下一条边的边头结点 
	 } 
	 
}
//2.非递归算法
void DFS1(Graph *G,int v)
{
	ArcNode *p;
	int St[MAX];
	int top=-1;	//定义顺序栈
	int w,x,i;
	for(i=0;i<G->n;i++)
		visited[i]=0;	//访问标志置0，没有访问过
	printf("%d",v) ;
	visited[v]=1;	//访问起点，访问标志置1
	top++;
	St[top]=v;	//起点入栈
	while(top>-1)//栈非空
	{
		x=St[top];//取栈顶元素
		p=G->adjList[x].to;	//指向栈顶元素的首邻接点（单链表）
		while(p)
		{
			w=p->v;
			if(visited[w]==0)
			{
				printf("%3d",w);
				visited[w]=1;
				top++;
				St[top]=w;
				break;
			}
			p=p->next;
		 } 
		 if(!p)
		 	top--; 
	 } 
	 printf("\n");
 } 
void BFS(Graph *G,int v)
{
	int w,i,vis[MAX],top = -1;;
	ArcNode *p;
	int visited[MAX];	//定义顶点访问标志数组 
	for(i=0;i<G->n;i++)
		visited[i]=0;	//访问标志数组初始化 
	printf("%2d",v);	//输出被访问顶点的编号
	visited[v]=1;		//置已访问标记 
	vis[++top] = v; 
	while(top!=-1)	//队不空循环
	{
		w = vis[top--];
		p=G->adjList[w].to;		//指向w的第一个邻接点 
		while(p)		//查找w的所有邻接点 
		{
			if(visited[p->v]==0)		//若当前邻接点未被访问
			{
				printf("%2d",p->v);	//访问该邻接点
				visited[p->v]=1;		//置已访问标记
				vis[++top] = p->v;		//该顶点进队 
			 } 
			 p=p->next;		//找下一个邻接点 
		}
	 } 
	 printf("\n"); 
}
bool Connect(Graph *G)	//判断无向图G的连通性
{
	int i;
	bool flag=true;
	for(i=0;i<G->n;i++)	//isited数组置初值
		visited[i]=0;
	//DFS(G,0);		//调用前面的中DFS算法，从顶点0开始 深度优先遍历
	for(i=0;i<G->n;i++)
		if(visited[i]==0)
		{
			flag=false;
			break;
		 } 
	return flag;
 } 
int main()
{
	cout<<"1、创建图";
	MGraph mg;
	Graph *g;
	int A[MAX][MAX]={{0,1,0,1,1},{1,0,1,1,0},
						{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5,e=8;
	CreateMGraph(mg,A,n,e);
	CreateGraph(g,A,n,e);
	cout<<"\n\n2、输出图";
	cout<<"\n\t   (邻接矩阵)\n";
	DispMap(mg); 
	cout<<"\n\t   (邻接表)\n";
	DispAdj(g);
	
	cout<<"\n\n3、DFS遍历\n\t(递归) ";
	DFS(g,0);
	cout<<"\n\t(非递归）";
	DFS1(g,0);
	
	cout<<"\n\n4、BFS遍历：";
	BFS(g,0); 
	
	cout<<"\n\n5、判断是否连通："<<(Connect(g)?"否":"是"); 
}

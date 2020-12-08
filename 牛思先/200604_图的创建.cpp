#include<cstdio>
#include<iostream>
#include<cstdlib>
#define MAX 100 
using namespace std;
typedef int DataType;
/***********�ڽӾ���************/
typedef struct
{
	int n,e;//������������
	DataType ege[MAX][MAX];//���� 
}MGraph;
/************�ڽӱ�*************/
//�ڽӵ�Ķ��� 
typedef struct ANode
{
	int v;//��һ��ı�� 
	int weight;//Ȩֵ���еĻ�
	ANode *next; 
}ArcNode;
//�����ͷ�Ķ���
typedef struct
{
	int data;//�ڵ��ֵ
	ArcNode *to;//��ͷָ�� 
}AdjList;
//ͼ�Ķ���
typedef struct
{
	int n,e;
	AdjList adjList[MAX];
}Graph;
/************����ͼ************/
//�ڽӾ��� 
void CreateMGraph(MGraph &G,int a[MAX][MAX],int n,int e)
{
	G.n = n;
	G.e = e;
	for(int i = 0;i < G.n;i++)
		for(int j = 0;j < G.n;j++)
			G.ege[i][j] = a[i][j];
}
//�ڽӱ� 
void CreateGraph(Graph *&G,int a[MAX][MAX],int n,int e)
{
	ArcNode *p;
	//��ʼ��Graph 
	G = (Graph *)malloc(sizeof(Graph));
	for(int i = 0;i < n;i++)
		G->adjList[i].to = NULL;
	for(int i = 0;i < n;i++)
		for(int j = n-1;j > -1;j--)
		{
			if(a[i][j])
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));//����һ���ڵ�p 
				p->v = j;
				p->weight = a[i][j];
				p->next = G->adjList[i].to;//ͷ�巨 
				G->adjList[i].to = p;
			}
		}
	G->n = n;
	G->e = e;
}
/*************���ͼ*************/ 
//�ڽӾ��� 
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
//�ڽӱ� 
void DispAdj(Graph *G)
{
	ArcNode *p;
	for(int i = 0;i < G->n;i++)
	{
		p = G->adjList[i].to;
		cout<<"\t"<<i<<": ";
		while(p)
		{
			printf("%d[%d]��",p->v,p->weight);
			p = p->next;
			if(!p)cout<<"^";
		}
		cout<<endl;
	}
}
/**********DFS����*********/
 //DFS������ȱ����㷨 
//1.�ݹ��㷨 
int visited[MAX]={0}; 
void DFS(Graph *G,int v)
{
	ArcNode *p;//int w;
	visited[v]=1;	//���ѷ��ʱ��
	printf("%3d",v);		//��������ʶ���ı��
	p=G->adjList[v].to;//pָ�򶥵�v�ĵ�һ���ߵı�ͷ���
	
	while(p!=NULL)
	{
		//w=p->adjvex;
		if(visited[p->v]==0)
			DFS(G,p->v);	//��p->adjvex����δ���ʣ��ݹ������
		p=p->next;	//pָ�򶥵�v����һ���ߵı�ͷ��� 
	 } 
	 
}
//2.�ǵݹ��㷨
void DFS1(Graph *G,int v)
{
	ArcNode *p;
	int St[MAX];
	int top=-1;	//����˳��ջ
	int w,x,i;
	for(i=0;i<G->n;i++)
		visited[i]=0;	//���ʱ�־��0��û�з��ʹ�
	printf("%d",v) ;
	visited[v]=1;	//������㣬���ʱ�־��1
	top++;
	St[top]=v;	//�����ջ
	while(top>-1)//ջ�ǿ�
	{
		x=St[top];//ȡջ��Ԫ��
		p=G->adjList[x].to;	//ָ��ջ��Ԫ�ص����ڽӵ㣨������
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
	int visited[MAX];	//���嶥����ʱ�־���� 
	for(i=0;i<G->n;i++)
		visited[i]=0;	//���ʱ�־�����ʼ�� 
	printf("%2d",v);	//��������ʶ���ı��
	visited[v]=1;		//���ѷ��ʱ�� 
	vis[++top] = v; 
	while(top!=-1)	//�Ӳ���ѭ��
	{
		w = vis[top--];
		p=G->adjList[w].to;		//ָ��w�ĵ�һ���ڽӵ� 
		while(p)		//����w�������ڽӵ� 
		{
			if(visited[p->v]==0)		//����ǰ�ڽӵ�δ������
			{
				printf("%2d",p->v);	//���ʸ��ڽӵ�
				visited[p->v]=1;		//���ѷ��ʱ��
				vis[++top] = p->v;		//�ö������ 
			 } 
			 p=p->next;		//����һ���ڽӵ� 
		}
	 } 
	 printf("\n"); 
}
bool Connect(Graph *G)	//�ж�����ͼG����ͨ��
{
	int i;
	bool flag=true;
	for(i=0;i<G->n;i++)	//isited�����ó�ֵ
		visited[i]=0;
	//DFS(G,0);		//����ǰ�����DFS�㷨���Ӷ���0��ʼ ������ȱ���
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
	cout<<"1������ͼ";
	MGraph mg;
	Graph *g;
	int A[MAX][MAX]={{0,1,0,1,1},{1,0,1,1,0},
						{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int n=5,e=8;
	CreateMGraph(mg,A,n,e);
	CreateGraph(g,A,n,e);
	cout<<"\n\n2�����ͼ";
	cout<<"\n\t   (�ڽӾ���)\n";
	DispMap(mg); 
	cout<<"\n\t   (�ڽӱ�)\n";
	DispAdj(g);
	
	cout<<"\n\n3��DFS����\n\t(�ݹ�) ";
	DFS(g,0);
	cout<<"\n\t(�ǵݹ飩";
	DFS1(g,0);
	
	cout<<"\n\n4��BFS������";
	BFS(g,0); 
	
	cout<<"\n\n5���ж��Ƿ���ͨ��"<<(Connect(g)?"��":"��"); 
}

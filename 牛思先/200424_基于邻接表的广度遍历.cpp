#include<iostream>
#include<cstdlib>
#include<cstring>
#define Max 100
using namespace std;
//�ڽӵ�Ķ��� 
typedef struct Node
{
	int v;//��һ����ı�� 
	int weight;//Ȩֵ���еĻ� 
	Node *next;
}EdgeNode;
//�����ͷ���Ķ���
typedef struct 
{
	int data;//�ڵ��ֵ
	EdgeNode *to;//�߱�ͷָ�� 
}AdjList[Max]; 
//ͼ���Ķ��� 
typedef struct 
{
	int n,e;//������������
	AdjList adjList; 
}*Graph;
void CreateGraph(Graph G)
{
	EdgeNode *p;
	int n,e,i; 
//	���붥���������� 
	cout<<"���붥������������";
	cin>>n>>e;
	G->n = n;
	G->e = e;
	//��ʼ��ͼ
	for(i = 1;i <= n;i++)
		G->adjList[i].to = NULL;
	cout<<"\n���붥���ֵ��";
	for(i = 1;i <= n;i++)
		scanf("%d",&(G->adjList[i].data));
	cout<<"\n����ߣ�\n";
	for(i = 1;i <= e;i++)
	{
		int r,t;
		cin>>r>>t;
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->v = t;
		p->next = G->adjList[r].to;
		G->adjList[r].to = p;
		//����ͼ��ʡ�� 
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->v = r;
		p->next = G->adjList[t].to;
		G->adjList[t].to = p;
	}
}
void BFS(Graph G)
{
	int vis[Max];//��ʾ�������Ƿ���ʹ� 
	memset(vis,0,sizeof(vis));//0��ʾû�з��ʹ�
	int que[Max*2],L = 0,R = -1;//���У���ͷ����β
	que[++R] = 1;//��� 
	vis[1] = 1;//1��ʾ���ʹ� 
	while(L <= R)
	{
		int k =que[L++];//����
		cout<<G->adjList[k].data<<" ";
		EdgeNode *p = G->adjList[k].to;
		while(p && vis[p->v] == 0)
		{
			que[++R] = p->v;//��� 
			vis[p->v] = 1;//���ʹ� 
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


#include<iostream>
#include<cstdlib>
#define MAX 50
#define INF 32767
using namespace std;
typedef  int DataType;
typedef struct
{
	DataType data[MAX][MAX];
	int n,e;//������������ 
}Graph;
typedef struct 
{
	int u;     	//�ߵ���ʼ����
	int v;     	//�ߵ���ֹ����
	int w;   	//�ߵ�Ȩֵ
}Edge; 

//����ͼ 
void Create(Graph &G,DataType a[MAX][MAX],int n,int e)
{
	G.n = n;
	G.e = e;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			G.data[i][j] = a[i][j];
}
//�����ͼ
void DispGraph(Graph G)
{
	for(int i = 0;i < G.n;i++)
	{
		for(int j = 0;j < G.n;j++)
		if(G.data[i][j] != INF)
			cout<<"   "<<G.data[i][j];
		else cout<<"   "<<"*";
		cout<<endl<<endl;
	}
}
//��С������
void Prim(Graph g,int v)
{
	int lowcost[MAX];
	int min;
	int closest[MAX],i,j,k;
	for (i=0;i<g.n;i++)	//��lowcost[]��closest[]�ó�ֵ
	{	
		lowcost[i]=g.data[v][i];
		closest[i]=v;
	}
	for (i=1;i<g.n;i++)	  	//���(n-1)����
	{
		min=INF;
		for(j=0;j<g.n;j++) 	//��(V-U)���ҳ���U����Ķ���k
			if(lowcost[j]!=0 && lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;			//k��¼���������
			}
		printf(" ��(%d��%d)ȨΪ:%d\n",closest[k],k,min);
    	lowcost[k]=0;		//���k�Ѿ�����U
		for (j=0;j<g.n;j++)  //�޸�����lowcost��closest
    		if(lowcost[j]!=0 && g.data[k][j]<lowcost[j])
    		{
				lowcost[j]=g.data[k][j];
    			closest[j]=k;
    		}
	}
}
//��³˹������Kruskal���㷨
void Kruskal(Graph g)
{
	int i,j,u1,v1,sn1,sn2,k;
	int vset[MAX];
	Edge E[MAX];		//������б�
	k=0;				//E������±��0��ʼ��
	for (i=0;i<g.n;i++)	//��g�����ı߼�E
		for (j=0;j<g.n;j++)
        	if (g.data[i][j]!=0 && g.data[i][j]!=INF)
			{
				E[k].u=i;
				E[k].v=j;
				E[k].w=g.data[i][j];
	    		k++;
			}
	//InsertSort(E,g.e);		//��ֱ�Ӳ��������E���鰴Ȩֵ��������
	
    for(int i=0;i<g.e-1;++i)
        for(int j=0;j<g.e-1-i;++j)
            if(E[j].w > E[j+1].w)
            {
            	int t = E[j].w;
            	E[j].w = E[j+1].w;
            	E[j+1].w = t;
			}

	for (i=0;i<g.n;i++) 	//��ʼ����������
		vset[i]=i;
	k=1;				//k��ʾ��ǰ�����������ĵڼ�����
  	j=0;				//E�бߵ��±꣬��ֵΪ0
	while (k<g.n)		//���ɵı���С��nʱѭ��
	{
    	u1=E[j].u;v1=E[j].v;	//ȡһ���ߵ�ͷβ����
     	sn1=vset[u1];
     	sn2=vset[v1];		//�ֱ�õ��������������ļ��ϱ��
    	if(sn1!=sn2)  		//���������ڲ�ͬ�ļ���
    	{
			printf("  (%d��%d):%d\n",u1,v1,E[j].w);
        	k++;		   	//���ɱ�����1
        	for(i=0;i<g.n;i++)  	//��������ͳһ���
           		if(vset[i]==sn2) 	//���ϱ��Ϊsn2�ĸ�Ϊsn1
					vset[i]=sn1;
     	}
    	j++;			//ɨ����һ����
  	}
}

void Dispath(Graph g,int dist[],int path[],int S[],int v)
//����Ӷ���v�������������·��
{
	int i,j,k;
	int apath[MAX],d;     //���һ�����·�������򣩼��䶥����� 
	for(i=0;i<g.n;i++)     //ѭ������Ӷ���v��i��·�� 
	    if(S[i]==1 && i!=v)
	    {
	    	printf( "�Ӷ���%d������%d��·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);
	    	d=0;apath[d]=i;//���·���ϵ��յ� 
	    	k=path[i];
	    	if(k==-1)//û��·������� 
	    	   printf("��·��\n");
	    	else    //����·��ʱ�����·�� 
	    	{
	    		while(k!=v)
	    		{
	    			d++;apath[d]=k;
	    			k=path[k];
				}
				d++;apath[d]=v;         //���·���ϵ���� 
				printf("%d",apath[d]);  //�������� 
				for(j=d-1;j>=0;j--)     //������������� 
				    printf(",%d",apath[j]);
				printf("\n");
			}
		}
 } 
//�Ͽ�˹���㷨
void Dijkstra(Graph g,int v)
{  
	int dist[MAX],path[MAX],s[MAX];
	int mindis,i,j,u;
   	for (i=0;i<g.n;i++)
   	{   
	   	dist[i]=g.data[v][i];	 //�����ʼ��
		s[i]=0;			 //s[]�ÿ�
		if(g.data[v][i]<INF) //·����ʼ��
			path[i]=v;		 //����v��i�б�ʱ
		else
	   		path[i]=-1;		 //����v��iû��ʱ
   }
   	s[v]=1;	 		 //Դ��v����S��
	for (i=0;i<g.n;i++)	 	//ѭ��n-1��
   	{  
		mindis=INF;
      	for(j=0;j<g.n;j++)
	 		if(s[j]==0 && dist[j]<mindis) 
	 		{  
			 	u=j;
	    		mindis=dist[j];
	 		}
      	s[u]=1;				//����u����S��
      	for(j=0;j<g.n;j++)		//�޸Ĳ���s�еĶ���ľ���
         	if (s[j]==0)
	    		if(g.data[u][j]<INF && dist[u]+g.data[u][j]<dist[j])
           		{  
					dist[j]=dist[u]+g.data[u][j];
	       			path[j]=u;
	    		}
  	}
  	Dispath(g,dist,path,s,v);		//������·��
}
//Floyd
void Dispath(Graph g,int A[][MAX],int path[][MAX])
{
	int i,j,k,s;
	int apath[MAX],d;
	for(i=0;i<g.n;i++)
	    for(j=0;j<g.n;j++)
	    {
	    	if(A[i][j]!=INF && i!=j)
	    	{
	    		printf("  ��%d��%d��·��Ϊ:",i,j);
	    		k=path[i][j];
	    		d=0;apath[d]=j;
	    		while(k!=-1 && k!=i)
	    		{
	    			d++;apath[d]=k;
	    			k=path[i][k];
				}
				d++;apath[d]=i;
				printf("%d",apath[d]);
				for(s=d-1;s>=0;s--)
				    printf(",%d",apath[s]);
				printf("\t·������Ϊ:%d\n",A[i][j]);
			}
		}
}

void Floyd(Graph g)
{
	int A[MAX][MAX],path[MAX][MAX];
	int i,j,k;
	for(i=0;i<g.n;i++)
	    for(j=0;j<g.n;j++)
	    {
	    	A[i][j]=g.data[i][j];
	    	if(i!=j && g.data[i][j]<INF)
	    	   path[i][j]=i;
	        else
	           path[i][j]=-1;
		}
	for(k=0;k<g.n;k++)
	{
		for(i=0;i<g.n;i++)
		    for(j=0;j<g.n;j++)
		        if(A[i][j]>A[i][k]+A[k][j])
		        {
		        	A[i][j]=A[i][k]+A[k][j];
		        	path[i][j]=path[k][j];
				}
	}
	Dispath(g,A,path);
}



int main()
{
	Graph G;
	int a[MAX][MAX] = {{0,1,0,1,1},{1,0,1,1,0},
				{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
	int A[MAX] [MAX]={
    {0,28,INF,INF,INF,10,INF},
    {28,0,16,INF,INF,INF,14},
    {INF,16,0,12,INF,INF,INF},
    {INF,INF,12,0,22,INF,18},
    {INF,INF,INF,22,0,25,24},
    {10,INF,INF,INF,25,0,INF},
    {INF,14,INF,18,24,INF,0}};

	//����ͼ
	cout<<"1������ͼ";
	//Create(G,a,5,8);
	Create(G,A,7,9);
	//���ͼ 
	cout<<"\n\n2�����ͼ\n";
	DispGraph(G);
	
	//�����ͼ����С������ 
	cout<<"\n\n3����С������\n";
	cout<<"\n\tPrim�㷨��\n";
	Prim(G,0);
	cout<<"\tKruskal�㷨��\n"; 
	Kruskal(G);
	
	//5�����ͼ�ĵ�Դ���·����dijkstra�� 
	cout<<"\n\n5�����ͼ�ĵ�Դ���·����dijkstra��\n";
	Dijkstra(G,0);
	
	cout<<"\n\n6��������Ե����·��:\n";
	Floyd(G);

}

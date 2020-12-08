#include<iostream>
#include<cstdlib>
#define MAX 50
#define INF 32767
using namespace std;
typedef  int DataType;
typedef struct
{
	DataType data[MAX][MAX];
	int n,e;//顶点数、边数 
}Graph;
typedef struct 
{
	int u;     	//边的起始顶点
	int v;     	//边的终止顶点
	int w;   	//边的权值
}Edge; 

//创建图 
void Create(Graph &G,DataType a[MAX][MAX],int n,int e)
{
	G.n = n;
	G.e = e;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			G.data[i][j] = a[i][j];
}
//输出该图
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
//最小生成树
void Prim(Graph g,int v)
{
	int lowcost[MAX];
	int min;
	int closest[MAX],i,j,k;
	for (i=0;i<g.n;i++)	//给lowcost[]和closest[]置初值
	{	
		lowcost[i]=g.data[v][i];
		closest[i]=v;
	}
	for (i=1;i<g.n;i++)	  	//输出(n-1)条边
	{
		min=INF;
		for(j=0;j<g.n;j++) 	//在(V-U)中找出离U最近的顶点k
			if(lowcost[j]!=0 && lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;			//k记录最近顶点编号
			}
		printf(" 边(%d，%d)权为:%d\n",closest[k],k,min);
    	lowcost[k]=0;		//标记k已经加入U
		for (j=0;j<g.n;j++)  //修改数组lowcost和closest
    		if(lowcost[j]!=0 && g.data[k][j]<lowcost[j])
    		{
				lowcost[j]=g.data[k][j];
    			closest[j]=k;
    		}
	}
}
//克鲁斯卡尔（Kruskal）算法
void Kruskal(Graph g)
{
	int i,j,u1,v1,sn1,sn2,k;
	int vset[MAX];
	Edge E[MAX];		//存放所有边
	k=0;				//E数组的下标从0开始计
	for (i=0;i<g.n;i++)	//由g产生的边集E
		for (j=0;j<g.n;j++)
        	if (g.data[i][j]!=0 && g.data[i][j]!=INF)
			{
				E[k].u=i;
				E[k].v=j;
				E[k].w=g.data[i][j];
	    		k++;
			}
	//InsertSort(E,g.e);		//用直接插入排序对E数组按权值递增排序
	
    for(int i=0;i<g.e-1;++i)
        for(int j=0;j<g.e-1-i;++j)
            if(E[j].w > E[j+1].w)
            {
            	int t = E[j].w;
            	E[j].w = E[j+1].w;
            	E[j+1].w = t;
			}

	for (i=0;i<g.n;i++) 	//初始化辅助数组
		vset[i]=i;
	k=1;				//k表示当前构造生成树的第几条边
  	j=0;				//E中边的下标，初值为0
	while (k<g.n)		//生成的边数小于n时循环
	{
    	u1=E[j].u;v1=E[j].v;	//取一条边的头尾顶点
     	sn1=vset[u1];
     	sn2=vset[v1];		//分别得到两个顶点所属的集合编号
    	if(sn1!=sn2)  		//两顶点属于不同的集合
    	{
			printf("  (%d，%d):%d\n",u1,v1,E[j].w);
        	k++;		   	//生成边数增1
        	for(i=0;i<g.n;i++)  	//两个集合统一编号
           		if(vset[i]==sn2) 	//集合编号为sn2的改为sn1
					vset[i]=sn1;
     	}
    	j++;			//扫描下一条边
  	}
}

void Dispath(Graph g,int dist[],int path[],int S[],int v)
//输出从顶点v出发的所有最短路径
{
	int i,j,k;
	int apath[MAX],d;     //存放一条最短路径（逆向）及其顶点个数 
	for(i=0;i<g.n;i++)     //循环输出从顶点v到i的路径 
	    if(S[i]==1 && i!=v)
	    {
	    	printf( "从顶点%d到顶点%d的路径长度为:%d\t路径为:",v,i,dist[i]);
	    	d=0;apath[d]=i;//添加路径上的终点 
	    	k=path[i];
	    	if(k==-1)//没有路径的情况 
	    	   printf("无路径\n");
	    	else    //存在路径时输出该路径 
	    	{
	    		while(k!=v)
	    		{
	    			d++;apath[d]=k;
	    			k=path[k];
				}
				d++;apath[d]=v;         //添加路径上的起点 
				printf("%d",apath[d]);  //先输出起点 
				for(j=d-1;j>=0;j--)     //在输出其他顶点 
				    printf(",%d",apath[j]);
				printf("\n");
			}
		}
 } 
//迪克斯拉算法
void Dijkstra(Graph g,int v)
{  
	int dist[MAX],path[MAX],s[MAX];
	int mindis,i,j,u;
   	for (i=0;i<g.n;i++)
   	{   
	   	dist[i]=g.data[v][i];	 //距离初始化
		s[i]=0;			 //s[]置空
		if(g.data[v][i]<INF) //路径初始化
			path[i]=v;		 //顶点v到i有边时
		else
	   		path[i]=-1;		 //顶点v到i没边时
   }
   	s[v]=1;	 		 //源点v放入S中
	for (i=0;i<g.n;i++)	 	//循环n-1次
   	{  
		mindis=INF;
      	for(j=0;j<g.n;j++)
	 		if(s[j]==0 && dist[j]<mindis) 
	 		{  
			 	u=j;
	    		mindis=dist[j];
	 		}
      	s[u]=1;				//顶点u加入S中
      	for(j=0;j<g.n;j++)		//修改不在s中的顶点的距离
         	if (s[j]==0)
	    		if(g.data[u][j]<INF && dist[u]+g.data[u][j]<dist[j])
           		{  
					dist[j]=dist[u]+g.data[u][j];
	       			path[j]=u;
	    		}
  	}
  	Dispath(g,dist,path,s,v);		//输出最短路径
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
	    		printf("  从%d到%d的路径为:",i,j);
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
				printf("\t路径长度为:%d\n",A[i][j]);
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

	//创建图
	cout<<"1、创建图";
	//Create(G,a,5,8);
	Create(G,A,7,9);
	//输出图 
	cout<<"\n\n2、输出图\n";
	DispGraph(G);
	
	//输出该图的最小生成树 
	cout<<"\n\n3、最小生成树\n";
	cout<<"\n\tPrim算法：\n";
	Prim(G,0);
	cout<<"\tKruskal算法：\n"; 
	Kruskal(G);
	
	//5、输出图的单源最短路径（dijkstra） 
	cout<<"\n\n5、输出图的单源最短路径（dijkstra）\n";
	Dijkstra(G,0);
	
	cout<<"\n\n6、各顶点对的最短路径:\n";
	Floyd(G);

}

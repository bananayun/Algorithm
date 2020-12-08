#include<iostream>
#include<cstdio>
using namespace std;
typedef char DataType; 
typedef struct Node
{
	int flag;//标记是原子还是子表
	union
	{
		DataType data;//原子的值 
		Node *List;//子表首地址 
	}val;
	Node *next;
}GLNode;

//初始化广义表
void InitGLNode(GLNode *&g)
{
	g = (GLNode*)malloc(sizeof(GLNode));
	g->next = NULL;
	g->val.List = NULL;
}
//广义表的长度 
int GLNodeLength(GLNode *g) 
{
	int length = 0;
	GLNode *p = g->val.List;
	while(p != NULL)
	{
		length++;
		p = p->next;
	}
	return length;
}
//广义表的深度
int GLNodeDepth(GLNode *g) 
{
	int depth,max = 0;
	GLNode *p = g->val.List;
	if(g->flag == 0)return 0;//是原子返回0
	if(p == NULL)return 1;//是空表返回1 
	while(p != NULL)
	{
		if(p->flag == 1)
		{
			depth = GLNodeDepth(p);
			max = max>depth ? max:depth;
		}
		p = p->next;
	}
	return max+1;
}
//最大原子 
DataType  MaxGLNode(GLNode *g)
{
	DataType max = '#';
	GLNode *p = g->val.List;
	while(p != NULL)
	{
		if(p->flag == 1)//子表 
			max = max>MaxGLNode(p) ? max:MaxGLNode(p);
		else max = max>p->val.data ? max:p->val.data;
		p = p->next;
	}
	return max;
}
//广义表原子个数 
int GLNodeCount(GLNode *g)
{
	int count = 0;
	GLNode *p = g->val.List;
	while(p != NULL)
	{
		if(p->flag == 1)//子表 
			count += GLNodeCount(p);
		else count++;
		p = p->next;
	}
	return count;
}
//建立广义表 
GLNode* CreateGLNode(char *&s)
{
	GLNode *g;
	char c = *s++;
	if(c != '\0')
	{
		g = (GLNode*)malloc(sizeof(GLNode));
		if(c == '(')
		{
			g->flag = 1;
			g->val.List = CreateGLNode(s);
		}
		else if(c == '#') g = NULL;
		else
		{
			g->flag = 0;
			g->val.data = c;
		}
	}
	else g = NULL;
	c = *s++;
	if(g != NULL)
	{
		if(c == ',')
			g->next = CreateGLNode(s);
		else g->next = NULL;
	}
	return g;
}
//输出广义表
void OutGLNode(GLNode *g)
{
	if (g!=NULL )
	{
		if (g->flag == 0)
			cout<<g->val.data;
		else
		{ 
			cout<<"(";
			if (g->val.List == NULL)
				cout<<'#';
			else
				OutGLNode(g->val.List);
			cout<<')';
		}
		if (g->next != NULL)
		{
			cout<<',';
			OutGLNode(g->next);
		}
	}
}
//销毁广义表
void Destroy(GLNode *&g)
{
	GLNode *p,*q;
	p = g->val.List;
	while(p)
	{
		if(p->flag == 0)
		{
			q = p->next;
			free(p);
			p = q;
		}
		else
		{
			q = p->next;
			Destroy(p);
			p = q;
		}
	}
	free(g);
}
int main()
{
	GLNode *g;
	char *c = "(b,(b,a,(#),d),((a,b),c,((#))))";
	//初始化广义表
	cout<<"初始化广义表"; 
	InitGLNode(g); 
	//1. 建立广义表g="(b,(b,a,(#),d),((a,b),c,((#))))"的链式存储结构
	cout<<"\n\n1. 建立广义表g=\"(b,(b,a,(#),d),((a,b),c,((#))))\"的链式存储结构";
	g = CreateGLNode(c);
	
	//2. 输出广义表
	cout<<"\n\n2. 输出广义表："; 
	OutGLNode(g);

	//3. 输出广义表G的长度；
	cout<<"\n\n3. 输出广义表G的长度；"<<GLNodeLength(g);
	
	//4. 输出广义表g的深度；
	cout<<"\n\n4. 输出广义表g的深度；"<<GLNodeDepth(g);
	
	//5. 输出广义表g的最大原子；
	cout<<"\n\n5. 输出广义表g的最大原子；"<<MaxGLNode(g);
	
	//6. 输出广义表g的原子个数；
	cout<<"\n\n6. 输出广义表g的原子个数；"<<GLNodeCount(g);
	
	//7. 销毁广义表
	cout<<"\n\n7. 销毁链表";
	Destroy(g);
	return 0;
}

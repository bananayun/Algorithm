#include<iostream>
#include<cstdio>
using namespace std;
typedef char DataType; 
typedef struct Node
{
	int flag;//�����ԭ�ӻ����ӱ�
	union
	{
		DataType data;//ԭ�ӵ�ֵ 
		Node *List;//�ӱ��׵�ַ 
	}val;
	Node *next;
}GLNode;

//��ʼ�������
void InitGLNode(GLNode *&g)
{
	g = (GLNode*)malloc(sizeof(GLNode));
	g->next = NULL;
	g->val.List = NULL;
}
//�����ĳ��� 
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
//���������
int GLNodeDepth(GLNode *g) 
{
	int depth,max = 0;
	GLNode *p = g->val.List;
	if(g->flag == 0)return 0;//��ԭ�ӷ���0
	if(p == NULL)return 1;//�ǿձ���1 
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
//���ԭ�� 
DataType  MaxGLNode(GLNode *g)
{
	DataType max = '#';
	GLNode *p = g->val.List;
	while(p != NULL)
	{
		if(p->flag == 1)//�ӱ� 
			max = max>MaxGLNode(p) ? max:MaxGLNode(p);
		else max = max>p->val.data ? max:p->val.data;
		p = p->next;
	}
	return max;
}
//�����ԭ�Ӹ��� 
int GLNodeCount(GLNode *g)
{
	int count = 0;
	GLNode *p = g->val.List;
	while(p != NULL)
	{
		if(p->flag == 1)//�ӱ� 
			count += GLNodeCount(p);
		else count++;
		p = p->next;
	}
	return count;
}
//��������� 
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
//��������
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
//���ٹ����
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
	//��ʼ�������
	cout<<"��ʼ�������"; 
	InitGLNode(g); 
	//1. ���������g="(b,(b,a,(#),d),((a,b),c,((#))))"����ʽ�洢�ṹ
	cout<<"\n\n1. ���������g=\"(b,(b,a,(#),d),((a,b),c,((#))))\"����ʽ�洢�ṹ";
	g = CreateGLNode(c);
	
	//2. ��������
	cout<<"\n\n2. ��������"; 
	OutGLNode(g);

	//3. ��������G�ĳ��ȣ�
	cout<<"\n\n3. ��������G�ĳ��ȣ�"<<GLNodeLength(g);
	
	//4. ��������g����ȣ�
	cout<<"\n\n4. ��������g����ȣ�"<<GLNodeDepth(g);
	
	//5. ��������g�����ԭ�ӣ�
	cout<<"\n\n5. ��������g�����ԭ�ӣ�"<<MaxGLNode(g);
	
	//6. ��������g��ԭ�Ӹ�����
	cout<<"\n\n6. ��������g��ԭ�Ӹ�����"<<GLNodeCount(g);
	
	//7. ���ٹ����
	cout<<"\n\n7. ��������";
	Destroy(g);
	return 0;
}

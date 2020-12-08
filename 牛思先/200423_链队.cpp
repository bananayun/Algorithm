#include<iostream>
#include<cstdlib>
#define Max 100
using namespace std;
typedef char DataType;
typedef struct Node
{
	DataType data;
	Node *next;
}DataNode;
typedef struct
{
	DataNode *front,*rear;
}LinkQueue;
//��ʼ�� 
void InitQueue(LinkQueue *&q) 
{
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	q->front = q->rear = NULL;
}
//�ж������Ƿ�Ϊ��
bool EmptyQueue(LinkQueue *q) 
{
	return q->front == NULL;
}
//���� 
void Push(LinkQueue *q,DataType e)
{
	DataNode *p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if(q->rear == NULL)
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}
//���� 
DataType Pop(LinkQueue *q)
{
	DataNode *t;
	DataType e;
	if(q->rear == NULL)
	{
		cout<<"�����ѿա���\n";
		return 0;
	}
	t = q->front;
	e = q->front->data;
	if(q->front ==q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	free(t);
	return e;
}
//���� 
void Destroy(LinkQueue *&q) 
{
	DataNode *p = q->front,*r;
	if(p!=NULL)
	{
		r = p->next;
		while(r)
		{
			free(p);
			p = r;
			r = r->next;
		}
	}
	free(p);
	free(q);
}
int main()
{
	LinkQueue *q;
	//1����ʼ������
	cout<<"��ʼ������\n\n";
	InitQueue(q);
	
	//2���ж϶����Ƿ�Ϊ��
	cout<<"�ж϶����Ƿ�Ϊ�գ�"<<EmptyQueue(q);
	
	//3�����ν���a,b,c
	cout<<"\n\n���ν���a,b,c";
	Push(q,'a');
	Push(q,'b');
	Push(q,'c');
	
	//4���ж϶����Ƿ�Ϊ��
	cout<<"\n\n�ж϶����Ƿ�Ϊ�գ�"<<EmptyQueue(q);
	
	//5������һ��Ԫ��
	cout<<"\n\n����һ��Ԫ�أ�"<<Pop(q);
	
	//6�����ν���d,e,f
	cout<<"\n\n���ν���d,e,f";
	Push(q,'d');
	Push(q,'e');
	Push(q,'f');
	
	//7���������Ԫ��
	cout<<"\n\n�������Ԫ�أ�";
	while(!EmptyQueue(q))
		cout<<Pop(q)<<" ";
	
	//8���ͷŶ���
	cout<<"\n\n�ͷŶ���";
	Destroy(q);

	return 0;
}


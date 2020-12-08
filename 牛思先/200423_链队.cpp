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
//初始化 
void InitQueue(LinkQueue *&q) 
{
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	q->front = q->rear = NULL;
}
//判断链队是否为空
bool EmptyQueue(LinkQueue *q) 
{
	return q->front == NULL;
}
//进队 
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
//出队 
DataType Pop(LinkQueue *q)
{
	DataNode *t;
	DataType e;
	if(q->rear == NULL)
	{
		cout<<"队列已空。。\n";
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
//销毁 
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
	//1、初始化队列
	cout<<"初始化队列\n\n";
	InitQueue(q);
	
	//2、判断队列是否为空
	cout<<"判断队列是否为空："<<EmptyQueue(q);
	
	//3、依次进队a,b,c
	cout<<"\n\n依次进队a,b,c";
	Push(q,'a');
	Push(q,'b');
	Push(q,'c');
	
	//4、判断队列是否为空
	cout<<"\n\n判断队列是否为空："<<EmptyQueue(q);
	
	//5、出队一个元素
	cout<<"\n\n出队一个元素："<<Pop(q);
	
	//6、依次进队d,e,f
	cout<<"\n\n依次进队d,e,f";
	Push(q,'d');
	Push(q,'e');
	Push(q,'f');
	
	//7、输出队列元素
	cout<<"\n\n输出队列元素：";
	while(!EmptyQueue(q))
		cout<<Pop(q)<<" ";
	
	//8、释放队列
	cout<<"\n\n释放队列";
	Destroy(q);

	return 0;
}


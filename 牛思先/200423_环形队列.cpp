#include<iostream>
#include<cstdlib>
#define Max 100
using namespace std;
typedef char DataType;

typedef struct
{
	DataType data[Max];
	int front;
	int rear;
}queue;
//初始化队列
void InitQueue(queue *&q)
{
	q = (queue*)malloc(sizeof(queue));
	q->front = q->rear = -1;
}
//判断队列是否为空
bool EmptyQueue(queue *q)
{
	return (q->front+1)%Max == (q->rear+1)%Max;
}
//进队
void Push(queue *q,DataType e)
{
	if((q->rear+1)%Max == q->front)
	{
		cout<<"队已满..\n";
		return;
	}
	q->data[(++q->rear)%Max] = e;
}
//出队
DataType Pop(queue *q)
{
	if(q->front == q->rear)
	{
		cout<<"队列没有元素\n";
		return 0;
	}
	return q->data[(++q->front)%Max];
}
//释放队列 
void FreeQueue(queue *q)
{
	free(q);
}
int main()
{
	queue *q;
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
	FreeQueue(q);

	return 0;
}


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
//��ʼ������
void InitQueue(queue *&q)
{
	q = (queue*)malloc(sizeof(queue));
	q->front = q->rear = -1;
}
//�ж϶����Ƿ�Ϊ��
bool EmptyQueue(queue *q)
{
	return (q->front+1)%Max == (q->rear+1)%Max;
}
//����
void Push(queue *q,DataType e)
{
	if((q->rear+1)%Max == q->front)
	{
		cout<<"������..\n";
		return;
	}
	q->data[(++q->rear)%Max] = e;
}
//����
DataType Pop(queue *q)
{
	if(q->front == q->rear)
	{
		cout<<"����û��Ԫ��\n";
		return 0;
	}
	return q->data[(++q->front)%Max];
}
//�ͷŶ��� 
void FreeQueue(queue *q)
{
	free(q);
}
int main()
{
	queue *q;
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
	FreeQueue(q);

	return 0;
}


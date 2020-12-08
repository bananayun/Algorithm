#include<iostream>
#include<cstdlib>

using namespace std;
typedef char DataType;
typedef struct Node
{
	DataType data;
	Node *next;
}ListStack;
//��ʼ����ջ 
void InitListStack(ListStack *&s)
{
	s = (ListStack*)malloc(sizeof(ListStack));
	s->next = NULL;
}
//�ж���ջ�Ƿ�Ϊ��
bool ListStackEmpty(ListStack *s)
{
	return s->next == NULL;
} 
//Ԫ�ؽ�ջ 
void  Push(ListStack *s,DataType value)
{
	ListStack *p;
	p = (ListStack *)malloc(sizeof(ListStack));
	p->data = value;
	p->next = s->next;
	s->next = p;
}
//Ԫ�س�ջ
DataType Pop(ListStack *s)
{
	ListStack *p = s->next;
	DataType value;
	if(s->next == NULL)
	{
		cout<<"ջ�գ�û��Ԫ��";
		return NULL; 
	}
	value = p->data;
	s->next = p->next;
	free(p);
	return value;
}
//����ջ��Ԫ��
DataType Top(ListStack *s) 
{
	return s->next->data;
}
//�ͷ�ջ 
void DestroyListStack(ListStack *&s)
{
	ListStack *p=s,*q = s->next;
    while (q)
    {	
		 free(p);
		 p = q;
		 q = q->next;
    }
    free(p);
}
int main()
{
	ListStack *s,*p;
	//1����ʼ����ջ
	cout<<"��ʼ����ջ\n\n";
	InitListStack(s);
	
	//2���ж���ջ�Ƿ�Ϊ��
	cout<<"�ж���ջ�Ƿ�Ϊ�գ�"<<ListStackEmpty(s);
	
	//3�����ΰ�Ԫ��a,b,c,d,e,f��ջ
	cout<<"\n\n���ΰ�Ԫ��a,b,c,d,e,f��ջ";
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	Push(s,'f');
	
	//4���ж���ջ�Ƿ�Ϊ��
	cout<<"\n\n�ж���ջ�Ƿ�Ϊ�գ�"<<ListStackEmpty(s);
	
	//5�����ջ��Ԫ��
	cout<<"\n\n���ջ��Ԫ�أ�"<<Top(s);
	
	//6���������γ�ջ
	cout<<"\n\n�������γ�ջ����ջԪ��Ϊ��"<<Pop(s)<<"��";
	cout<<Pop(s);
	
	//7�����ջ��Ԫ��
	cout<<"\n\n���ջ��Ԫ�أ�"<<Top(s);
	
	//8�������ջ����
	cout<<"\n\n�����ջ���У�";
	p = s;
	while(!ListStackEmpty(p))
	{
		cout<<Top(p)<<" ";
		p = p->next;
	}
	
	//9���ͷ�ջ
	cout<<"\n\n�ͷ�ջ";
	DestroyListStack(s);

	return 0; 
}


#include<iostream>
#include<cstdlib>
#define MaxSize 100
typedef char DataType;
using namespace std;

typedef struct
{
	DataType data[MaxSize];
	int top;
}Stack;

//��ʼ��ջ������һ����ջs��
void InitStack(Stack *&s)
{
	s = (Stack*)malloc(sizeof(Stack));
	s->top = -1;
}

//����ջ���ͷ�ջsռ�õĴ洢�ռ䡣
void DestroyStack(Stack *&s)
{
	free(s);
}
//�ж�ջ�Ƿ�Ϊ��:��ջsΪ�գ��򷵻��棻���򷵻ؼ١�
bool StackEmpty(Stack *s)
{
	return (s->top == -1);
}
//��ջ����Ԫ��e���뵽ջs����Ϊջ��Ԫ�ء�
void Push(Stack *s,DataType e)
{
	if(s->top == MaxSize-1)
	{
		cout<<"ջ����\n";
		return;
	}
	s->data[++s->top] = e;
}
//��ջ����ջs���˳�ջ��Ԫ�أ�������ֵ����e��
void Pop(Stack *s,DataType &e)
{
	if(s->top == -1)
	{
		cout<<"ջΪ��\n";
		return;
	}
	e = s->data[s->top--];
}
//ȡջ��Ԫ�ء����ص�ǰ��ջ��Ԫ�أ�������ֵ����e��
void GetTop(Stack *s,DataType &e)
{
	if(s->top == -1)
	{
		cout<<"ջ�ѿգ�û��Ԫ��\n";
		return;
	}
	e = s->data[s->top];
}

int main()
{
	Stack *s;
	DataType e;
	//1����ʼ��ջ 
	cout<<"��ʼ��ջ\n\n";
	InitStack(s);
	
	//2���ж�ջS�Ƿ�Ϊ��
	cout<<"�ж�ջS�Ƿ�Ϊ�գ�"<<StackEmpty(s);
	
	//3�����ν�ջԪ��a,b,c,d,e,f
	cout<<"\n\n���ν�ջԪ��a,b,c,d,e,f\n\n";
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	Push(s,'f');
	
	//4���ж�ջS�Ƿ�Ϊ��
	cout<<"�ж�ջS�Ƿ�Ϊ�գ�"<<StackEmpty(s);
	
	//5�����ջ��Ԫ��
	cout<<"\n\n���ջ��Ԫ�أ�";
	GetTop(s,e);
	cout<<e;
	
	//6���������γ�ջ����
	cout<<"\n\n�������γ�ջ��������ջԪ�أ�";
	Pop(s,e);
	cout<<e<<"��";
	Pop(s,e);
	cout<<e;
	
	//7�����ջ��Ԫ��
	cout<<"\n\n���ջ��Ԫ�أ�";
	GetTop(s,e);
	cout<<e;
	
	//8�����ջ����
	cout<<"\n\n���ջ���У�";
	while(s->top != -1)
		cout<<s->data[s->top--];
	
	//9���ͷ�ջ
	cout<<"\n\n�ͷ�ջ";
	DestroyStack(s);
	
	return 0;
}


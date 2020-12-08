#include<iostream>
#include<cstdlib>

using namespace std;
typedef char DataType;
typedef struct Node
{
	DataType data;
	Node *next;
}ListStack;
//初始化链栈 
void InitListStack(ListStack *&s)
{
	s = (ListStack*)malloc(sizeof(ListStack));
	s->next = NULL;
}
//判断链栈是否为空
bool ListStackEmpty(ListStack *s)
{
	return s->next == NULL;
} 
//元素进栈 
void  Push(ListStack *s,DataType value)
{
	ListStack *p;
	p = (ListStack *)malloc(sizeof(ListStack));
	p->data = value;
	p->next = s->next;
	s->next = p;
}
//元素出栈
DataType Pop(ListStack *s)
{
	ListStack *p = s->next;
	DataType value;
	if(s->next == NULL)
	{
		cout<<"栈空，没有元素";
		return NULL; 
	}
	value = p->data;
	s->next = p->next;
	free(p);
	return value;
}
//返回栈顶元素
DataType Top(ListStack *s) 
{
	return s->next->data;
}
//释放栈 
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
	//1、初始化链栈
	cout<<"初始化链栈\n\n";
	InitListStack(s);
	
	//2、判断链栈是否为空
	cout<<"判断链栈是否为空："<<ListStackEmpty(s);
	
	//3、依次把元素a,b,c,d,e,f进栈
	cout<<"\n\n依次把元素a,b,c,d,e,f进栈";
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	Push(s,'f');
	
	//4、判断链栈是否为空
	cout<<"\n\n判断链栈是否为空："<<ListStackEmpty(s);
	
	//5、输出栈顶元素
	cout<<"\n\n输出栈顶元素："<<Top(s);
	
	//6、进行两次出栈
	cout<<"\n\n进行两次出栈，出栈元素为："<<Pop(s)<<"、";
	cout<<Pop(s);
	
	//7、输出栈顶元素
	cout<<"\n\n输出栈顶元素："<<Top(s);
	
	//8、输出出栈序列
	cout<<"\n\n输出出栈序列：";
	p = s;
	while(!ListStackEmpty(p))
	{
		cout<<Top(p)<<" ";
		p = p->next;
	}
	
	//9、释放栈
	cout<<"\n\n释放栈";
	DestroyListStack(s);

	return 0; 
}


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

//初始化栈。构造一个空栈s。
void InitStack(Stack *&s)
{
	s = (Stack*)malloc(sizeof(Stack));
	s->top = -1;
}

//销毁栈。释放栈s占用的存储空间。
void DestroyStack(Stack *&s)
{
	free(s);
}
//判断栈是否为空:若栈s为空，则返回真；否则返回假。
bool StackEmpty(Stack *s)
{
	return (s->top == -1);
}
//进栈。将元素e插入到栈s中作为栈顶元素。
void Push(Stack *s,DataType e)
{
	if(s->top == MaxSize-1)
	{
		cout<<"栈已满\n";
		return;
	}
	s->data[++s->top] = e;
}
//出栈。从栈s中退出栈顶元素，并将其值赋给e。
void Pop(Stack *s,DataType &e)
{
	if(s->top == -1)
	{
		cout<<"栈为空\n";
		return;
	}
	e = s->data[s->top--];
}
//取栈顶元素。返回当前的栈顶元素，并将其值赋给e。
void GetTop(Stack *s,DataType &e)
{
	if(s->top == -1)
	{
		cout<<"栈已空，没有元素\n";
		return;
	}
	e = s->data[s->top];
}

int main()
{
	Stack *s;
	DataType e;
	//1、初始化栈 
	cout<<"初始化栈\n\n";
	InitStack(s);
	
	//2、判断栈S是否为空
	cout<<"判断栈S是否为空："<<StackEmpty(s);
	
	//3、依次进栈元素a,b,c,d,e,f
	cout<<"\n\n依次进栈元素a,b,c,d,e,f\n\n";
	Push(s,'a');
	Push(s,'b');
	Push(s,'c');
	Push(s,'d');
	Push(s,'e');
	Push(s,'f');
	
	//4、判断栈S是否为空
	cout<<"判断栈S是否为空："<<StackEmpty(s);
	
	//5、输出栈顶元素
	cout<<"\n\n输出栈顶元素：";
	GetTop(s,e);
	cout<<e;
	
	//6、进行两次出栈操作
	cout<<"\n\n进行两次出栈操作，出栈元素：";
	Pop(s,e);
	cout<<e<<"、";
	Pop(s,e);
	cout<<e;
	
	//7、输出栈顶元素
	cout<<"\n\n输出栈顶元素：";
	GetTop(s,e);
	cout<<e;
	
	//8、输出栈序列
	cout<<"\n\n输出栈序列：";
	while(s->top != -1)
		cout<<s->data[s->top--];
	
	//9、释放栈
	cout<<"\n\n释放栈";
	DestroyStack(s);
	
	return 0;
}


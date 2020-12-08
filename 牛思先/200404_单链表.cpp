#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef char DataType;

typedef struct Node
{
	DataType value;
	Node *next;
}List;

//初始化链表 
void InitList(List *&L)
{
	L = (List *)malloc(sizeof(List));
	L->next = NULL;
}

//创建链表
void CreateList(List *&L,DataType a[])
{
	List *p,*r;
	r = L;
	int length = strlen(a);
	for(int i=0;i<length;i++)
	{
		p=(List *)malloc(sizeof(List));
		p->value = a[i];
		r->next = p;
		r=p;
	}
	r->next = NULL;
 } 

 //输出链表
void OutList(List *L)
{	
	List *p = L->next;
	
 	while(p != NULL)
 	{
 		cout<<" "<<p->value;
 		p = p->next;
	}
} 
 
//输出链表的长度
int ListLength(List *L)
{
	List *p = L->next;
	int i=0;
	while(p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
} 

//拆分链表 
void SplitList(List *&L,List *&L1, List *&L2,List *&L3)
{
	List *p = L->next,*q,*r1 = L1,*r2 = L2,*r3 = L3;
	
	while(p != NULL)
	{
		q = (List *)malloc(sizeof(List));
		q->value = p->value;
		
		if(p->value >= '0' && p->value <= '9')
		{
			r1->next = q;
			r1 = q;
		}
		else if(p->value >= 'a' && p->value <= 'z')
		{
			r2->next = q;
			r2 = q;
		}
		else
		{
			r3->next = q;
			r3 = q;
		}
		p = p->next;
	}
	r1->next=NULL;
	r2->next=NULL;
	r3->next=NULL;
}

//输出链表123
void OutList123(List *L1,List *L2,List *L3)
{
	List *a;
	
	a = L1->next;
	cout<<"\n   L1：";
	while(a != NULL)
	{
		cout<<" "<<a->value;
		a = a->next;
	}
	
	a = L2->next;
	cout<<"\n   L2：";
	while(a != NULL)
	{
		cout<<" "<<a->value;
		a = a->next;
	}
	
	a = L3->next;
	cout<<"\n   L3：";
	while(a != NULL)
	{
		cout<<" "<<a->value;
		a = a->next;
	}
} 

//输出链表123的长度 
void ListLength123(List *L1,List *L2,List *L3)
{
	int length=0;
	List *p;
	p = L1->next;
	cout<<"\n   L1的长度：";
	while(p != NULL)
	{
		p = p->next;
		length++;
	} 
	cout<<length;
	
	length = 0;
	p = L2->next;
	cout<<"\n   L2的长度：";
	while(p != NULL)
	{
		p = p->next;
		length++;
	} 
	cout<<length;
	
	length = 0;
	p = L3->next;
	cout<<"\n   L3的长度：";
	while(p != NULL)
	{
		p = p->next;
		length++;
	} 
	cout<<length;
}

//统计单链表L中的整数个数
void Count(List *L)
{
	int count = 0;
	List *p;
	p = L->next;
	while(p != NULL)
	{
		if(p->value >= '0' && p->value <= '9')
		{
			count++;
			while(p->value >= '0' && p->value <= '9' &&p->next)
				p = p->next;
				
		}
		p = p->next;
	}
	cout<<count;
} 

//释放链表
void FreeList(List * L)
{
	List * p = L->next,*q;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	L->next = NULL;
}
int main()
{
	List *L,*L1,*L2,*L3;
	
	//1、初始化链表
	cout<<"初始化链表L，L1，L2，L3\n\n"; 
	InitList(L);
	InitList(L1);
	InitList(L2);
	InitList(L3);
	 
	//2、建立单链表
	cout<<"建立单链表L\n\n"; 
	DataType a[]="Lgy520Wxy1314"; 
	CreateList(L,a);
	 
	//3、输出单链表L
	cout<<"输出单链表L：";
	OutList(L); 
	
	//4、输出链表L的长度
	cout<<"\n\n链表的长度为：";
	cout<<ListLength(L);
	
	//5、拆分单链表L
	cout<<"\n\n拆分单链表L";
	SplitList(L,L1,L2,L3);
	
	//6、输出单链表L1，L2，L3
	cout<<"\n\n输出单链表L1，L2，L3" ;
	OutList123(L1,L2,L3);
	
	//7、输出单链表L1，L2，L3的长度
	cout<<"\n\n输出单链表L1，L2，L3的长度";
	ListLength123(L1,L2,L3);
	
	//8、统计单链表L中的整数的个数
	cout<<"\n\n统计单链表L中的整数的个数：";
	Count(L); 
	
	//9、释放单链表L，L1，L2，L3
	cout<<"\n\n释放单链表L，L1，L2，L3";
	FreeList(L);
	FreeList(L1);
	FreeList(L2);
	FreeList(L3);

	return 0; 
}


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

//��ʼ������ 
void InitList(List *&L)
{
	L = (List *)malloc(sizeof(List));
	L->next = NULL;
}

//��������
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

 //�������
void OutList(List *L)
{	
	List *p = L->next;
	
 	while(p != NULL)
 	{
 		cout<<" "<<p->value;
 		p = p->next;
	}
} 
 
//�������ĳ���
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

//������� 
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

//�������123
void OutList123(List *L1,List *L2,List *L3)
{
	List *a;
	
	a = L1->next;
	cout<<"\n   L1��";
	while(a != NULL)
	{
		cout<<" "<<a->value;
		a = a->next;
	}
	
	a = L2->next;
	cout<<"\n   L2��";
	while(a != NULL)
	{
		cout<<" "<<a->value;
		a = a->next;
	}
	
	a = L3->next;
	cout<<"\n   L3��";
	while(a != NULL)
	{
		cout<<" "<<a->value;
		a = a->next;
	}
} 

//�������123�ĳ��� 
void ListLength123(List *L1,List *L2,List *L3)
{
	int length=0;
	List *p;
	p = L1->next;
	cout<<"\n   L1�ĳ��ȣ�";
	while(p != NULL)
	{
		p = p->next;
		length++;
	} 
	cout<<length;
	
	length = 0;
	p = L2->next;
	cout<<"\n   L2�ĳ��ȣ�";
	while(p != NULL)
	{
		p = p->next;
		length++;
	} 
	cout<<length;
	
	length = 0;
	p = L3->next;
	cout<<"\n   L3�ĳ��ȣ�";
	while(p != NULL)
	{
		p = p->next;
		length++;
	} 
	cout<<length;
}

//ͳ�Ƶ�����L�е���������
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

//�ͷ�����
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
	
	//1����ʼ������
	cout<<"��ʼ������L��L1��L2��L3\n\n"; 
	InitList(L);
	InitList(L1);
	InitList(L2);
	InitList(L3);
	 
	//2������������
	cout<<"����������L\n\n"; 
	DataType a[]="Lgy520Wxy1314"; 
	CreateList(L,a);
	 
	//3�����������L
	cout<<"���������L��";
	OutList(L); 
	
	//4���������L�ĳ���
	cout<<"\n\n����ĳ���Ϊ��";
	cout<<ListLength(L);
	
	//5����ֵ�����L
	cout<<"\n\n��ֵ�����L";
	SplitList(L,L1,L2,L3);
	
	//6�����������L1��L2��L3
	cout<<"\n\n���������L1��L2��L3" ;
	OutList123(L1,L2,L3);
	
	//7�����������L1��L2��L3�ĳ���
	cout<<"\n\n���������L1��L2��L3�ĳ���";
	ListLength123(L1,L2,L3);
	
	//8��ͳ�Ƶ�����L�е������ĸ���
	cout<<"\n\nͳ�Ƶ�����L�е������ĸ�����";
	Count(L); 
	
	//9���ͷŵ�����L��L1��L2��L3
	cout<<"\n\n�ͷŵ�����L��L1��L2��L3";
	FreeList(L);
	FreeList(L1);
	FreeList(L2);
	FreeList(L3);

	return 0; 
}


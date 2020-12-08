#include<iostream>
#include<cstdlib>
using namespace std;
//���崮����
typedef struct Node
{
	char data;
	Node *next;
}Sqstr;
void InitStr(Sqstr *&s)
{
	s = (Sqstr *)malloc(sizeof(Sqstr));
	s->next = NULL;
}
//1.������
void CreateStr(Sqstr *s,char cstr[])
{
     //�㷨��1.��cstr�����ÿ���ַ�������s�е�ÿ��Ԫ��
  //�ַ�������'\0'������
	Sqstr *p,*q = s;
	for(int i=0;cstr[i]!='\0';i++)
	{
		p = (Sqstr*)malloc(sizeof(Sqstr));
		p->data = cstr[i];
		q->next = p;
		q = p;
	}
	q->next = NULL;
}
//2�������
void OutStr(Sqstr *s)
{
	Sqstr *p = s->next;
	while(p)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}
//3.�����S�ĳ���
int StrLength(Sqstr *s)
{
	int length = 0;
	Sqstr *p = s->next;
	while(p)
	{
		length++;
		p = p->next;
	}
	return length;
}
//4. �ڴ�s�ĵ�9��λ���ϲ��봮s1�����ɴ�s2
Sqstr* InsertStr(Sqstr *s,Sqstr *t,int pos)
{
	Sqstr *str,*r,*p = s->next,*q = t->next,*k;
	str = (Sqstr*)malloc(sizeof(Sqstr));
	r = str;
	while(--pos)
	{
		k = (Sqstr*)malloc(sizeof(Sqstr));
		k->data = p->data;
		r->next = k;
		r = k;
		p = p->next;
	}
	cout<<r->data;
	while(q)
	{
		k = (Sqstr*)malloc(sizeof(Sqstr));
		k->data = q->data;
		r->next = k;
		r = k;
		q = q->next;
	}
	while(p)
	{
		k = (Sqstr*)malloc(sizeof(Sqstr));
		k->data = p->data;
		r->next = k;
		r = k;
		p = p->next;
	}
	r->next = NULL;
	return str;
}
//6. ɾ����s�ĵ�2���ַ���ʼ��5���ַ����ɴ�s3
Sqstr* DelStr(Sqstr *s,int pos,int length)
{
	Sqstr *p = s->next,*str,*r,*q;
	str = (Sqstr*)malloc(sizeof(Sqstr));
	r = str;
	for(int i=1;p;i++)
	{
		if(i < pos || i >= pos+length)
		{
			q = (Sqstr*)malloc(sizeof(Sqstr));
			q->data = p->data;
			r->next = q;
			r = q;
		}
		p = p->next;
	}
	r->next = NULL;
	return str;
}
//8. ����s��2���ַ���ʼ��5���ַ��滻�ɴ�s1���ɴ�s4
Sqstr* ReplaceStr(Sqstr *s,Sqstr *t,int pos,int length)
{
	Sqstr *p = s->next,*str,*r,*q,*k = t->next;
	str = (Sqstr*)malloc(sizeof(Sqstr));
	r = str;
	for(int i=1;p;i++)
	{
		if(i < pos || i >= pos+length)
		{
			q = (Sqstr*)malloc(sizeof(Sqstr));
			q->data = p->data;
			r->next = q;
			r = q;
		}
		else if(k)
		{
			q = (Sqstr*)malloc(sizeof(Sqstr));
			q->data = k->data;
			r->next = q;
			r = q;
			k = k->next;
		}
		p = p->next;
	}
	r->next = NULL;
	return str;
}
//10.��ȡ��s�ĵ�2���ַ���ʼ��5���ַ����ɴ�s5
Sqstr* Extract(Sqstr *s,int pos,int length)
{
	Sqstr *p = s->next,*str,*r,*q;
	str = (Sqstr*)malloc(sizeof(Sqstr));
	r = str;
	for(int i=1;p;i++)
	{
		if(i >= pos && i < pos+length)
		{
			q = (Sqstr*)malloc(sizeof(Sqstr));
			q->data = p->data;
			r->next = q;
			r = q;
		}
		p = p->next;
	}
	r->next = NULL;
	return str;
}

//12.����s�ʹ�s1�����������ɴ�s6
Sqstr* Concat(Sqstr *s,Sqstr *t)
{  
	Sqstr *str,*p = s->next,*q = t->next,*r,*k;
	str = (Sqstr*)malloc(sizeof(Sqstr));
	r = str;
	while(p)
	{
		k = (Sqstr*)malloc(sizeof(Sqstr));
		k->data = p->data;
		r->next = k;
		r = k;
		p = p->next;
	}
	while(q)
	{
		k = (Sqstr*)malloc(sizeof(Sqstr));
		k->data = q->data;
		r->next = k;
		r = k;
		q = q->next;
	}
	r->next = NULL;
	return str;
}
int main()
{
	Sqstr* s,*s1,*s2,*s3,*s4,*s5,*s6;
	cout<<"1. ������s=\"abcdefghfefhygdijklmn\"�ʹ�s1=\"xyz\"";
	char a[] = "abcdefghfefhygdijklmn",b[] = "xyz";
	InitStr(s);
	InitStr(s1);
//1. ������s="abcdefghfefhygdijklmn"�ʹ�s1="xyz"
	CreateStr(s,a);
	CreateStr(s1,b);
//2. �����S
	cout<<"\n\n2. �����S��";
	OutStr(s);
//3. �����S�ĳ���
	cout<<"\n\n3. �����S�ĳ��ȣ�";
	cout<<StrLength(s);
//4. �ڴ�s�ĵ�9��λ���ϲ��봮s1�����ɴ�s2
	cout<<"\n\n4. �ڴ�s�ĵ�9��λ���ϲ��봮s1�����ɴ�s2";
	s2 = InsertStr(s,s1,9);
//5. �����s2
	cout<<"\n\n5. �����s2��";
	OutStr(s2);
//6. ɾ����s�ĵ�2���ַ���ʼ��5���ַ����ɴ�s3
	cout<<"\n\n6. ɾ����s�ĵ�2���ַ���ʼ��5���ַ����ɴ�s3";
	s3 = DelStr(s,2,5);
//7. �����s3
	cout<<"\n\n7. �����s3��";
	OutStr(s3);
//8. ����s��2���ַ���ʼ��5���ַ��滻�ɴ�s1���ɴ�s4;
	cout<<"\n\n8. ����s��2���ַ���ʼ��5���ַ��滻�ɴ�s1���ɴ�s4";
	s4 = ReplaceStr(s,s1,2,5);
//9.�����s4;
	cout<<"\n\n9.�����s4��";
	OutStr(s4);
//10.��ȡ��s�ĵ�2���ַ���ʼ��5���ַ����ɴ�s5;
	cout<<"\n\n10.��ȡ��s�ĵ�2���ַ���ʼ��5���ַ����ɴ�s5";
	s5 = Extract(s,2,5);
//11.�����s5;
	cout<<"\n\n11.�����s5��";
	OutStr(s5);
//12.����s�ʹ�s1�����������ɴ�s6;
	cout<<"\n\n12.����s�ʹ�s1�����������ɴ�s6";
	s6 = Concat(s,s1);
//13.�����s6��
	cout<<"\n\n13.�����s6��";
	OutStr(s6);
	
	return 0;
}


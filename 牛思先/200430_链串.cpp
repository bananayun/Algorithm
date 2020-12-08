#include<iostream>
#include<cstdlib>
using namespace std;
//定义串类型
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
//1.建立串
void CreateStr(Sqstr *s,char cstr[])
{
     //算法：1.把cstr数组的每个字符赋给串s中的每个元素
  //字符串是以'\0'结束的
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
//2、输出串
void OutStr(Sqstr *s)
{
	Sqstr *p = s->next;
	while(p)
	{
		cout<<" "<<p->data;
		p = p->next;
	}
}
//3.输出串S的长度
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
//4. 在串s的第9个位置上插入串s1而生成串s2
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
//6. 删除串s的第2个字符开始的5个字符生成串s3
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
//8. 将串s第2个字符开始的5个字符替换成串s1生成串s4
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
//10.提取串s的第2个字符开始的5个字符生成串s5
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

//12.将串s和串s1连接起来生成串s6
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
	cout<<"1. 建立串s=\"abcdefghfefhygdijklmn\"和串s1=\"xyz\"";
	char a[] = "abcdefghfefhygdijklmn",b[] = "xyz";
	InitStr(s);
	InitStr(s1);
//1. 建立串s="abcdefghfefhygdijklmn"和串s1="xyz"
	CreateStr(s,a);
	CreateStr(s1,b);
//2. 输出串S
	cout<<"\n\n2. 输出串S：";
	OutStr(s);
//3. 输出串S的长度
	cout<<"\n\n3. 输出串S的长度：";
	cout<<StrLength(s);
//4. 在串s的第9个位置上插入串s1而生成串s2
	cout<<"\n\n4. 在串s的第9个位置上插入串s1而生成串s2";
	s2 = InsertStr(s,s1,9);
//5. 输出串s2
	cout<<"\n\n5. 输出串s2：";
	OutStr(s2);
//6. 删除串s的第2个字符开始的5个字符生成串s3
	cout<<"\n\n6. 删除串s的第2个字符开始的5个字符生成串s3";
	s3 = DelStr(s,2,5);
//7. 输出串s3
	cout<<"\n\n7. 输出串s3：";
	OutStr(s3);
//8. 将串s第2个字符开始的5个字符替换成串s1生成串s4;
	cout<<"\n\n8. 将串s第2个字符开始的5个字符替换成串s1生成串s4";
	s4 = ReplaceStr(s,s1,2,5);
//9.输出串s4;
	cout<<"\n\n9.输出串s4：";
	OutStr(s4);
//10.提取串s的第2个字符开始的5个字符生成串s5;
	cout<<"\n\n10.提取串s的第2个字符开始的5个字符生成串s5";
	s5 = Extract(s,2,5);
//11.输出串s5;
	cout<<"\n\n11.输出串s5：";
	OutStr(s5);
//12.将串s和串s1连接起来生成串s6;
	cout<<"\n\n12.将串s和串s1连接起来生成串s6";
	s6 = Concat(s,s1);
//13.输出串s6。
	cout<<"\n\n13.输出串s6：";
	OutStr(s6);
	
	return 0;
}


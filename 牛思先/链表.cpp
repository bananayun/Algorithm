#include<cstdio>
#include<cstdlib>
#define MAXLEN 50
typedef int DataType;
typedef struct{
	DataType data[MAXLEN];
	int length;
}SeqList;
//初始化顺序表
void InitList(SeqList *L){
	//动态分布存储空间
	L=(SeqList *)malloc(sizeof(SeqList));
	L->length=0;
}
//销毁顺序表
void DestroyList(SeqList *L){
	free(L);
}
//判断顺序表是否为空
bool ListEmpty(SeqList *L){
	return (L->length==0);
}
//求顺序表的长度
int ListLength(SeqList *L){
	return L->length;
}
//输出顺序表
void DispList(SeqList *L){
	int i;
	//判断是是否为空
	if(ListEmpty(L)){
		printf("顺序表为空\n");
		return;
	}
	for (i=0;i<L->length;i++)
		printf("%6d",L->data[i]);
	printf("\n");
}
//建立顺序表
void CreateList(SeqList *&L,DataType a[],int n){
	int i=0,k=0;
	L=(SeqList *)malloc(sizeof(SeqList));
	while(i<n){
		L->data[k]=a[i];
		k++;i++;
	}
	L->length=k;
}
//插入元素
bool ListInsert(){
} 
//删除元素
bool ListDelete(){} 
//查找元素 
GetElem() {} 
 int main()
 {
 	SeqList *L;
 	int a[MAXLEN]={1,2,3,3,4,5,6,7,8,9}; 
 	int n;
 	//1.初始化顺序表
	 InitList(L);
	 //1.1验证顺序表是否为空
	 if(ListEmpty(L))
	 printf("线性表为空\n"); 
	 else
	  printf("线性表非空\n"); 
	 //2.建立顺序表
	 CreateList(L,a,9);
	 // 2.1验证顺序表是否为空
	 if(ListEmpty(L))
	 printf("线性表为空\n"); 
	 else
	  printf("线性表非空\n"); 
	 //3.输出顺序表
	 DispList(L); 
 	
 }


#include<cstdio>
#include<cstdlib>
#define MAXLEN 50
typedef int DataType;
typedef struct{
	DataType data[MAXLEN];
	int length;
}SeqList;
//��ʼ��˳���
void InitList(SeqList *L){
	//��̬�ֲ��洢�ռ�
	L=(SeqList *)malloc(sizeof(SeqList));
	L->length=0;
}
//����˳���
void DestroyList(SeqList *L){
	free(L);
}
//�ж�˳����Ƿ�Ϊ��
bool ListEmpty(SeqList *L){
	return (L->length==0);
}
//��˳���ĳ���
int ListLength(SeqList *L){
	return L->length;
}
//���˳���
void DispList(SeqList *L){
	int i;
	//�ж����Ƿ�Ϊ��
	if(ListEmpty(L)){
		printf("˳���Ϊ��\n");
		return;
	}
	for (i=0;i<L->length;i++)
		printf("%6d",L->data[i]);
	printf("\n");
}
//����˳���
void CreateList(SeqList *&L,DataType a[],int n){
	int i=0,k=0;
	L=(SeqList *)malloc(sizeof(SeqList));
	while(i<n){
		L->data[k]=a[i];
		k++;i++;
	}
	L->length=k;
}
//����Ԫ��
bool ListInsert(){
} 
//ɾ��Ԫ��
bool ListDelete(){} 
//����Ԫ�� 
GetElem() {} 
 int main()
 {
 	SeqList *L;
 	int a[MAXLEN]={1,2,3,3,4,5,6,7,8,9}; 
 	int n;
 	//1.��ʼ��˳���
	 InitList(L);
	 //1.1��֤˳����Ƿ�Ϊ��
	 if(ListEmpty(L))
	 printf("���Ա�Ϊ��\n"); 
	 else
	  printf("���Ա�ǿ�\n"); 
	 //2.����˳���
	 CreateList(L,a,9);
	 // 2.1��֤˳����Ƿ�Ϊ��
	 if(ListEmpty(L))
	 printf("���Ա�Ϊ��\n"); 
	 else
	  printf("���Ա�ǿ�\n"); 
	 //3.���˳���
	 DispList(L); 
 	
 }


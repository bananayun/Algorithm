#include<iostream>

//***************���Ա�*******************

int MAX=100;
typedef struct Node *List;
struct Node{
	ElementType Data[MAX];
	int Last;
}L; 
List Ptrl;
//��ʼ��
List MakeEmpty(){
	List Ptrl;
	Ptrl=(List)malloc(sizeof(struct Node));
	Ptrl->Last = -1;
	return Ptrl;
} 
//����
int Find(ElementType x,List Ptrl){
	int i=0;
	while(i<Ptrl->Last&&Ptrl->Data[i]!=x) i++;
	if(i>Ptrl->Last)return -1;
	else return i;
} 
//����
void Insert(ElementType x,int i,List Ptrl){
	int j;
	if(Ptrl->Last==MAX-1) {
		printf("����\n");
		return;
	}if(i<1||i>Ptrl->Last+2){
		printf("λ�ò��Ϸ�\n");
		return ;
	}
	for(j=Ptrl->Last;j>=i-1;j--) Ptrl->Data[j+1]=Ptrl->Data[j];
	Ptrl->Data[i-1]=x;
	Ptrl->Last++;
	return ;
} 

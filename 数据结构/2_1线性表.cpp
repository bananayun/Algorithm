#include<iostream>

//***************线性表*******************

int MAX=100;
typedef struct Node *List;
struct Node{
	ElementType Data[MAX];
	int Last;
}L; 
List Ptrl;
//初始化
List MakeEmpty(){
	List Ptrl;
	Ptrl=(List)malloc(sizeof(struct Node));
	Ptrl->Last = -1;
	return Ptrl;
} 
//查找
int Find(ElementType x,List Ptrl){
	int i=0;
	while(i<Ptrl->Last&&Ptrl->Data[i]!=x) i++;
	if(i>Ptrl->Last)return -1;
	else return i;
} 
//插入
void Insert(ElementType x,int i,List Ptrl){
	int j;
	if(Ptrl->Last==MAX-1) {
		printf("表满\n");
		return;
	}if(i<1||i>Ptrl->Last+2){
		printf("位置不合法\n");
		return ;
	}
	for(j=Ptrl->Last;j>=i-1;j--) Ptrl->Data[j+1]=Ptrl->Data[j];
	Ptrl->Data[i-1]=x;
	Ptrl->Last++;
	return ;
} 

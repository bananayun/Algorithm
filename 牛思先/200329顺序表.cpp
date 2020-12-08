#include<iostream>
#include<cstdlib>
#define Max 50
using namespace std;

typedef char DataType;
typedef struct{
	DataType data[Max];
	int length;
}Sqlist;

//1����ʼ������
void InitList(Sqlist *&L){
	L=(Sqlist *)malloc(sizeof(Sqlist));
	L->length=0;
} 
//2������Ԫ��
bool ListInsert(Sqlist*&L,int a,DataType value){
	if(a<1 || a>L->length+1) return false;
	for(int i = L->length+1; i > a-1 ;i--)
		L->data[i] = L->data[i-1];
	L->data[a] = value;
	L->length++;
	return true;
}
//5���ж�˳����Ƿ�Ϊ��
bool ListEmpty(Sqlist *L){
	return L->length==0;
} 
//3�����˳���
void DispList(Sqlist*L){
	if(ListEmpty(L)){
		cout<<"˳���Ϊ��\n";
		return ;
	}
	for(int i=1;i<=L->length;i++)
		cout<<L->data[i]<<" ";
} 
//4�����˳���ĳ���
int ListLength(Sqlist *L){
	return L->length;
} 
//6�����˳���ĵ�a��Ԫ��
void GetElem(Sqlist *L,int a){
	if(a<=L->length && a>0)cout<<L->data[a]<<endl;
	else cout<<"���\n";
} 
//7�����Ԫ��*��λ��
void LocateElem(Sqlist *L,DataType a){
	for(int i=1;i<=L->length;i++)
		if(L->data[i]==a){
			cout<<i;
			return;
		}
	cout<<"û�и�Ԫ��\n";
}
//10��ɾ����a��Ԫ��
void ListDelete(Sqlist *L,int a){
	if(a<1 || a>L->length){
		cout<<"���";
		return;
	}
	for(int i=a;i<L->length;i++)
		L->data[i]=L->data[i+1];
	L->length--;
	cout<<"�ɹ�";
} 
//12���ͷ�˳���
void Destroy(Sqlist *L){
	free(L);
}
int main(){
	Sqlist *L;
	
	//1����ʼ������
	cout<<"��ʼ��˳���"; 
	InitList(L);
	
	//2�����β���a,b,c,d,eԪ��
	ListInsert(L,1,'a');
	ListInsert(L,2,'b');
	ListInsert(L,3,'c');
	ListInsert(L,4,'d');
	ListInsert(L,5,'e');
	
	//3�����˳���
	cout<<"\n\n���˳���"; 
	DispList(L);
	
	//4�����˳���ĳ���
	cout<<"\n\n˳���ĳ��ȣ�"<<ListLength(L); 
	
	//5���ж�˳����Ƿ�Ϊ��
	cout<<"\n\n˳����Ƿ�Ϊ�գ�"<<(ListEmpty(L)?"��":"��");
	
	//6�����˳���ĵ�����Ԫ��
	cout<<"\n\n˳���ĵ�3��Ԫ�أ�";
	GetElem(L,3);
	
	//7�����Ԫ��c��λ��
	cout<<"\nԪ��c����λ�ã�";
	LocateElem(L,'c');
	
	//8���ڵ�4��λ�ò���fԪ��
	cout<<"\n\n�ڵ�4��λ�ò���f��"<<(ListInsert(L,4,'f')? "�ɹ�":"ʧ��");
	
	//9�����˳���
	cout<<"\n\n���˳���";
	DispList(L);
	
	//10��ɾ��˳���ĵ�2��Ԫ��
	cout<<"\n\nɾ��˳���ĵ�2��Ԫ�أ�";
	ListDelete(L,2); 
	
	//11�����˳���
	cout<<"\n\n���˳���";
	DispList(L);
	
	//12���ͷ�˳���
	cout<<"\n\n�ͷ�˳���\n";
	Destroy(L); 
	
	return 0;
} 


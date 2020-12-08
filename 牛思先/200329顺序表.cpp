#include<iostream>
#include<cstdlib>
#define Max 50
using namespace std;

typedef char DataType;
typedef struct{
	DataType data[Max];
	int length;
}Sqlist;

//1、初始化链表
void InitList(Sqlist *&L){
	L=(Sqlist *)malloc(sizeof(Sqlist));
	L->length=0;
} 
//2、插入元素
bool ListInsert(Sqlist*&L,int a,DataType value){
	if(a<1 || a>L->length+1) return false;
	for(int i = L->length+1; i > a-1 ;i--)
		L->data[i] = L->data[i-1];
	L->data[a] = value;
	L->length++;
	return true;
}
//5、判断顺序表是否为空
bool ListEmpty(Sqlist *L){
	return L->length==0;
} 
//3、输出顺序表
void DispList(Sqlist*L){
	if(ListEmpty(L)){
		cout<<"顺序表为空\n";
		return ;
	}
	for(int i=1;i<=L->length;i++)
		cout<<L->data[i]<<" ";
} 
//4、输出顺序表的长度
int ListLength(Sqlist *L){
	return L->length;
} 
//6、输出顺序表的第a个元素
void GetElem(Sqlist *L,int a){
	if(a<=L->length && a>0)cout<<L->data[a]<<endl;
	else cout<<"溢出\n";
} 
//7、输出元素*的位置
void LocateElem(Sqlist *L,DataType a){
	for(int i=1;i<=L->length;i++)
		if(L->data[i]==a){
			cout<<i;
			return;
		}
	cout<<"没有该元素\n";
}
//10、删除第a个元素
void ListDelete(Sqlist *L,int a){
	if(a<1 || a>L->length){
		cout<<"溢出";
		return;
	}
	for(int i=a;i<L->length;i++)
		L->data[i]=L->data[i+1];
	L->length--;
	cout<<"成功";
} 
//12、释放顺序表
void Destroy(Sqlist *L){
	free(L);
}
int main(){
	Sqlist *L;
	
	//1、初始化链表
	cout<<"初始化顺序表"; 
	InitList(L);
	
	//2、依次插入a,b,c,d,e元素
	ListInsert(L,1,'a');
	ListInsert(L,2,'b');
	ListInsert(L,3,'c');
	ListInsert(L,4,'d');
	ListInsert(L,5,'e');
	
	//3、输出顺序表
	cout<<"\n\n输出顺序表："; 
	DispList(L);
	
	//4、输出顺序表的长度
	cout<<"\n\n顺序表的长度："<<ListLength(L); 
	
	//5、判断顺序表是否为空
	cout<<"\n\n顺序表是否为空："<<(ListEmpty(L)?"是":"否");
	
	//6、输出顺序表的第三个元素
	cout<<"\n\n顺序表的第3个元素：";
	GetElem(L,3);
	
	//7、输出元素c的位置
	cout<<"\n元素c所在位置：";
	LocateElem(L,'c');
	
	//8、在第4个位置插入f元素
	cout<<"\n\n在第4个位置插入f："<<(ListInsert(L,4,'f')? "成功":"失败");
	
	//9、输出顺序表
	cout<<"\n\n输出顺序表：";
	DispList(L);
	
	//10、删除顺序表的第2个元素
	cout<<"\n\n删除顺序表的第2个元素：";
	ListDelete(L,2); 
	
	//11、输出顺序表
	cout<<"\n\n输出顺序表：";
	DispList(L);
	
	//12、释放顺序表
	cout<<"\n\n释放顺序表\n";
	Destroy(L); 
	
	return 0;
} 


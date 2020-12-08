#include<cstdio>
#define MaxSize 100
typedef struct
{
	int data[MaxSize];//
	int length;//the length of set
}Set;
void createset(Set &s,int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		s.data[i]=a[i];
	s.length=n;
}
void add(Set s1,Set s2,Set &s3){//求集合的并集 
	int test[101],i,j,k;
	for(i=0,j=0,k=0;i<s1.length && j<s2.length;){
		while(s1.data[i]<s2.data[j] && i<s1.data[i]) test[k++]=s1.data[i++];
		while(s1.data[i]>s2.data[j] && j<s2.data[j]) test[k++]=s2.data[j++];
		while(s1.data[i]==s2.data[j] && i<s1.length && j<s2.length){
			test[k++]=s1.data[i++]; j++;
		}
	}
	while(i<s1.length)test[k++]=s1.data[i++];
	while(j<s2.length)test[k++]=s2.data[j++];
	createset(s3,test,k);
}
void sub(Set s1,Set s2,Set &s4){//求集合的差集 
	int test[101],i,j,k;
	for(i=0,j=0,k=0;i<s1.length && j<s2.length;){
		while(s1.data[i]<s2.data[j] && i<s1.data[i]) test[k++]=s1.data[i++];
		while(s1.data[i]>s2.data[j] && j<s2.data[j]) test[k++]=s2.data[j++];
		while(s1.data[i]==s2.data[j] && i<s1.length && j<s2.length){
			i++;j++;
		}
	}
	while(i<s1.length)test[k++]=s1.data[i++];
	while(j<s2.length)test[k++]=s2.data[j++];
	createset(s4,test,k);
}
void intersection(Set s1,Set s2,Set &s5){//求集合的交集 
	int test[101],i,j,k;
	for(i=0,j=0,k=0;i<s1.length && j<s2.length;){
		while(s1.data[i]<s2.data[j] && i<s1.data[i++]);
		while(s1.data[i]>s2.data[j] && j<s2.data[j++]);
		while(s1.data[i]==s2.data[j] && i<s1.length && j<s2.length){
			test[k++]=s1.data[i++]; j++;
		}
	}
	createset(s5,test,k);
}
void dispset(Set s)//输出集合的元素
{
	int i;
	for(i=0;i<s.length;i++)
		printf("%5d",s.data[i]);
	printf("\n");
}
int main()
{
	Set s1,s2,s3,s4,s5;
	int a1[]={1,3,5,7,9};
	int a2[]={1,2,3,4,5,6,7,8,9};
	//建立集合s1,s2
	createset(s1,a1,5);
	createset(s2,a2,9);
	//输出s1
	printf("set s1:");
	dispset(s1);
	//输出s2
	printf("\n\nset s2:");
	dispset(s2);
	//输出s3 =s1vs2 
	printf("\ns3=s1∪s2\n");
    add(s1,s2,s3);
    //输出s3 
    printf("\ns3:"); dispset(s3);
    //输出s4=s1-s2 
    printf("\ns4=s1-s2\n");
    sub(s1,s2,s4);
    //输出s4 
    printf("\ns4:"); dispset(s4);
    //输出s5=s1 n s2 
    printf("\ns5=s1∩s2\n");
    intersection(s1,s2,s5);
    //输出s5 
    printf("\ns5:"); dispset(s5);
    
	return 0;
}


#include<cstdio>
int pp(int a[],int left,int right){
	int temp=a[left];
	while(left<right){
		while(left<right && a[right]>temp) right--;
		a[left]=a[right];
		while(left<right && a[left]<=temp) left++;
		a[right]=a[left]; 
	} 
	a[left]=temp;
	return left;
} 
void qqsort(int a[],int left,int right){
	if(left<right){
		int pos = pp(a,left,right);//将a[left]一分为二 
		qqsort(a,left,pos-1);
		qqsort(a,pos+1,right);
	}
}

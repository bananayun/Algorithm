#include<cstdio>
int cou(int w){
	if(w==1)return 1;
	return w-1+w-2;
}
int main(){
	int a;
	scanf("%d",&a);
	a=cou(a);
	printf("%d",a);
} 

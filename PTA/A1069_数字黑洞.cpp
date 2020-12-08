#include<cstdio>
#include<algorithm> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
void trayy(int n,int num[]){
	for(int i=0;i<4;i++){
		num[i]=n%10;
		n/=10;
	}
}
int pp(int num[]){
	int sum=0;
	for(int i=0;i<4;i++){
		sum=sum*10+num[i];
	}
	return sum;
}
int main(){
	int n,max,min;
	scanf("%d",&n);
	int num[5];
	while(1){
		trayy(n,num);
		sort(num,num+4);
		min=pp(num);
		sort(num,num+4,cmp);
		max=pp(num);
		n=max-min;
		printf("%04d - %04d = %04d\n",max,min,n);
		if(n==0 || n==6174) break;
	}
	return 0;
}

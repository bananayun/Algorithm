#include<iostream>
using namespace std;
int a,b,c,s[10]={0},t=0;
int main(){
    cin>>a>>b;
    c=a+b;
    if(c<0){
	c*=-1;
    printf("-");
	};
    while(c>0){
    	s[t++]=c%1000;
    	c/=1000;
	}
	printf("%d",s[--t]);
	while(--t>-1){
		printf(",%03d",s[t]);
	}
}

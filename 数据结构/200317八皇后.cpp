#include<iostream>
#include<cstring>
using namespace std;
int sum=0,d[8][8],R=0,flag=0;

void pr(){//打印 
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(d[i][j]==1)printf("#");
			else printf("+");
		}printf("\n");
	}
	printf("--------------------------\n\n");
}
int f(int a,int b){//判断能否放置 
	for(int i=a;i>=0;i--){//row
		if(d[i][b]==1){
			flag=1;break;
		}
	}
	for(int i=0;i<8;i++){//col
		if(d[a][i]==1){
			flag=1;break;
		}
	}
	for(int i=a,j=b;i>=0&&j>=0;i--,j--){
		if(d[i][j]==1){
			flag=1;break;
		}
	}
	for(int i=a,j=b;i>=0&&j<8;i--,j++){
		if(d[i][j]==1){
			flag=1;break;
		}
	}
	return flag;
}
int pa(int R){//回溯时，判断该行的1在哪 
	for(int i=0;i<8;i++)
		if(d[R][i]==1)return i;
	return -1;
}
int re(int R){
	int i=pa(R)>-1?pa(R):0;
	for(;i<8&&flag!=5;i++){
		if(d[R][i]==1){
			d[R][i]=0;
			if(pa(0)==-1 && i+1==8){
				flag=5;break;
			}
			continue;
		}
		if(f(R,i)==0){
			d[R][i]=1;
			if(R<7)re(R+1);
			else {
				sum++;
				printf("第%d个\n",sum);
				//pr();
				re(R);
			}
		}else flag=0;
	}
	if(flag==5)return sum;
	if(i=8 && R<=8)re(R-1);
}
int main(){
	printf("sum=%d\n",re(0));
	return 0;
}

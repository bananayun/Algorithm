#include<iostream>
#include<cstring>
using namespace std;
int sum=0,d[8][8],che[8][8],R=0,flag=0,n,w=-1;

void pr(){//打印 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i][j]==1)printf("#");
			else printf("+");
		}printf("\n");
	}
	printf("--------------------------\n\n");
}
int f(int a,int b,int c){//判断能否放置 
	for(int i=a;i>=0;i--){//row
		if(d[i][b]==c){
			flag=1;break;
		}
	}
	for(int i=0;i<n;i++){//col
		if(d[a][i]==c){
			flag=1;break;
		}
	}
	for(int i=a,j=b;i>=0&&j>=0;i--,j--){
		if(d[i][j]==c){
			flag=1;break;
		}
	}
	for(int i=a,j=b;i>=0&&j<n;i--,j++){
		if(d[i][j]==c){
			flag=1;break;
		}
	}
	return flag;
}
int pa(int R,int c){//回溯时，判断该行的1在哪 
	for(int i=0;i<n;i++)
		if(d[R][i]==c)return i;
	return -1;
}
int re(int R,int c){
	int i=pa(R,c)>-1?pa(R,c):0;
	for(;i<n&&flag!=5;i++){
		if(d[R][i]==c){
			d[R][i]=0;
			if(pa(0,c)==-1 && i+1==n){
				flag=5;break;
			}
			continue;
		}
		if(f(R,i,1)==0 && che[R][i]==1){
			d[R][i]=c;
			if(R<n-1)re(R+1,c);
			else {
				w*=-1;
				if(w>0)re(0,2);
				sum++;
				//printf("第%d个\n",sum);
				//pr();
				re(R,c);
			}
		}else flag=0;
	}
	if(flag==5)return sum;
	if(i=n && R<=n)re(R-1,c);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)cin>>che[i][j];
	printf("sum=%d\n",re(0,1));
	return 0;
}

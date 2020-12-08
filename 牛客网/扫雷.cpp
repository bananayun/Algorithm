#include<cstdio>
int n,m;
char c[1010][1010];
char v(int q,int w){
    int sum=0;
    if(c[q][w]=='*') return '*';
        if(c[q+1][w]=='*' && q<n)sum++;
        if(c[q+1][w+1]=='*' && q<n && w<m)sum++;
        if(c[q+1][w-1]=='*' && q<n && w>0)sum++;
        if(c[q][w-1]=='*' && w>0)sum++;
        if(c[q][w+1]=='*' && w<m)sum++;
        if(c[q-1][w]=='*' && q>0)sum++;
        if(c[q-1][w-1]=='*' && q>0 && w>0)sum++;
        if(c[q-1][w+1]=='*'&& q>0 && w<m)sum++;
    return (char)sum+'0';
}
int main(){
    scanf("%d%d",&n,&m);
    char a;
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%c",&c[i][j]);
        }
        if(i<n-1)
		 getchar();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",v(i,j));
        }
        if(i<n)printf("\n");
    }
}

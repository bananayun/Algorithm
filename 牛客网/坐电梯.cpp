#include<cstdio>
int n,k,s,w,max=0;
int main(){
    scanf("%d%d",&n,&k);
    getchar();
    for(int i;i<n;i++){
        scanf("%d",&w);
        if(max<w)max=w;
    }
    if(max>k)printf("%d",max-1+(max-k));
    else printf("%d",k-1);
}

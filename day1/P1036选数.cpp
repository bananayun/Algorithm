#include<cstdio>
int n,k,a[21],s=0,ans=0;
bool f[21];
int v(int a){
	for(int i=2;i*i<a;i++){
		if(a%i==0)return 0;
	}
	return 1;
}
void fountion(int w,int b){
	for(int i=b;i<=n;i++){
		f[i]=false;
		s+=a[i];
		if(w==k){
			if(v(s))ans++;
		}else fountion(w+1,i+1);
		s-=a[i];
		f[i]=true;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=true;
	}
	fountion(1,1);
	printf("%d",ans);
	return 0;
}













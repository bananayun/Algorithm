#include<cstdio>
int c[5001];
int main(){
	int n,s,a,b,w,e,count=0,sum=0;
	scanf("%d%d%d%d",&n,&s,&a,&b);
	for(int i=0;i<n;i++){
		scanf("%d%d",&w,&e);
		if(w<=a+b&&e<=s)c[e]++;
	} 
	int t=0,i=0,lg=0;
	for(i=0;i<=n&&sum<s;i++){
		t=c[i];
		while(t--&&sum!=s){
		sum+=i;
		if(sum>s){
			count+=c[i]-t-1;
			lg=1;break;
		}
		}
		if(lg)break;
		count+=c[i];
	}
	printf("%d",count);
} 

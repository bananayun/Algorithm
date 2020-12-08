
#include<cstdio>
#include<algorithm>
using namespace std;

struct showtime{
	int start;
	int end;
}; 

bool cmp(showtime a ,showtime b){
	if(a.end != b.end)	return a.end < b.end;
	else	return a.start > b.start;
}

int main()
{
	showtime show[100010];
	int m,n;
	
	scanf("%d%d",&m,&n);
	
		for(int i = 0;i<n;i++){
			scanf("%d%d",&show[i].start,&show[i].end);
		}
		sort(show,show+n,cmp);
		int i, count = 0;
		int lastend = show[0].end;
		for( i = 0;i < n ;i++){
            if(n<2 && i==0){
                count+=show[i].end-show[i].start+1;
                break;
            }
			else if(lastend <= show[i].start){
				count+=show[i-1].end-show[i-1].start+1;
				lastend = show[i].end;
			}
		}
		printf("%d",count);
	
	
	return 0;
}
 



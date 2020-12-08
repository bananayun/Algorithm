#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct student{
	char id[15];//学号
	int score;//分数
	int number;//考场号
	int rank;//考场内排名 
}stu[30005]; 
bool cmp(student a,student b){
	if(a.score!=b.score) return a.score>b.score;
	else return strcmp(a.id,b.id)<0;
}
int main(){
	int n,t,num=0,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		for(j=0;j<t;j++){
			scanf("%s %d",stu[num].id,&stu[num].score);
			stu[num].number=i;
			num++;
		}
		sort(stu+num-t,stu+num,cmp);
		stu[num-t].rank=1;
		for(j=num-t+1;j<num;j++){
			if(stu[j].score==stu[j-1].score)stu[j].rank=stu[j-1].rank;
			else stu[j].rank=j+1-(num-t);
		}
	}
	printf("%d",num);
	sort(stu,stu+num,cmp);
	int m=1;
	for(i=0;i<num;i++){
		if(i>0&&stu[i].score!=stu[i-1].score) m=i+1;
		printf("\n%s %d %d %d",stu[i].id,m,stu[i].number,stu[i].rank);
	}
}

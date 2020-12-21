#include<cstdio>
#include<cmath>
int main(){
	int a,b;
	double GPA;
	scanf("%d",&a);
	if(a >= 90) GPA = 4.0;
	else if(a >= 60){
		GPA = 4.0 - (90-a)*0.1;
	}
	else{
		b = floor(sqrt(a)*10);
		GPA = 4.0 - (90-b)*0.1;
		if(b < 60) GPA = 0;
	}
	printf("%.1lf",GPA);
	return 0;
}

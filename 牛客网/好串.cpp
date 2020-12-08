//#include<cstdio>
#include<stack>
#include<string>
#include<iostream>
using namespace std;

	stack<char> s;
	stack<char> w;
	char a;
	
int main(){
	string str; 
	getline(cin,str);
	
	for(int i=0;i<str.length();i++)
		s.push(str[i]);
	w.push('q');
	while(s.size()!=0){
		a=s.top();
		w.push(a);
		if(a=='a'&&w.size()>2){
			w.pop();
			w.pop();
		}
		if(w.top()=='a')break;
		s.pop();
	}
	if(w.top()=='q')
	printf("Good");
	else
	printf("Bad");
} 

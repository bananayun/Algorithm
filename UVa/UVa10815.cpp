#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

set<string> de;

int main(){
	string s,buf;
	while(cin>>s){
		for(int i=0;i<s.length();i++)
		if(isalpha(s[i])) s[i]=tolower(s[i]);
		else s[i]=' ';
		stringstream ss(s);
		while(ss>>buf) de.insert(buf);
	}
	for(set<string>::iterator it=de.begin();it!=de.end();it++)
		cout<<*it<<endl;
		return 0;
} 

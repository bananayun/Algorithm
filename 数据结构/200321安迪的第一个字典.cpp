#include<iostream>
#include<cstring>
#include<set>
#include<sstream>
using namespace std;
set<string>dict;
int main(){
	string s,but;
	while(cin>>s){
		for(int i=0;i<s.length();i++)
			if(isalpha(s[i]))s[i]=tolower(s[i]);else s[i]=' ';
		stringstream ss(s);
		while(ss>>but)dict.insert(but);
	}
	for(set<string>::iterator it=dict.begin();it!=dict.end();++it)
		cout<<*it<<"\n";
		return 0;
}

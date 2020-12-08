#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node{
	double num;  //������
	char op;     //������
	bool flag;   //true��ʾ��������false��ʾ������ 
};

string str;
stack<node> s;//������ջ
queue<node> q;//��׺�������
map<char,int> op; 

void change(){//����׺���ʽת��Ϊ��׺���ʽ
	double num;
	node temp;
	for(int i=0;i<str.length();){
		if(str[i]>='0' && str[i]<='9'){
			temp.flag=true; //���������
			temp.num =str[i++]-'0';
			while(i<str.length() && str[i]>='0' && str[i]<=9){
				temp.num=temp.num*10+(str[i]-'0');//������������� 
				i++;
			}  
			q.push(temp); //�����������ѹ���׺���ʽ�Ķ��� 
		}else{
			temp.flag=false; //����ǲ�����
			//ֻҪ������ջ��ջ��Ԫ�رȸò��������ȼ��ߣ�
			//�ͰѲ�����ջջ��Ԫ�ص�������׺���ʽ�Ķ�����
			while(!s.empty() && op[str[i]]<=op[s.top().op]){
				q.push(s.top());
				s.pop();
			} 
			temp.op=str[i];
			s.push(temp);//�Ѹò�����ѹ�������ջ�� 
			i++;
		} 
	} 
	//���������ջ�л��в��������Ͱ�����������׺���ʽ������
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}
	
}
double cal(){//�����׺���ʽ 
	double temp1,temp2;
	node cur,temp;
	while(!q.empty()){
		cur=q.front(); //cur��¼����Ԫ��
		q.pop();
		if(cur.flag==true) s.push(cur);//����ǲ�������ֱ��ѹ��ջ
		else{
			temp2 = s.top().num; //�����ڶ�������
			s.pop() ;
			temp1 = s.top().num;//������һ������
			s.pop();
			temp.flag=true;    //��ʱ��¼������
			if(cur.op=='+')temp.num=temp1+temp2;
			else if(cur.op=='-')temp.num=temp1-temp2;
			else if(cur.op=='*')temp.num=temp1*temp2;
			else temp.num=temp1/temp2;
			s.push(temp);//�Ѹò�����ѹ��ջ 
		} 
	}
	return s.top().num;//ջ��Ԫ�ؾ��Ǻ�׺���ʽ��ֵ 
}
int main(){
	op['+']=op['-']=1;
	op['*']=op['/']=2;
	while(getline(cin,str),str!="0"){
		for(string::iterator it = str.end();it!=str.begin();it--){
			if(*it==' ')str.erase(it);
		}
		while(!s.empty())s.pop();//��ʼ��ջ
		change();
		printf("%.2f\n",cal()); 
	} 
	return 0;
} 

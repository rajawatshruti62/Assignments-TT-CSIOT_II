#include<stdlib.h>
#include <bits/stdc++.h> 
using namespace std;
//Valid Parenthesis
#define MAX 100000
class Solution {
    private:
    char getmatch(char ch){
	char match;
	switch(ch){
		case ')':
		match='(';
		break;
		case '}':
			match='{';
			break;
		case ']':
			match='[';
			break;
	}
	return match;
}
public:
    bool isValid(string exp) {
        int stack[MAX];
        int top=-1;
        int i=0;
	char ch;
	while(exp[i]){
		if(exp[i]=='('|| exp[i]=='{' ||exp[i]=='['){
			stack[++(top)]=exp[i];
		}
		else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
			if(top==-1){
			return false;
			}
			ch=stack[(top)--];
			if(ch!=getmatch(exp[i])){
				return false;
				return 0;
			}
		}
		++i;
	}
	if(top!=-1){
		return false;
	}
	else
	return true;
}

};
int main(){
	int n;
	string s;
	cin>>n;
	while(n){
		cin>>s;
		Solution obj;
		if(obj.isValid(s))
		cout<<"Valid"<<'\n';
		else
		cout<<"Invalid"<<'\n';
		n--;
		
	}
}
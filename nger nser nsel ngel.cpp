#include <bits/stdc++.h> 
using namespace std; 
//next greater element to right
vector<int> nextGreaterElementToRight(int arr[], int n) {
	stack<int> st;
	vector<int> res;

	for(int i = n - 1; i >= 0; i--) {
	    while(!st.empty() && st.top() <= arr[i]) {
			st.pop();
		}
		if(st.empty()) {
		    res.push_back(-1);
		}
		else  {
		    res.push_back(st.top());
		}
		st.push(arr[i]);
	}
	reverse(res.begin(), res.end());
	return res;
}
//next smallest element to right
vector<int> nextSmallestElementToRight(int arr[], int n) {
	stack<int> st;
	vector<int> res;

	for(int i = n - 1; i >= 0; i--) {
	    while(!st.empty() && st.top()>=arr[i]) {
			st.pop();
		}
		if(st.empty()) {
		    res.push_back(-1);
		}
		else  {
		    res.push_back(st.top());
		}
		st.push(arr[i]);
	}
	reverse(res.begin(), res.end());
	return res;
}
//next smallest element to left
vector<int> nextSmallestElementToLeft(int arr[], int n) {
	stack<int> st;
	vector<int> res;

	for(int i =0; i <n; i++) {
	    while(!st.empty() && st.top()>=arr[i]) {
			st.pop();
		}
		if(st.empty()) {
		    res.push_back(-1);
		}
		else  {
		    res.push_back(st.top());
		}
		st.push(arr[i]);
	}
	return res;
}
//next greater element to left
vector<int> nextGreatestElementToLeft(int arr[], int n) {
	stack<int> st;
	vector<int> res;

	for(int i =0; i <n; i++) {
	    while(!st.empty() && st.top()<=arr[i]) {
			st.pop();
		}
		if(st.empty()) {
		    res.push_back(-1);
		}
		else  {
		    res.push_back(st.top());
		}
		st.push(arr[i]);
	}
	return res;
}
int main() {

	int arr[] = {9,7,2,5,8};  
	vector<int> nger = nextGreaterElementToRight(arr,sizeof(arr)/sizeof(arr[0])); 
	vector<int> nser = nextSmallestElementToRight(arr,sizeof(arr)/sizeof(arr[0]));
	vector<int> nsel = nextSmallestElementToLeft(arr,sizeof(arr)/sizeof(arr[0])); 
	vector<int> ngel = nextGreatestElementToLeft(arr,sizeof(arr)/sizeof(arr[0])); 
	cout<<"next Greater Element To Right"<<'\n';
	for (int a: nger) {
		cout << a << " ";
	}
	cout<<"next Smallest Element To Right"<<'\n';
	for (int a: nser) {
		cout << a << " ";
	}
	cout<<"next Smallest Element To Left"<<'\n';
	for (int a: nsel) {
		cout << a << " ";
	}
	cout<<"next greatest Element To Left"<<'\n';
	for (int a: ngel) {
		cout << a << " ";
	}
}
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
		if(isValid(s))
		cout<<"Valid"<<'\n';
		else
		cout<<"Invalid"<<'\n';
		n--;
	}
}

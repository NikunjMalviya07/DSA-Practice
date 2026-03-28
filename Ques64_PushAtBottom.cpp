#include<iostream>
#include<stack>
#include<string>

using namespace std;

void printStack(stack<char> &s){
    while(!s.empty()){
        cout<<s.top()<<"";
        s.pop();
    }
}

void pushAtBottom(stack<int> &s, int n){

    if(s.empty()){
        s.push(n);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s,n);
    s.push(temp);
}

string reverseAString(string str){
    string ans;
    stack<char> s;
    
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main(){
    string str = "abcd";
    cout << reverseAString(str);

    return 0;
}
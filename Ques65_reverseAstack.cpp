#include<iostream>
#include<stack>
#include<string>

using namespace std;

void printStack(stack<int> &s){
    while(!s.empty()){
        cout<<s.top()<<" ";
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

void reverseAstack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverseAstack(s);
    pushAtBottom(s,temp);

}

int main(){
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);

    reverseAstack(s);
    printStack(s);
}
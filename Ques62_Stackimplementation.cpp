#include<iostream>
#include<vector>

using namespace std;

template<class T>
class stack{
    vector<T> v;
public:
    void push(int n){
        v.push_back(n);
        return;
    }

    void pop(){
        v.pop_back();
        return;
    }

    int top(){
        int n = v.size() - 1;
        return v[n];
    }

    bool isEmpty(){
        return v.size() == 0;
    }
};

int main(){
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.isEmpty()){
        cout<< s.top();
        s.pop();
    }
}
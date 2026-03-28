#include<iostream>
using namespace std;
    // sum of natural number...
int sum(int n){
    if(n==0){
    return 0;
    }
    return n + sum(n-1);
}

    // nth fibonacci
int fib(int n){
    // if(n==0){return 0;}
    // if(n==1){return 1;}
    if(n==0 || n==1){return n;} // good way... b
    return fib(n-1) + fib(n-2);
    
}

    // fibonacci series...
void fib1(int n, int a, int b){
    if(n==0 || n<0){
        return;
    }
    cout<<a + b<<" ";
    fib1(n-1 , b , a + b);
}

int main(){

    cout<<0<<" "<<1<<" ";
    fib1(4 , 0 , 1);
    
}
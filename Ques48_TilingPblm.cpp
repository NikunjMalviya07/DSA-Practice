#include<iostream>
using namespace std;

int tilingPblm(int n){
    if( n == 0 || n==1){
        return 1;
    }

    return tilingPblm(n-1) + tilingPblm(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<tilingPblm(n);
}
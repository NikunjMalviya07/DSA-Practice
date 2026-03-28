#include<iostream>
using namespace std;

void printTable(int n){
    int multiple;
    for(int i=1;i<=10;i++){
        cout<< n << "*"<< i << " = "<< n*i << "\n"; 
    }

    return ;
}

int main(){
    int n;
    cout<<"Enter the number n : ";
    cin>>n;

    printTable(n);
}
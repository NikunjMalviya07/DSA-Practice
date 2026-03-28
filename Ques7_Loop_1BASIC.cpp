#include<iostream>
using namespace std;
int main(){
    // Basic 
    for(int i=0;i<5;i++){
        cout<<"Nikunj Malviya \n";
    } 
    // More Basic
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    // Moderate
    int n=10829;
    int sum=0;
    while(n!=0){
        int digit = n%10;
        n/=10;
        sum +=digit;
        cout<<digit;
    }
    cout<<"\n"<<sum;
    cout<<endl;
}
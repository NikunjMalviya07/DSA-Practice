#include<iostream>
using namespace std;

void printPattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}

void printPattern_2(int n){
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}

void printPattern_3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}

void printPattern_4(int n){
    for(int i=1;i<=n;i++){
        // space loop
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        // star loop
        for(int k=1;k<=i;k++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    printPattern_4(n);
}
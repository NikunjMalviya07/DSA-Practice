#include<iostream>
using namespace std;
    // print Palindromic Pattern
void printPattern(int n){
    for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i;j++) {cout<<" ";}
    for(int j=i;j>=1;j--) {cout<<j;}
    for(int j=2;j<=i;j++) {cout<<j;}
    cout<<"\n";
    }
}

void printPattern_2(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1;j<=i;j++){
            if((i+j)%2==0){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
        cout << endl;
    }
}

void printPattern_3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=n;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    
    printPattern_2(n);
}
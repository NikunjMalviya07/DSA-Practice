#include<iostream>
using namespace std;
    // hollow triangle
void printPattern(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j== 0 || j== n-1){
                cout<<"* ";
            } else {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
    // diamond pattern
void printPattern_2(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<n;j++){
            cout<<" ";
        }
        for(int k=1;k<=2*i-1;k++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<n-i+1;j++){
            cout<<" ";
        }
        for(int k=2*i-1;k>=1;k--){
            cout<<"*";
        }
        cout<<"\n";
    }
}


int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;

    printPattern_2(n);
}
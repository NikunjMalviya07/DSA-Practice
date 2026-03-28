#include<iostream>
using namespace std;

void printPattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<"";
        }
        cout<<"\n";
    }
 }
 void printPattern_2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<"";
        }
        cout<<"\n";
    }
 }

 void printPattern_3(int n){
    int character = 65;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<char(character)<<"";
            character++;
        }
        cout<<"\n";
    }
 }
    //floads triangle
  void printPattern_4(int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num<<" ";
            num++;
        }
        cout<<"\n";
    }
 }
 int main(){
    int n;
    cout<<"Enter n :";
    cin>>n;

    printPattern_4(n);
 }

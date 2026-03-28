#include<iostream>
using namespace std;

int main(){
    int year;
    cout<<"Enter Year : ";
    cin>>year;

    if(year>0 && year%100!=0){
        if(year % 4 == 0){
            cout << year << " is leap year.";
        } else {
            cout << year << " is not leap year";
        }
    } else if(year % 100 == 0){
        if(year % 400 == 0)
        cout << year << " is leap year.";
        else{
            cout << year << " is not leap year.";
        }
    }
}
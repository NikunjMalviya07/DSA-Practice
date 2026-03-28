#include<iostream>
using namespace std;

int reverseANumber(int n){
    int digit;
    int num=0;
    while(n!=0){
        digit=n%10;
        num = num * 10 + digit;
        n/=10;
    }

    return num;
}

int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;

    int ans = reverseANumber(n);
    cout << "Reverse of "<< n << " is " << ans ;
}
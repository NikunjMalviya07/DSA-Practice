#include<iostream>
using namespace std;

int printOddDigit(int n){
    int sum=0;
    while(n!=0){
        int digit=n%10;
        n/=10;
        int oddDigit;
        if(digit%2==1){
            oddDigit=digit;
            sum+=oddDigit;
        }
    }
    return sum;
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    int ans = printOddDigit(n);
    cout<<"Sum of ODD digit is : "<<ans;
}
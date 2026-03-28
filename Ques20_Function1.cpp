#include<iostream>
using namespace std;
    // check  palindrome :-
void checkPalindrome(int n){
    int num = n;
    int reverse = 0;
    while(n!=0){
        int digit;
        digit = n%10;
        n/=10;
        reverse = reverse*10+digit;
    }
    if(num = reverse) cout<< num << " is a palindrome.";
    else cout << num << " is not a palindrome.";
}

int main(){
    int n;
    cout<<"Enter number n : ";
    cin>>n;
}
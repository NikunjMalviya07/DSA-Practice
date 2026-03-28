#include<iostream>
#include<cmath>
using namespace std;

void binaryToDecimal(int n){
    int binNum = n;
    int digit;
    int decimalNum = 0;
    int power = 0;
    while (n!=0){
        digit = n%10;
        n/=10;
        decimalNum =decimalNum + digit*pow(2,power++);
    }
    cout << "Decimal Form of " << binNum << " is : " << decimalNum;
}

void deciToBinary(int n){
    int decNum = n;
    int rem = 0;
    int pow = 1;
    int binNum = 0;
    while(n>0){
        int decNum = n;
        rem = n%2;
        binNum +=rem * pow;
        n=n/2;
        pow = pow * 10;
    }
    cout<< "Binary Form of " << decNum << " is : " << binNum;
}

int main(){
    int n;
    cout << "Enter Number n : ";
    cin >> n;

    deciToBinary(n);
}
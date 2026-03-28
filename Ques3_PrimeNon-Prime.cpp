#include<iostream>
#include<cmath>
using namespace std;

void checkPrime(int num){
    if(num<=1){
        cout<<num<<" is not a prime number.";
    }

    bool isPrime = true;

    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            isPrime = false;
            break;
        }
    }

    if(isPrime){
        cout<<num<<" is a prime number.";
    }
    if(!isPrime){
        cout<<num<<" is not a prime number.";
    }
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    checkPrime(n);

}
#include<iostream>
#include<cmath>

using namespace std;
void printPrimeNumber(int n){
    bool isPrime = true;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            cout<<i<<" ";
        }
        isPrime = true;
        
    }
    return ;
}

int main(){
    int n;
    cout<<"Enter the number n : ";
    cin>>n;

    printPrimeNumber(n);
}
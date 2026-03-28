#include<iostream>
using namespace std;

int printFactorial(int n){
    int factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i;
    }

    return factorial;

}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    int ans = printFactorial(n);
    cout<<"Factorial of 'n' i.e n! = " << ans;
    
}
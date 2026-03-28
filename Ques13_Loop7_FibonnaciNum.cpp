#include <iostream>
#include <cmath>

using namespace std;
void printFibonacciSeries(int n){
    int num1 = 0;
    int num2 = 1;
    int sum = 0;
    if(n==0){
        cout<<"Invalid Input";
    } else if(n==1){
        cout<<0;
    } else if(n==2){
        cout<<0<<" "<<1;
    } else {
        cout<<0<<" "<<1<<" ";
        for(int i=0;i<n-2;i++){
        sum = num1+num2;
        num1 = num2;
        num2 = sum;
        cout<<sum<<" ";
        }
    }
}

void printFibonacciSeries_2(int n) {
    int num1 = 0, num2 = 1, sum;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << num1 << " ";
        } else if (i == 1) {
            cout << num2 << " ";
        } else {
            sum = num1 + num2;
            cout << sum << " ";
            num1 = num2;
            num2 = sum;
        }
    }
}


int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;

    printFibonacciSeries(n);
    cout<<endl;
    printFibonacciSeries_2(n);

}

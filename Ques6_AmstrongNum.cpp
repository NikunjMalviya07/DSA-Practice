#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cout<<"Enter a 3 digit number : ";
    cin>>n;
    int num=n;
    int sum;

    if(n>=100 && n<=999){
        int dig_1 = n%10;
        n/=10;
        dig_1 = pow(dig_1,3);
        
        int dig_2 = n%10;
        n/=10;
        dig_2 = pow(dig_2,3);

        int dig_3 = n%10;
        n/=10;
        dig_3 = pow(dig_3,3);

        sum = dig_1+dig_2+dig_3;

        if(num == sum){
        cout << num <<" is a Amstrong Number...";
    } else {
        cout << num << " is NOT a Amstrong Number...";
    }

    } else{
        cout<<"Invalid Input...";
    }

    return 0;
}
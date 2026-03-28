#include<iostream>
using namespace std;

int fastExpo(int num , int power){
    int lastDigit = 0;
    int ans = 1;
    int x = num;
    while(power>0){
        lastDigit = (power & 1);
        if(lastDigit == 1) {ans = x*ans;}
        x*=x;
        power=(power>>1);
    }

    return ans;
}

int main(){
    int ans = fastExpo(3,5);
    cout << ans;
}
#include<iostream>
#include<vector>

using namespace std;
    // time complexity O(n)
int powerN(int x , int n){
    if(n==1){
        return x;
    }
    return x * powerN(x,n-1);

}

    // time complexity O(logn)
int power(int x, int n){
    if(n==0){
        return 1;
    }
    
    int halpow = power(x, n/2);
    int halfpowsq = halpow * halpow;
    if(n%2!=0){
        // odd
        return x*halfpowsq;
    }
    return halfpowsq;
} 
int main(){
    int ans = power(2 , 10);
    cout<<ans;
}
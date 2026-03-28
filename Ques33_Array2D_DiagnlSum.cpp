#include<iostream>
using namespace std;
    // Sum of Diagonal Element
int sumOfDiagonal(int arr[][5] , int n ,int m){
    int sum = 0;
    for(int i=0;i<n;i++){
            sum+=arr[i][i];
    }
    for(int i=0; i<n; i++){
        sum += arr[i][n-1-i];
        if(i==n-i-1){
            sum -= arr[i][n-i-1];
        }
    }

    return sum;
}
int main(){
    int n = 5;
    int m = 5;
    int arr[][5] = {{1,2,3,4,5},
                   {5,6,7,8,9},
                   {9,10,11,12,13},
                   {13,14,15,16,17},
                   {18,19,20,21,22},
                };
    int ans = sumOfDiagonal(arr , n , m);
    cout << ans;
}
#include<iostream>
using namespace std;

    //  Using Recursion
int binarySearch(int arr[] , int left_ptr, int right_ptr , int k){

    if (left_ptr > right_ptr)
        return -1;

    int mid = (left_ptr + right_ptr)/2;
    // base case

    if( arr[mid] == k){ return mid;}

    else if(arr[mid] > k){ 
        return binarySearch(arr ,left_ptr , mid-1, k);
    }
    
    else if (arr[mid] < k ){
        return binarySearch(arr , mid + 1 , right_ptr , k);
    }
    return - 1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(int);

    int lp = 0;
    int rp = size - 1;
    int k = 8;
    int ans = binarySearch( arr , lp , rp , k);
    cout << ans ;
}
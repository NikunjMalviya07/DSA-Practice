#include<iostream>
using namespace std;

void printKeyIndices(int arr[] , int size , int i , int k ){
    if( i == size){
        return;
    }

    if(arr[i] == k){
        cout<<i<<" ";
    }

    printKeyIndices(arr ,size , i+1 , k );
    return;
}

int main(){
    int arr[] = {3,2,4,5,6,2,7,2,2};
    int size = sizeof(arr)/sizeof(int);
    // cout<<size;
    int i = 0;
    int k = 2;
    printKeyIndices(arr, size , i , k);
}
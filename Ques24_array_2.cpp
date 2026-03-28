#include<iostream>
using namespace std;
    // reverse array using extraspace
void reverseAnArray(int arr[] , int n){
    int revArray[n];
    for(int i=0;i<n;i++){
        revArray[i] = arr[n-1-i];
    }
    for(int i=0;i<n;i++){
        cout << revArray[i] << " ";
    }
    cout <<endl;
}
    // putting garbage values in my arr;
void reverseAnArray_2(int arr[],int n){
    int garbageArray[n];
    for(int i=0;i<n;i++){
        arr[i] = garbageArray[i];
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout <<endl;
}

    // reverse an array without creationg any other space;
void reverseAnArray_3(int arr[] , int n){
    int ptr_1 = n-1;
    int ptr_2 = 0;

    while(ptr_2<=ptr_1){
        int rev = arr[ptr_2];
        arr[ptr_2++] = arr[ptr_1];
        arr[ptr_1--] = rev;
        // or you can swap ...
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
    
int main(){
    int arr[] = {2,6,7,2,65,9};
    int n = sizeof(arr)/sizeof(int);
    reverseAnArray_3(arr , n);
}
#include<iostream>
using namespace std;
    // BinarySearch
int binarySearch(int arr[], int n , int key){
    int ptr1 = n-1; // end
    int ptr2 = 0; // start
    while(ptr2<=ptr1){
        int mid = (ptr1+ptr2)/2;
        if(arr[mid] == key) {return mid; break;}
        else if (arr[mid] < key) {ptr2 = mid+1;}
        else if (arr[mid] > key) {ptr1 = mid -1;}
    }
    return -1;
}

int main(){
    int arr[] = {0,2,4,6,8,10,12,14,16,18,20};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cout << "Enter key :";
    cin>>key;
    int ans = binarySearch(arr , n , key);
    cout << ans;
}
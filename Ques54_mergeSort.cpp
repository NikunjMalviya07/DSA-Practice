#include<iostream>
#include<vector>

using namespace std;

void merge(int arr[] , int si , int mid , int ei){
    vector<int> temp;
    int i = si;
    int j = mid +1;
    while (i<= mid && j<=ei){
        if(arr[i] < arr[j]){
            temp.push_back(arr[j++]);
        } else {
            temp.push_back(arr[i++]);
        }
    }

    while (i<=mid){
        temp.push_back(arr[i++]);
    } 
    while (j<=ei){
        temp.push_back(arr[j++]);
    }
    int x = 0;
    for(int i=si ; i <= ei; i++){
        arr[i] = temp[x++];
    }
}

void mergeSort(int arr[] , int si , int ei){
    
    int mid = si + (ei - si )/2;

    if(si>=ei){return;} // base case

    mergeSort(arr , si , mid );
    mergeSort(arr , mid + 1 , ei);
    merge (arr , si , mid , ei);
}

void printArr(int arr[] , int n){
    
    for( int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}

int main (){
    int arr [] = { 6,3,7,5,2,4};
    int n = 6;
     
    mergeSort(arr , 0 , n-1);
    printArr(arr , n);
}
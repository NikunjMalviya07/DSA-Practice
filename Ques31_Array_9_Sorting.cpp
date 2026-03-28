#include<iostream>
using namespace std;
    // Bubble Sort Algorithm
void bubbleSort(int *arr , int n){
    for(int i=0;i<n;i++){
        bool isSwap = false;
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                // swap(arr[i],arr[j]);
                int num = arr[j];
                arr[j] = arr[i];
                arr[i] = num;
                isSwap = true;
            }
        }
        if(!isSwap){
            // arr is alrdy sorted 
            return;
        }
    }
}

    // Selection Sort;
void selectionSort(int *arr, int n){
    for( int i = 0 ; i < n ; i++ ){
        int minIdx = i;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
            swap(arr[i],arr[minIdx]);
        }
    }
}
    // Insertion Sort
void insertionSort(int *arr , int n ){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while (prev>=0 && arr[prev] > curr){
            swap(arr[prev] , arr[prev+1]);
            prev--;
        }
        // arr[prev+1] = curr; only essential when shifting of elements
    }
}

void insertionSort2(int *arr , int n){
    for(int i = 0; i<n;i++){
        int curr = arr[i];
        int prev = i -1;
        while(prev >=0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr; // necessary because of shifting 
    }
}
    // counting sort
void countingSort(int *arr , int n){
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for(int i=0;i<n;i++){
        minVal = min(minVal , arr[i]);
        maxVal = max(maxVal , arr[i]);
    }
    // step 1 to make a frequesncy array..
    int freq[100000] = {0} ;

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    // step 2 is to add 
    for(int i = minVal , j=0 ; i<=maxVal ; i++){
        while(freq[i]>0){
        arr[j++] = i;
        freq[i] --;
        }
    }
} 
int main(){
    int arr[] = {5,1,4,3,2};
    int n = sizeof(arr)/sizeof(int);
    insertionSort2(arr , n);
    for(int i=0;i<n;i++){
        cout << arr[i]<<" "; 
    }
}
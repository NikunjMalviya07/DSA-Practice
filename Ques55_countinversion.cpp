#include<iostream>
#include<vector>
using namespace std;

int merge(int arr[] , int si , int mid , int ei){
    int i = si;
    int j  = mid +1;
    int invCount = 0;
    
    vector<int> temp;

    while(i<= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
            invCount += mid - i + 1;
        }
    }

    while(i<= mid){
        temp.push_back(arr[i++]);
    }
    while(j<= ei){
        temp.push_back(arr[j++]);
    }

    int x = 0;
    for(int i=si;i<=ei;i++){
        arr[i] = temp[x++];
    }
    return invCount;
}

int mergeSort(int arr[] , int si,  int ei){
    int mid = si + (ei - si)/2;
    int invCount = 0;
    if(ei > si){
        invCount += mergeSort(arr , si , mid ); // left side
        invCount += mergeSort(arr, mid + 1, ei); // right side
        invCount += merge(arr , si , mid , ei);
    } 

    return invCount;
}

int getInversion(int arr[] , int n){
    return mergeSort(arr , 0 , n-1);
}

int main(){
    int arr[] = {2,4,3,1,5};
    int n = sizeof(arr)/sizeof(int);

    int ans = getInversion(arr , n);
    cout << ans;
}

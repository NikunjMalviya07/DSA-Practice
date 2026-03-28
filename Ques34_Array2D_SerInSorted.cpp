#include<iostream>
using namespace std;
    // brute force code
void searchInSorted1(int arr[][5],int n,int m ,int key){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == key){
                cout << i <<","<< j;
            }
        }
    } 
}
    // optimised code using Binary search
void searchInSorted2(int arr[][5], int n,int m,int key){
    for(int i=0;i<n;i++){
        int ptr1 = 0;
        int ptr2 = m-1;
        while (ptr1<=ptr2)
        {
            int mid = (ptr1+ptr2)/2;
            if(arr[i][mid] == key){
                cout << i <<"," << mid;
                break;
            }
            else if(arr[i][mid] > key){
                ptr2 = mid - 1;
            }
            else if(arr[i][mid] < key){
                ptr1 = mid + 1;
            }
        }
    }
}

    // best method stair case search
bool stairCase(int arr[][5] , int n , int m , int key){
    int i = 0;
    int j = m-1;
    while(i<n && j>=0){
        if(arr[i][j] == key){
            return true;
        } else if(arr[i][j] > key ){
            j = j-1;
        } else if(arr[i][j] < key){
            i = i-1;
        }
    }
    return false;
}
int main(){
    int n = 5;
    int m = 5;
    int key = 100;
    int arr[][5] = {{1,2,3,4,5},
                   {5,6,7,8,9},
                   {9,10,11,12,13},
                   {13,14,15,16,17},
                   {18,19,20,21,22},
                };
    int ans = stairCase(arr , n , m ,key);
    cout << ans;
}
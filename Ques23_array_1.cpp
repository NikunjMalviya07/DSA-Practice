#include<iostream>
using namespace std;

void linearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            cout << i ;
        }
    }    
}

int main(){
    int arr[] = {1,5,6,8,9,2,7,22,52,8};
    int n = sizeof(arr)/sizeof(int);

    int  key;
    cout << "Enter Numbre : ";
    cin>> key;

    linearSearch(arr , n , key);
}


#include<iostream>
using namespace std;
    // subarray;
void printAllSubArray(int *arr, int n ){
    cout <<"Total no. subarrays are : ";
    cout << (n*(n+1))/2 << endl;
    cout << "Total subarrays are : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout <<""<<arr[k];
            }
            cout <<", ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);

    printAllSubArray(arr,n);
}
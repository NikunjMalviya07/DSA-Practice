#include<iostream>
using namespace std;
    // Max Subarray Sum Print.... WITH BRUTHE FORCE TC:n^(3);
void printMaxSubarraySum(int *arr, int n){
    int sum;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum = 0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
            }
            // if(sum > maxSum){maxSum = sum;}
            maxSum = max(maxSum , sum);
        }
    }
    cout << "Max subarray sum : "<< maxSum;
}

    // Max Subarray Sum Print... WITH OPTIMISED VERSION TC:n^(2);
void printMaxSubarraySum2(int arr[],int n){
    int sum;
    int maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=i;j<n;j++){
            sum+= arr[j];
        }
        maxSum = max(maxSum , sum);
    }
    cout << "Max subarray sum : "<< maxSum;
}

    // Kadane's Algorithm TC:n^(1);
void kadaneAlgorithm(int *arr,int n){
    int curSum;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        curSum +=arr[i];
        maxSum = max(maxSum , curSum);
        if(curSum < 0){curSum = 0;}
    }
    cout << "Max subarray sum : "<< maxSum;
}
int main(){
    int arr[] = {2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    kadaneAlgorithm( arr,  n);
}
#include<iostream>
#include<vector>

using namespace std;

    // is array sorted...
bool isSorted(int arr[], int n , int i){
    if(i==n-1){
        return true;
    }
    if(arr[i]>arr[i+1]){
        return false;
    }
    return isSorted(arr, n, i+1); 
    
}
    // first occurance...
int firstOcc(vector<int> &v, int target ,int i){
    if( i == v.size() ){ return -1;}
    if(v[i] == target){ return i;}
    
    return firstOcc(v,target, i+1);
   
}

    // last occurance...
int lastOcc(vector<int> &v, int target ,int i){
    if(i==v.size()){ return -1;}
    int idxfound = lastOcc(v,target,i+1);
    if(idxfound == -1 && v[i] == target){
        return i;
    }

    return idxfound;
   
}

int main(){
    vector<int> v = {1,2,3,3,3,4};
    int target = 3;
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {1,2,6,4,5};
    // cout<<isSorted(arr1,5,0);
    int ans =  lastOcc(v,target,0); // 3
    cout<<ans<<endl;
}
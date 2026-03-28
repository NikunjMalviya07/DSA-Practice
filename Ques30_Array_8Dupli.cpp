#include<iostream>
using namespace std;
    // Duplicate num
bool containsDuplicate(int *nums,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int nums[] = {1,2,3,3,4};
    int n = sizeof(nums)/sizeof(int);
    int ans = containsDuplicate(nums,n);
    cout << ans;
}

#include<iostream>
using namespace std;

int clearTheRange(int num, int i, int j){
    int bitMask = ( (~0<<(j+1)) | ((1<<i) - 1) );
    int ans = (bitMask & num);
    return ans;
}
int main(){
    int ans = clearTheRange(31,1,3);
    cout<<ans;
}
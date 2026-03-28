#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

void nextGraterElement(vector<int> &v){
    stack<int> s;
    int n = v.size();

    vector<int> ans(n,-1);
    s.push(v[n-1]);

    for(int i = n-1; i>=0;i--){
        while(!s.empty() && s.top()<=v[i]){
            s.pop();
        }

        if(s.empty()){ // corner case
            ans[i] = -1;
        } else{
            ans[i] = s.top();
        }

        s.push(v[i]);
    }
    for(int i:ans){
        cout<<i<<" ";
    }
    return;

}
int main(){
    vector<int> v = {6,8,0,1,3};
    nextGraterElement(v);
    return 0;
}
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int nextSmaller(vector<int> height , int ri){
    stack<int> s;
    int n = height.size();

    for(int i = n-1; i > ri; i--){
        s.push(height[i]);
    }

    int i;
    for(i = ri+1 ; i<=n-1 ; i++ ){

        while(!s.empty() && s.top()>= height[ri]){
            s.pop();
        }

        if(s.empty()){
            return ri+1;
        } 
        if(s.top() < height[ri]){
            return i;
        }
    }

    return i;
}

int prevSmaller(vector<int> height , int li){
    stack<int> s;
    int n = height.size();
    int i;
    for(i = 0; i < li; i++){
        s.push(height[i]);
    }

    for(int i= li-1; i>=0 ;i++){

        while(!s.empty() && s.top()>= height[li]){
            s.pop();
            i-=1;
        }

        if(s.empty()){
            return li-1;
        } 
        if(s.top() < height[li]){
            return i;
        }
    }

    return i;

}

int areaOfHistogram(vector<int> &height){

    int n = height.size();

    int area = 0;
    int maxArea = 0;

    for(int i=0;i<n;i++){
        
        area = height[i]*( (nextSmaller(height , i)) - (prevSmaller(height, i)) - 1 );
        maxArea = max(area,maxArea);

    }

    return maxArea;
}

int main(){
    vector<int> height = {2,1,5,6,2,3};
    cout<<areaOfHistogram(height);
}
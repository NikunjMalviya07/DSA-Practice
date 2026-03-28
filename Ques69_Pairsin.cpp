#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int, int> p2){
    return p1.second < p2.second; // ascending
}

int main(){
    vector<int> start = {0,1,2};
    vector<int> end = {9,2,4};

    vector<pair<int,int>> pairs(3, make_pair(0,0));

    pairs[0] = make_pair(0,9);
    pairs[1] = make_pair(1,2);
    pairs[2] = make_pair(2,4);

    sort(pairs.begin(), pairs.end(), compare);

    for(int i=0;i< start.size();i++){
        cout<< pairs[i].first << ", "<< pairs[i].second<<endl;
    }
    return 0;
}
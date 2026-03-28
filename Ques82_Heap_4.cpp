#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int connecrNRopes(vector<int> ropes){
    // Creating a Min-Heap using priority_queue
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end()); // O(n)
    int cost = 0;

    while(pq.size() > 1) {
        // Step 1: Pick the two smallest ropes
        int min1 = pq.top();
        pq.pop();
        
        int min2 = pq.top();
        pq.pop();

        // Step 2: Add their sum to total cost and push back into heap
        cost += min1 + min2;
        pq.push(min1 + min2);
    }

    cout << "min cost = " << cost << endl;
    return cost;

} 

int main(){
    vector<int> ropes = {4,3,2,6};
    connecrNRopes(ropes);
    return 0;
}
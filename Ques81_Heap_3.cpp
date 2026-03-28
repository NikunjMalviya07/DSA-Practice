#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Car{
    public:
    int idx;
    int dist;

    Car(int idx, int dist){
        this->dist = dist;
        this->idx = idx;
    }

    bool operator < (const Car &obj) const {
        return this->dist > obj.dist;
    }
};

void nearByCars(vector<pair<int,int>> pos , int K){
    vector<Car> cars;

    for(int i = 0; i < pos.size(); i++){
        int dist = (pos[i].first*pos[i].first) + (pos[i].second*pos[i].second);
        cars.push_back(Car(i, dist));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());

    for(int i=0;i<K;i++){
        cout<<"Car: C"<<pq.top().idx<<endl;
        pq.pop();
    }


    return;
}

int main(){
    vector<pair<int,int>> pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int K = 2;

    nearByCars(pos, K);
}
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Heap {
        vector<int> vec;
public:

    // push
    void push(int val){
        // step 1
        vec.push_back(val);

        // fix heap
        int x = vec.size()-1;
        int parI = (x-1)/2;

        while(parI >= 0 && vec[x] > vec[parI]){
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    // pop
    // step 1 swap root and leaf
    // step 2 is to delete last element
    // fix the heap

    void heapify(int i){ // i = parI

        if(i >= vec.size()){
            return;
        }

        int l = 2*i + 1;
        int r = 2*i + 2;

        int maxI = i;

        if(l < vec.size() && vec[l] > vec[maxI]){
            maxI = l;
        }

        if(r < vec.size() && vec[r] > vec[maxI]){
            maxI = r;
        }

        swap(vec[i] , vec[maxI]);

        if(maxI != i){  // sswapping with any child node
            heapify(maxI);
        }
    }

    void pop(){
        // step 1
        swap(vec[0], vec[vec.size()-1]);

        // step 2
        vec.pop_back();

        // step 3
        heapify(0);
    }

    // top
    int top(){
        return vec[0];
    }

    // empty
    bool emplty(){
        return vec.size() == 0;
    }
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(100);
    heap.push(60);
    heap.push(10);

    cout<<"top: "<<heap.top()<<endl;
    heap.pop();
    cout<<"top: "<<heap.top()<<endl;

}
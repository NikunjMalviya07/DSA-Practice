#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;
    // prim's algorithm is to connect all the nodes of the graph with minimum edges (MST);
    // Kruskal's algo is greedy approach using Disjoint set data structure
class Graph {
    int V;
    list<pair<int,int>>* l;
public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>> [V];
    }

    void addEdge (int u, int v, int wt){
        l[u].push_back(make_pair(v,wt));
        l[v].push_back(make_pair(u,wt));
    }

    void print(){
        for(int u = 0 ; u < V ; u++){
            cout<<u<<" : ";
            for(auto neighbour : l[u]){
                cout << "( "<< neighbour.first << " , "<< neighbour.second << ") ";
            }
            cout<<endl;
        }
    }

    void primsAlgo(int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // pair<wt,v> -> min Heap because sorting is acc. to first parameter;
        pq.push(make_pair(0,src));
        vector<bool> mst(V, false);
        int ans = 0;
        
        while(!pq.empty()){
            int u = pq.top().second; // first
            int wt = pq.top().first; // second
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                ans += wt;
                list<pair<int,int>> neighbours = l[u];
                for(pair<int,int> i : neighbours){
                    pq.push(make_pair(i.second , i.first));
                }
            }
        }

        cout<<"cost of mst : "<<ans<<endl;
        return;
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);
    graph.addEdge(1,3,30);
    graph.addEdge(2,3,50);

    graph.primsAlgo(0);
    
}
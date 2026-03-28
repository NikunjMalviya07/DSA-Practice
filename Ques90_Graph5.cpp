#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Edge{
public:
    int v;
    int wt;

    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;

    }
};
    // diskstra algorithm is with better time complexity...
void dijkstra(int src, vector<vector<Edge>> graph, int V){
    priority_queue<pair<int, int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
// pair of <dist[v],v> ; because by default the inbuild STL in C++ sort on the basis of first value
    vector<int> dist(V, INT_MAX);
    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        
        vector<Edge> edges = graph[u];
        for(Edge e : edges){
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
            }
        }
    }

    for(int d : dist){
            cout<<d<<" ";
        }
        cout<<endl;

    return;
}

void bellmanFord(vector<vector<Edge>> graph, int V, int src){
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i = 0 ; i < V-1; i++){
        for(int j = 0; j < V;j++){
            for(Edge e : graph[j]){
                if(dist[e.v] > dist[j] + e.wt){
                    dist[e.v] = dist[j] + e.wt;
                }
            }
        }
    }

    for(int i : dist){
        cout<<i<<" ";
    }

    return;
}

int main(){
    int V = 5;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,-4));
    graph[2].push_back(Edge(3,2));

    graph[3].push_back(Edge(4,4));

    graph[4].push_back(Edge(1,-1));

    // graph[4].push_back(Edge(3,2));
    // graph[4].push_back(Edge(2,5));

    bellmanFord(graph, V, 0);
    return 0;
}
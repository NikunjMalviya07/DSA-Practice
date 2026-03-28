#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
    // TOPOPLOGICL SORTING
using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isUndir = true;
public:
    Graph(int V, bool isUndir = true){
        this->V = V;
        l = new list<int> [V];
        this->isUndir= isUndir;
    }

    void addEdge (int u, int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }

    void print(){
        for(int u = 0 ; u < V ; u++){
            list <int>  nighbours = l[u];
            cout<<u<<" : ";
            for(int v : l[u]){
                cout << v << " ";
            }
            cout<<endl;
        }
    }

    void bfs(){
        queue<int> q;
        vector<bool> v(V, false);
        q.push(0);
        v[0] = true;

        while(!q.empty()){
            int u = q.front();
            cout<<u<<" ";
            q.pop();

            list<int> neighbour = l[u];
            for(int i : neighbour){
                if(!v[i]){
                    v[i] = true;
                    q.push(i);
                }
            }
            cout<<endl;
        }
    }

    void dfs(int u , vector<bool> &visited){
        visited[u] = true;
        cout<<u<<" ";

        list<int> neighbous = l[u];

        for(int i : neighbous){
            if(!visited[i]){
                dfs(i, visited);
            }
        }
    }

    void topologicalSortingHelper(int src, vector<bool> &vis, stack<int> &s){   // using DFS
        vis[src] = true;
        list<int> neighbous = l[src];

        for(int i : neighbous){
            if(!vis[i]){
                topologicalSortingHelper(i, vis, s);
            }
        }

        s.push(src);
        
    }

    void topologicalSorting(){
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){topologicalSortingHelper(i,vis,s);}
        }
        // print stack

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }

        return;
    }

    void calcIndegree(vector<int> &indeg){

        for(int i ; i < V ; i++){
            list<int> neighbous = l[i];
            for(int j : neighbous){
                indeg[j]++;
            }
        }

    }

    void topoSort2(){   // using Kahn's algorithm
        vector<int> indeg(V, 0);
        calcIndegree(indeg);
        queue<int> q;

        // 0 index node is starting point soo add them

        for(int i = 0; i < V ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            cout<<curr<<" ";
            q.pop();

            list<int> neighbours = l[curr];
            for(int v : neighbours){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }

        cout<<endl;
    }
};

int main(){
    Graph graph(6 , false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.topoSort2();

}
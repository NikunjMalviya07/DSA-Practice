#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge (int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
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

    void bfs (){
        queue<int> q;
        vector<bool> vistied(V, false);
        q.push(0);
        vistied[0] = true;

        while(!q.empty()){
            int u = q.front();
            cout<<u<<" ";
            q.pop();
            list<int> neighbours = l[u];
            
            for(int v : neighbours){
                if(!vistied[v]){ 
                    vistied[v] = true;
                    q.push(v);
                }
            }
        }

        cout<<endl;
    }

    // WE CAN ALSO USE DFS HELPER TO AVOID MAKING GRAPH IN MAIN
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

    bool hasPathHelper(int u, vector<bool> &visited, int dis){
        if(u == dis){
            visited[u] = true;
            return true;
        }

        visited[u] = true;
        list<int> neighbours = l[u];
        for(int i : neighbours){
            if(!visited[i]){
                if(hasPathHelper(i, visited, dis)){
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPath(int u, int dis){
        vector<bool> visited(V,false);
        return hasPathHelper(u, visited, dis);
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    

    // vector<bool> v(7, false);
    // graph.bfs();
    // graph.dfs(0,v);

    cout<<graph.hasPath(0,5);
}
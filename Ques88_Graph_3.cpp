#include<iostream>
#include<vector>
#include<queue>
#include<list>

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

    void Helper1(int u, vector<bool> &v){ // disconnected using DFS
        cout<<u<<" ";
        v[u] = true;
        
        list<int> neighbours = l[u];

        for(int i : neighbours){
            if(!v[i]){
                Helper1(i , v);
            }
        }
    }

    void disGraphDFS(int u){
        // BASIC LOGIC IS OFF DFS
        vector<bool> v(V,false);
        for(int i = 0; i < V; i++){
            if(!v[i]){
                Helper1(i,v);
                cout<<endl;
            }
        }
    }

    void disGraphBFS(int u){
        // BASIC LOGIC IS OFF BFS
        vector<bool> v(V,false);
        for(int i = 0; i < V; i++){
            if(!v[i]){
                Helper2(i,v);
                cout<<endl;
            }
        }
        return;
    }

    void Helper2(int st, vector<bool> &v){ // disconnected using BFS
        queue<int> q;
        q.push(st);
        v[st] = true;

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
            
        }
    }

    bool Helper3(int u, int parent, vector<bool> &v){   // undirectedCase
        v[u] = true;
        list<int> neighbour = l[u];

        for(int i : neighbour){
            if(!v[i]){
                if(Helper3(i, u, v)){
                    return true;
                }
            } else {
                if(i != parent){
                    return true;
                }
            }
        }
        
        return false;
    }

    bool cycleDetection(){  // using DFS
        vector<bool> v(V, false);
        return Helper3(0,-1,v);
    }

    bool isCycleDirHelper(int u, vector<bool> &vis, vector<bool> &recPath){
        vis[u] = true;
        recPath[u] = true;

        list<int> neighbours = l[u];

        for(int v : neighbours){
            if(!vis[v]){
                if(isCycleDirHelper(v, vis, recPath)){
                    return true;
                }
            } else {
                if(recPath[v]){
                    return true;
                }
            }
        }

        recPath[u] = false;

        return false;
    }

    bool isCycleDir() {
        vector<bool> vis (V, false);
        vector<bool> recPath (V, false);

        for(int i = 0 ; i < V; i++){
            if(!vis[i]){
                if(isCycleDirHelper(i, vis, recPath)){
                    return true;
                }
            }
        }

        return false;
    }

    bool isBipartite(){ // it can also be solved with only 1 vector color
        queue<int> q ;
        vector<int> vis(V, false);
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            list<int> neighbours = l[u];
            for(int i : neighbours){
                if(!vis[i]){
                    vis[i] = true;
                    color[i] = !color[u];
                    q.push(i);
                } else {
                if(color[i] == color[u]){
                    return false;
                }
            }

            } 
        }

        return true;
    }

    void pathTraceHelper(int src, int dest, vector<bool> &vis, string &path){
        if(src == dest){
            cout<<path<<dest<<endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        list<int> neighbours = l[src];

        for(int i : neighbours){
            if(!vis[i]){
                pathTraceHelper(i , dest , vis, path);
            }
        }

        path.pop_back();
        vis[src] = false;
    }

    void pathTrace(int src, int dest){
        vector<bool> vis(V, false);
        string path = "";
        pathTraceHelper(src, dest, vis, path);
    }


};

int main(){
    Graph graph(6, false);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);


    graph.pathTrace(5 , 1);
}
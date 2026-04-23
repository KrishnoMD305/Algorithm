#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Graph{
    int n; int e;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;
    vector<int> cycle;
    queue<int> qq;
    void dfs_private(int node,vector<vector<int>>& adj,vector<bool>& visited){
        visited[node] = true;
        cout<<node<<" ";
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs_private(neighbor,adj,visited);
            }
        }
    }
    void bfs_private(int start,vector<vector<int>>& adj, int n){
        visited[start] = true;
        qq.push(start);

        while(!qq.empty()){
            int node = qq.front();
            qq.pop();

            cout<<node<<" ";

            for(int neighbor : adj[node]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    qq.push(neighbor);
                }
            }
        }
    }

    bool dfs_cycle(int node,int par){
        visited[node] = true;
        parent[node] = par;

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                if(dfs_cycle(neighbor,node)){
                    return true;
                }
            }else if(neighbor != par){
                int cur = node;
                cycle.push_back(neighbor);

                while(cur != neighbor){
                    cycle.push_back(cur);
                    cur = parent[cur];
                }
                cycle.push_back(neighbor);
                return true;
            }
        }
        return false;
    }

public:
    Graph(int a,int b){
        n = a;
        e = b;
        adj.resize(n+1);
        visited.assign(n+1,false);
        parent.assign(n+1,-1);
        cycle.clear();
    }



    void insert(){
        for(int i=0; i<e; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void show(){
        for(int i=1; i<=n; i++){
            cout<<"["<<i<<"] : ";
            for(int j=0; j<adj[i].size(); j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }

    void dfs(int node){
        cout<<"\n";
        dfs_private(node,adj,visited);
        cout<<"\n";
        visited.assign(n+1,false);
    }

    void bfs(int start,int n){
        cout<<"\n";
        bfs_private(start,adj,n);
        visited.assign(n+1,false);
        queue<int> emp;
        swap(qq,emp);
    }

    bool cycle_detection(){
        bool cycle = false;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                if(dfs_cycle(i,-1)){
                    cycle = true;
                }
            }
        }
        visited.assign(n+1,false);
        return cycle;
    }

    void cycle_print(){
        if(cycle_detection()){
            for(int node : cycle){
                cout<<node<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"No Cycle\n";
        }
        parent.assign(n+1,-1);
        cycle.clear();
    }

    void shortest_path(int source, int destination){
        vector<int> dist(n+1,-1);
        vector<int> parent(n+1,-1);

        dist[source] = 0;
        qq.push(source);

        while(!qq.empty()){
            int u = qq.front();
            qq.pop();
            for(int i : adj[u]){
                if(dist[i]==-1){
                    dist[i] = dist[u] + 1;
                    parent[i] = u;
                    qq.push(i);
                }
            }
        }

        for(int i=1; i<=n; i++){
            cout<<i<<" -> "<<dist[i]<<"\n";
        }

        if(dist[destination]==-1){
            cout<<"No Path\n";
        }else{
            vector<int> path;
            for(int i=destination; i != -1; i = parent[i]){
                path.push_back(i);
            }
            reverse(path.begin(),path.end());

            for(int node : path){
                cout<<node<<"\n";
            }
        }

        queue<int> emp;
        swap(qq,emp);
    }


};

int main(){
    int n,e;
    cin>>n>>e;
    Graph g(n,e);
    g.insert();
    g.show();
    g.dfs(1);
    g.bfs(3,6);
    return 0;
}

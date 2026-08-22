#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int main(){
    int v,e;
    cout<<"Enter Number of Vertex : ";
    cin>>v;
    cout<<"Enter number of Edge : ";
    cin>>e;
    vector<vector<pair<int,int>>> adj(v);
    cout<<"\n\nEnter the edges and weight--\n";
    for(int i=0; i<e; i++){
        int s,d,w;
        cin>>s>>d>>w;
        adj[s].push_back({d,w});
    }
    cout<<"\n\nThe Graph representation : --\n";
    for(int i=0; i<adj.size(); i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<i<<" --> "<<adj[i][j].first<<" : "<<adj[i][j].second<<"\n";
        }
    }

    cout<<"\n\nApplying Dijkstra's Algorithm-----\n\n";
    int source;
    cout<<"Enter the source vertex : ";
    cin>>source;
    vector<int> dist(v,INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> visited;
    visited.push({0,source});
    while(!visited.empty()){
        int u = visited.top().second;
        int d = visited.top().first;
        visited.pop();
        for(int i=0; i<adj[u].size(); i++){
            int ver = adj[u][i].first;
            int dis = adj[u][i].second;
            int newD = dis + d;
            if(newD < dist[ver]){
                dist[ver] = newD;
                visited.push({newD,ver});
            }
        }
    }

    cout<<"Shortest Distances from source :--\n";
    for(int i=0; i<dist.size(); i++){
        cout<<i<<" --> "<<dist[i]<<"\n";
    }

    cout<<"\nThe End\n";
    return 0;
}

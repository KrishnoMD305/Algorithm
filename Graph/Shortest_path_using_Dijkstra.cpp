#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<algorithm>
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
    vector<int> parent(v,-1);
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
                parent[ver] = u;
                visited.push({newD,ver});
            }
        }
    }

    cout<<"Shortest Distances from source :--\n";
    for(int i=0; i<dist.size(); i++){
        cout<<i<<" --> "<<dist[i]<<"\n";
    }

    cout<<"\nEnter the destination : ";
    int des; 
    cin>>des;
    if(dist[des]==INT_MAX){
        cout<<"No path exist\n\n";
        cout<<"\nThe End\n";
        return 0;
    }
    vector<int> path;
    int i = des;
    while(i!=-1){
        path.push_back(i);
        i = parent[i];
    }
    reverse(path.begin(),path.end());
    cout<<"Shortest distance from source to destination : "<<dist[des]<<"\n";
    cout<<"Shortest path : ";
    for(int i=0; i<path.size(); i++){
        cout<<path[i];
        if(i==path.size()-1){
            continue;
        }
        cout<<" --> ";
    }

    cout<<"\nThe End\n";
    return 0;
}

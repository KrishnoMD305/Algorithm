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

    cout<<"\n\nApplying Bellman-Ford's Algorithm-----\n\n";
    int source;
    cout<<"Enter the source vertex : ";
    cin>>source;
    vector<int> dist(v,INT_MAX);
    dist[source] = 0;

    for(int k=0; k<v-1; k++){
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                int s = i;
                int d = adj[i][j].first;
                int w = adj[i][j].second;

                if(dist[s] != INT_MAX){
                    int newD = dist[s] + w;
                    if(newD < dist[d]){
                        dist[d] = newD;
                    }
                }
            }
        }
    }
    bool negCycle = false;
    for(int i=0; i<adj.size(); i++){
        for(int j=0; j<adj[i].size(); j++){
            int s = i;
            int d = adj[i][j].first;
            int w = adj[i][j].second;
            if(dist[s]!=INT_MAX && dist[s]+w<dist[d]){
                negCycle = true;
                break;
            }
        }
        if(negCycle){
            break;
        }
    }
    if(negCycle){
        cout<<"Graph has negative cycle\n\n";
    }else{
        cout<<"Shortest Distances from source :--\n";
        for(int i=0; i<dist.size(); i++){
            cout<<i<<" --> "<<dist[i]<<"\n";
        }
    }
    return 0;
}

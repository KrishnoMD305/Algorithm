#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<e; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<endl;
    cout<<endl;
    cout<<"Adjacency list: \n";
    for(int i=1; i<=n; i++){
        cout<<i<<" : ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

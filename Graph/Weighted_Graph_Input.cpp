#include<iostream>
#include<vector>
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
    cout<<"\nThe End\n";
    return 0;
}

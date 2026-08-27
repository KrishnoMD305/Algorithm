#include<iostream>
#include<vector>
using namespace std;
const int inf = 1e8;
int main(){
    int v,e;
    cout<<"Enter number of vertex : ";
    cin>>v;
    cout<<"Enter number of edge : ";
    cin>>e;

    vector<vector<int>> adj(v,vector<int>(v));
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i==j){
                adj[i][j] = 0;
            }else{
                adj[i][j] = inf;
            }
        }
    }
    cout<<"Before taking edges input the adjacency matrix : \n";
    cout<<" ";
    for(int i=0; i<v; i++){
        cout<<" "<<i<<"  ";
    }
    cout<<"\n";
    for(int i=0; i<v; i++){
        cout<<i;
        for(int j=0; j<v; j++){
            if(adj[i][j]==inf){
                cout<<"Inf ";
            }else{
                cout<<" "<<adj[i][j]<<"  ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n\nEnter Edges: \n";
    for(int i=0; i<e; i++){
        int u,v1,w;
        cin>>u>>v1>>w;
        adj[u][v1] = w;
    }
    cout<<"\n\n\n";
    cout<<"After taking edges input the adjacency matrix : \n";
    cout<<" ";
    for(int i=0; i<v; i++){
        cout<<" "<<i<<"  ";
    }
    cout<<"\n";
    for(int i=0; i<v; i++){
        cout<<i;
        for(int j=0; j<v; j++){
            if(adj[i][j]==inf){
                cout<<"Inf ";
            }else{
                cout<<" "<<adj[i][j]<<"  ";
            }
        }
        cout<<"\n";
    }

    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }

    cout<<"\n\nAfter applying Floyd-warshall, the matrix : \n";
        cout<<" ";
    for(int i=0; i<v; i++){
        cout<<" "<<i<<"  ";
    }
    cout<<"\n";
    for(int i=0; i<v; i++){
        cout<<i;
        for(int j=0; j<v; j++){
            if(adj[i][j]==inf){
                cout<<"Inf ";
            }else{
                cout<<" "<<adj[i][j]<<"  ";
            }
        }
        cout<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void subsets(vector<int> &v,vector<int> &current,vector<vector<int>> &result,int index){
    result.push_back(current);
    for(int i=index; i<v.size(); i++){
        current.push_back(v[i]);
        subsets(v,current,result,i+1);
        current.pop_back();
    }
}

int main(){
    cout<<"Enter the number of the elements: ";
    int n; cin>>n; 
    vector<int> v(n),current;
    vector<vector<int>> result;
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    subsets(v,current,result,0);
    cout<<"The subsets are-\n";
    for(int i=0; i<result.size(); i++){
        for(auto j : result[i]){cout<<j<<" ";}
        cout<<endl;
    }
    return 0;
}
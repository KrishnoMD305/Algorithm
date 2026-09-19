#include<bits/stdc++.h>
using namespace std;

void Gauss_Jordan(int n, vector<vector<double>> &a, vector<double> &b){
    for(int i=0; i<n; i++){
        if(a[i][i]==0){
            for(int k=i+1; k<n; k++){
                if(a[k][i]!=0){
                    swap(a[k],a[i]);
                    swap(b[k],b[i]);
                    break;
                }
            }
        }
        double f1 = a[i][i]; 
        for(int k=0; k<n; k++){
            a[i][k] = a[i][k] / f1; 
        }
        b[i] = b[i] / f1;
        for(int j=0; j<n; j++){
            if(j!=i){
                double ff = a[j][i];
                for(int k=0; k<n; k++){
                    a[j][k] = a[j][k] - ff*a[i][k];
                }
                b[j] = b[j] - ff*b[i];
            }
        }
    }
}

int main(){
    int n; cin>>n;
    vector<vector<double>> a(n,vector<double>(n));
    vector<double> b(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++){
            double x; cin>>x; 
            if(j<n){
                a[i][j] = x;
            }else{
                b[i] = x;
            }
        }
    }
    Gauss_Jordan(n,a,b);
    for(int i=0; i<n; i++){
        cout<<b[i]<<endl;
    }
    return 0;
}

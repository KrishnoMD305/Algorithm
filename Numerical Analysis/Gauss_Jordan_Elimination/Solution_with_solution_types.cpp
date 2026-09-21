#include<bits/stdc++.h>
using namespace std;

void GaussJ(vector<vector<double>> &a,vector<double> &b,int n){
    int r= 0 ;
    for(int i=0; i<n; i++){
        if(a[i][i]==0){
            bool fnd = false;
            for(int j=i+1; j<n; j++){
                if(a[j][i] != 0){
                    swap(a[j],a[i]);
                    swap(b[i],b[j]);
                    fnd = true;
                    break;
                }
            }
            if(!fnd){
                continue;
            }
        }
        double piv = a[i][i];
        for(int j=0; j<n; j++){
            a[i][j] = a[i][j] / piv;
        }
        b[i] = b[i] / piv;
        for(int j=0; j<n; j++){
            if(j!=i){
                double dd = a[j][i];
                for(int k=0; k<n; k++){
                    a[j][k] = a[j][k] - a[i][k]*dd;
                }
                b[j] = b[j] - dd*b[i];
            }
        }
        r++;
    }

    for(int i=0; i<n; i++){
        bool zeros = true;
        for(int j=0; j<n; j++){
            if(a[i][j] != 0){
                zeros = false;
                break;
            }
        }
        if(zeros && b[i]!=0){
            cout<<"No solution\n";
            return;
        }

    }
    if(r<n){
        cout<<"Many solution\n";
        return;
    }
    cout<<"Unique Solution\n";
    for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n;
    cin>>n;
    vector<vector<double>> a(n,vector<double>(n));
    vector<double> b(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=n; j++){
            double x; cin>>x;
            if(j==n){
                b[i] = x;
            }else{
                a[i][j] = x;
            }
        }
    }
    GaussJ(a,b,n);
    return 0;
}

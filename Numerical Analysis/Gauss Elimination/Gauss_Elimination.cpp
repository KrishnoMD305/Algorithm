#include<bits/stdc++.h>
using namespace std;

vector<double> Gauss(int n, vector<vector<double>> &a,vector<double> &b){
    for(int k=0; k<n-1; k++){
        for(int i=k+1; i<n; i++){
            double m = a[i][k]/a[k][k];
            for(int j=k; j<n; j++){
                a[i][j] = a[i][j] - m*a[k][j];
            }
            b[i] = b[i] - m*b[k];
        }
    }
    vector<double> ans(n);
    ans[n-1] = b[n-1]/a[n-1][n-1];
    for(int i=n-2; i>=0; i--){
        double s  = 0;
        for(int j=i+1; j<n; j++){
            s += a[i][j] * ans[j];
        }
        ans[i] = (b[i]-s)/a[i][i];
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<vector<double>> a(n,vector<double>(n));
    vector<double> b(n);
    for(int i=0; i<n; i++){
        int k = 0;
        for(int j=0; j<n+1; j++){
            double x; cin>>x; 
            if(j<n){
                a[i][j] = x;
            }else{
                b[i] = x;
                k++;
            }

        }
    }
    vector<double> ans = Gauss(n,a,b);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

bool isSorted(vector<int> &v,int n){
    if(n==0 || n==1) return true;

    return v[n-1]>=v[n-2] && isSorted(v,n-1);
}

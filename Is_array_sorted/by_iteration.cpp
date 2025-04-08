bool issorted(vector<int> &v){
    for(int i=1; i<v.size(); i++){
        if(v[i]<v[i-1]) return false;
    }
    return true;
}

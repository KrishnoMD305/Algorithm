vector<vector<int>> permutation(vector<int> &arr){
        if(arr.size() <= 1){
            return {arr};
        }
        vector<vector<int>> result;
        for(int i=0; i<arr.size(); i++){
            int current = arr[i];
            vector<int> remains;
            for(int j=0; j<arr.size(); j++){
                if(j!=i){
                    remains.push_back(arr[j]);
                }
            }
            vector<vector<int>> perm = permutation(remains);
            for(int k=0; k<perm.size(); k++){
                vector<int> ne = {current};
                ne.insert(ne.end(), perm[k].begin(), perm[k].end());
                result.push_back(ne);
            } 
        }
        return result;
    }

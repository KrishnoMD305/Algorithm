// It is also a loop but this time we decrease the loop. When we select a number we delete the whole multiplication list of this number.
// This way the number of loops is reduced and saves time.

int countPrimes(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 0;
        }
        vector<bool> p(n+1,true);
        int count = 0;
        for(int i=2; i<n; i++){
            if(p[i]){
                count++;
                for(int j=2*i; j<n; j+=i){
                    p[j] = false;
                }
            }
        }
        return count;
    }

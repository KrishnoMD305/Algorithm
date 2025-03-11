// In most of the case it will give TLE if n is large enough

    bool prime(int n){
        for(int i=2; i*i<=n; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        int count = 0;
        if(n==1){
            return 0;
        }
        if(n==0){
            return 0;
        }
        for(int i=2; i<n; i++){
            if(prime(i)){
                count++;
            }
        }
        return count;
    }

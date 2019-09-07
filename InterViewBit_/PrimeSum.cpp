/**
 *  @author:      skyhavoc
 *  created:      2019
**/
/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture
*/
vector<int> Solution::primesum(int n) {

    // boo is important for memory optim
    vector<bool> primes(n+1, 0);
    primes[0] = 0; 
    primes[1] = 0;
    for(int i=2; i<=n; i++) {
        primes[i] = 1;
    }
    
    for(int i=2; i<=n; i++) {
        if(primes[i]==1) {
            for(int j=i*2; j<=n; j += i) {
                primes[j] = 0;
            }
        }
    }
    
    vector<int> ans(2);

    for(int i=2; i<=(n/2); i++) {
        if(primes[i]==1 && primes[n-i]==1) {
            ans[0] = i;
            ans[1] = n-i;
            return ans;
        }
    }   
}


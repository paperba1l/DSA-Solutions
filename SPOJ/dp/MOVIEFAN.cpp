//https://www.spoj.com/problems/MOVIFAN/
#include <bits/stdc++.h>
using namespace std;

const int me = 302500;
const int mod = 1000000007;

int T, N, L;
int sum[me], st[me];

int main() {  
    cin>>T;
    while(T --){
        cin>>N>>L;
        for(int i = 1; i <= N; i ++)
            cin>>st[i];
        sort(st + 1, st + N + 1);
        
        int ans = 0, ptr = 1;
        /*
            if all the time slots where not overlapping, the answer for dp[i] = 2*dp[i-1] + 1
            
        */

        //dp[0] = 1;
        for(int i = 1; i <= N; i ++){
            while(ptr <= i and st[ptr] + L <= st[i])
                ++ptr;


            /* sum[i-1] -- when ith element is not included 
                sum[ptr-1] -- match all the subsets with which we can include ith element
                +1 -- for single set with only ith element */
            sum[i] = (sum[i - 1] + sum[ptr - 1] + 1) % mod;
        }
        cout<<sum[N]<<endl;;
    }
    
    return 0;
}
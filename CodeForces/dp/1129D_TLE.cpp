
/**
 *    @author:      skyhavoc
 *    created:      20xx
 *    problem:      https://codeforces.com/contest/1129/problem/D
 *    name:         D. Isolation
**/
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define vi vector<int>
#define pii pair<int, int>
#define all(c) c.begin(), c.end()
#define isnum(a) (a >= 48 && a <= 57)
#define ischar(a) (a >= 'a' && a <= 'z')
#define isChar(a) (a >= 'A' && a <= 'Z')
#define isDigit(a) (ch >= '0' && ch <= '9')
#define mset(x, v) memset(x, v, sizeof(x))
#define boostio                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif

typedef unsigned long long ull;
typedef long long int ll;
const long double eps = 1e-9;
const int maxn = 1e5+6;
const int mod = 998244353;
vector<int> occourences[maxn];
int cnt[maxn], dp[maxn]; 

void add(int a, int b, int diff) {
    for(int i=a; i<=b; i++) {
        cnt[i]+=diff;
    }
}

// O(n^2) solution 
int main() {
	int n, k;
	cin>>n>>k;
	
	for(int i=0; i<=n; i++) {
	    occourences[i].pb(-1);
	}
	
	int x; dp[0] = 1;
	for(int i=0; i<n; i++) {
	    cin>>x;
	    
	    // remove the +1 addition from the previous segment 
	    if(occourences[x].size()>=2) {
	        add(occourences[x].end()[-2]+1, occourences[x].back(), -1);
	    }
	    
	    // add +1 to the new segment found
	    add(occourences[x].back()+1, i, 1);
	    occourences[x].pb(i);
	    
	    // find j wich makes [j...i] a valid segment 
	    for(int j=0; j<=i; j++) {
	        if(cnt[j]<=k) {
	            dp[i+1]+=dp[j];
	            if(dp[i+1]>=mod)
	                dp[i+1]-=mod;
	        }
	    }
	}
	
	cout<<dp[n]<<endl;
	return 0;
}

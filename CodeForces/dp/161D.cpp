/**
 *  @author:      skyhavoc
 *  created:      2019
 *  D. Distance in Tree
 *  https://codeforces.com/contest/161/problem/D
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+8;
int dp[maxn][504], mask[maxn];
vector<int> adj[maxn];

int n, k, a, b, ans=0;

// dp on tree
int dfs(int x) {
    mask[x] = 1;
    // node n is at level 0, so put 1
    dp[x][0] = 1;
    
    for(auto e : adj[x]) {
        if(!mask[e]){
            dfs(e);
            
            // dp[x][] is calculated, either left or right
            // combine it with the other child e
            for(int i=0; i<k; i++) {
                ans += dp[x][i]*dp[e][k-i-1];
            }
            for(int i=1; i<=k; i++) {
                dp[x][i] += dp[e][i-1];
            }
        }
    }
}

int main() {
	cin>>n>>k;

	for(int i=1; i<=n-1; i++) {
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
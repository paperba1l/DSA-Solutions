// https://codeforces.com/contest/987/problem/C
#include <bits/stdc++.h>
using namespace std;
 
const long long INF = 1e18;
 
struct str {
    int s, c;
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    if (n < 3) {
        cout <<"-1\n";
        return 0;
    }
    vector <str> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].s;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].c;
    }
 
    vector <long long> dp(n);
    // INIT
    for (int i = 0; i < n; ++i) {
        dp[i] = INF;
    }

    /* dp[k] -- stores the minimum combination(i<k) cost, so that 
        whenever (v[k].s < v[j].s) condition is satisfied we pair jth with
        kth element and we know the cost for the pair (ith and kth element)
        in dp[k] */
    long long ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (v[i].s < v[j].s) {

                // calculating the dps
                if (v[i].c + v[j].c < dp[j]) {
                    dp[j] = v[i].c + v[j].c;
                }

                // this is actual dp logic
                if (dp[i] + v[j].c < ans) {
                    ans = dp[i] + v[j].c;
                }
            }
        }
    }
    if (ans != INF)
        cout << ans << '\n';
    else
        cout << "-1\n";
    return 0;
}
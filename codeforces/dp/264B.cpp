
/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      B. Good Sequences
 *  link:         https://codeforces.com/contest/264/problem/B
**/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 6;
int a[maxn], dp[maxn], mcnt[maxn];
vector<int> fact_list[maxn];

void pre()
{
    for (int i = 2; i < maxn; i++)
    {
        for (int j = i; j < maxn; j += i)
        {
            fact_list[j].push_back(i);
        }
    }
}

vector<int> divisor_list(int x)
{
    return fact_list[x];
}

int main()
{
    pre();

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    map<int, int> mpp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mpp[a[i]] = 1; // ai is present
    }

    int ans = 0;
    // making sure sequence is increasing
    for (int i = 1; i < maxn; i++)
    {
        if (mpp[i] != 1)
            continue;

        vector<int> lis = divisor_list(i);

        for (auto div : lis)
        {
            dp[i] = max(dp[i], mcnt[div] + 1);
        }

        for (auto div : lis)
        {
            mcnt[div] = max(mcnt[div], dp[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
    return 0;
}
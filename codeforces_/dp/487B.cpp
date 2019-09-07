/**
 *  @author:      skyhavoc
 *  created:      20xx
 *  https://codeforces.com/contest/487/problem/B
 *  B. Strip
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 4;
multiset<int> se, ss;
int a[maxn], dp[maxn];

int main()
{
    int n, s, l;
    cin >> n >> s >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        se.insert(a[i]);
        for (; *se.rbegin() - *se.begin() > s; j++)
        {
            se.erase(se.find(a[j]));
            if (i - l >= j)
            {
                ss.erase(ss.find(j ? dp[j - 1] : 0));
            }
        }

        if ((i - j + 1) >= l)
        {
            ss.insert((i - l >= 0) ? dp[i - l] : 0);
        }
        dp[i] = ss.size() ? *ss.begin() + 1 : n + 1;
    }

    cout << (dp[n - 1] > n ? -1 : dp[n - 1]) << endl;
    return 0;
}
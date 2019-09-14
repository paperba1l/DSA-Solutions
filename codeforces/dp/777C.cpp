/**
 *  @author:      dnar
 *  https://codeforces.com/problemset/problem/777/C
 *  C. Alyona and Spreadsheet
**/
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

using ll = long long;

int main()
{

    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> last(n, vector<int>(m));
    vector<int> mx(n, n + 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &a[i][j]);
            if (i > 0 && a[i][j] >= a[i - 1][j])
            {
                last[i][j] = last[i - 1][j];
            }
            else
            {
                last[i][j] = i;
            }
            // storing the min index where sequence breaks. sequence can definitely break after the  min
            // index in other column
            mx[i] = min(mx[i], last[i][j]);
        }
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        --l, --r;
        if (mx[r] <= l)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
}
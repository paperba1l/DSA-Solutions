/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      B. Hamming Distance Sum   
**/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 7;
int F[maxn][2];

int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = 1; i <= b.length(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            F[i][j] += F[i - 1][j];
        }
        F[i][b[i - 1] - '0']++;
    }

    int ans = 0;
    for (int i = 0; i < a.length(); i++)
    {

        // a[i]-0 for [0..b-a] indices, same for a[i]-1
        for (int j = 0; j < 2; j++)
        {
            ans += abs((a[i] - '0') - j) *
                   (F[b.length() - a.length() + i + 1][j] - F[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
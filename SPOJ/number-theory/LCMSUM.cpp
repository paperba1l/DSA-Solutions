/**
 *  @author:      skyhavoc
 *  created:      2019
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
#define all(vec) vec.begin(), vec.end()
#define isnum(dig) (dig >= 48 && dig <= 57)
#define isdigit(ch) (ch >= '0' && ch <= '9')
#define ischar(ch) (ch >= 'a' && ch <= 'z')
#define isChar(ch) (ch >= 'A' && ch <= 'Z')
#define fill(vec, x) memset(vec, x, sizeof(vec))
#define bitcount __builtin_popcount
#define boostio                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
// Input macros
#define s(n) scanf("%d", &n)
#define sc(n) scanf("%c", &n)
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)

typedef long long int ll;
typedef unsigned long long ull;
const long double EPS = 1e-9;
const long double PI = 3.14159265358979;
inline int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }
inline int fpow(ll n, ll k, int p)
{
    ll r = 1;
    for (; k; k >>= 1)
    {
        if (k & 1)
            r = r * n % p;
        n = n * n % p;
    }
    return r;
}

const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 4;
ll phi[maxn], lcm_sum[maxn];

void calcPhi()
{
    for (int i = 1; i < maxn; i++)
    {
        phi[i] = i;
    }
    for (int i = 2; i < maxn; i++)
    {
        if (phi[i] == i)
        {
            phi[i] = i - 1;
            for (int j = i * 2; j < maxn; j = j + i)
            {
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
}

void lcmSum()
{
    for (int i = 1; i < maxn; i++)
    {
        for (int j = i; j < maxn; j += i)
        {
            lcm_sum[j] += (i * phi[i]);
        }
    }
}

int main()
{
    boostio;

    //freopen("input.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    calcPhi();
    phi[1] = 1;
    lcmSum();

    int tcs = 1, n;

    cin >> tcs;
    while (tcs--)
    {
        cin >> n;
        ll res = lcm_sum[n] + 1;
        res *= n;
        res >>= 1;
        cout << res << '\n';
    }

    return 0;
} // skyhavoc        *2019

//int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month
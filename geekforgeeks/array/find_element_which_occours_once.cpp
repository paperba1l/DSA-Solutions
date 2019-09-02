/**
 *  @author:      skyhavoc
 *  created:      2019
**/
/*
Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2
In the given array all element appear three times except 2 which appears once.
*/
#include <bits/stdc++.h>
using namespace std;
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

int count_1s(int n)
{
    int c = 0;
    while (n)
    {
        n = n & (n - 1);
        c++;
    }
    return c;
}

const ll mod = 1e9 + 7;
const ll maxn = 5000;
int a[maxn];

int main()
{
    boostio;

    //freopen("input.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tcs = 1;

    cin >> tcs;
    while (tcs--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int p2 = 1, cnt = 0, ans = 0;
        while (p2 < 128)
        {
            cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if ((a[i] & p2) == p2)
                {
                    cnt++;
                }
            }

            ans += (cnt % 3) * p2;
            p2 = p2 * 2;
        }
        cout << ans << endl;
    }

    return 0;
} // skyhavoc        *2019

//int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month
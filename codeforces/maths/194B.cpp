/**
 *  @author:      skyhavoc
 *  created:      2020
 *  problem:      B. Square
 *  link:         https://codeforces.com/problemset/problem/194/B
**/
/**
 *  @author:      skyhavoc
 *  created:      2020
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

int main()
{
	boostio;

	//freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tcs = 1;
	cin >> tcs;

	while (tcs--)
	{
		ll n;
		cin >> n;

		/*
            we move in cricular fashion d = n+1 
            after moving certain round we will comeback to original location
            let say, we started from 0th position then after k rounds we come
            back to same location (0 + k(n+1))%4n. we need to find the smallest value 
            of k such that k(n+1) is the least multiple of 4n, that is lcm(4n, n+1)/(n+1)
        */

		ll hcf = __gcd(4 * n, n + 1);
		ll lcm = (4 * n * (n + 1)) / hcf;
		cout << lcm / (n + 1) + 1 << endl;
	}

	return 0;
} // skyhavoc        *2020

//int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

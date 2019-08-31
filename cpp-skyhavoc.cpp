/**
 *  @author:      skyhavoc
 *  created:      2019
**/
#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define pb              push_back
#define pf              push_front
#define mp              make_pair
#define vi              vector<int>
#define pii             pair<int, int>
#define all(v)          v.begin(),v.end()
#define isnum(a)        (a>=48 && a<=57)
#define isdigit(ch)      (ch>='0' && ch<='9')
#define ischar(c)       (c>='a' && c<='z')
#define isChar(c)       (c>='A' && c<='Z')
#define fill(a,v)       memset(a, v, sizeof(x))
#define bitcount                    __builtin_popcount
#define boostio         ios_base::sync_with_stdio(false); cin.tie(0);
// Input macros
#define s(n)            scanf("%d",&n)
#define sc(n)           scanf("%c",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)

typedef long long int ll;
typedef unsigned long long ull;
const long double EPS   = 1e-9;
const long double PI    = 3.14159265358979;
inline int gcd(int a, int b) {return(b?gcd(b,a%b):a);}
inline int lcm(int a, int b) {return a / gcd(a, b) * b;}
inline int fpow(ll n, ll k, int p) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}

int count_1s(int n){
    int c=0;
    while(n){
        n=n&(n-1); c++;
    }return c;
}

const ll mod    = 1e9+7;
const ll maxn   = 5000;
int dp[maxn];

int main() {
    boostio;

    //freopen("input.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tcs=1;

    //cin>>tcs;
    while(tcs--){

    }
    
    return 0;
}// skyhavoc        *2019

//int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
//int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month



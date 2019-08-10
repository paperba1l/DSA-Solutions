#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
const int me = 1e6+40;
ll arr[me];

// https://en.wikipedia.org/wiki/Padovan_sequence
/* --recursive--
const int me = 1e6+40;
int dp[me];
int func(int n) {
    
    if(n==0) return 1;
    if(n<0) return 0;
    
    if(dp[n]!=-1) return dp[n];
    
    dp[n] = (func(n-2) + func(n-3))%1000000007;
    return dp[n];
}
*/
int main(){
	
	arr[0] = arr[1] = 0;
	arr[2] = arr[3] = 1;
	for(int i=4;i<me;i++){
		arr[i] = (arr[i-2] + arr[i-3]) % mod;
	}
	int t, a;
	cin>>t;
	while(t--){
		cin>>a;
		cout<<arr[a]<<endl;
	}
	return 0;
}
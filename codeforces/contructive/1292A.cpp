/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      A. NEKO's Maze Game
 *  link:         https://codeforces.com/contest/1292/problem/A
**/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
bool is_forbidded[3][maxn];

int main() {
    int n, q;
    cin>>n>>q;
    memset(is_forbidded, false, sizeof(is_forbidded));
    int blocked_cnt = 0;
    for(int i=0; i<q; i++) {
        int r, c;
        cin>>r>>c;
        --r;
        --c;

        for (int _r : {0, 1}) {
            for (int _c = c-1; _c <= c+1; _c++) {
                if (_r == r) continue;
                
                if(!(_c>=0 and _c<n)) continue;
    
                if (is_forbidded[_r][_c]) {
                    if(is_forbidded[r][c])
                        blocked_cnt--;
                    else 
                        blocked_cnt++;
                }
            }
        }
        
        is_forbidded[r][c] = !is_forbidded[r][c];
        
        if(blocked_cnt>=1) {
            cout<<"No"<<endl;
        }
        else {
            cout<<"Yes"<<endl;
        }
    }
	return 0;
}
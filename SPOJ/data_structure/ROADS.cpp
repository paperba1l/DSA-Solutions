#include <bits/stdc++.h>
using namespace std;
const int maxn =100+5;

typedef pair<int, int> ii ;
typedef pair<int, ii> iii ;
priority_queue<iii, vector<iii>, greater<iii> > pq ;
vector<iii> adj[maxn];k

int N, coins, roads;
int main(){
    int t, u, v, len, toll,l;
    cin>>t;
    while(t--){
        cin>>coins>>N>>roads;
        for(int i=0; i<N; i++){
            adj[i].clear();
        }
        while(roads--){
            cin>>u>>v>>l>>toll;
            // {v, len, toll}
            adj[u].push_back(iii(v, ii(l, toll)));
        }

        // {l, toll, u}, l is used as key in pq
        pq = priority_queue<iii, vector<iii>, greater<iii>>();
        pq.push(make_pair(0, ii(0, 1)));

        bool found = false;
        while(!pq.empty()){
            iii tmp = pq.top();
            pq.pop();

            len = tmp.first;
            toll = tmp.second.first;
            u = tmp.second.second;

            if(u == N){
                found = true;
                break;
            }

            for(int i=0; i<(int)adj[u].size(); i++){
                iii node = adj[u][i];
                v = node.first;
                int vl = node.second.first;
                int vt = node.second.second;

                if( toll + vt <= coins ) {
					pq.push( make_pair(len + vl, ii(toll + vt, v))) ;
				}
            }
        }
        if( found )
			cout<< len <<endl;
		else
			cout<<-1<<endl;
    }
    return 0;
}

// https://www.spoj.com/problems/KGSS/
// KGSS - Maximum Sum

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int maxn  = 100010;
const int MIN  = 0;

struct node {
    int a, b;
}nodes[2*maxn];


// get max and 2nd max number 
node merge(node l, node r){
    node tmp;
    tmp.a = max(l.a, r.a);
    if(l.a == tmp.a)
        tmp.b = max(l.b, r.a);
    else 
        tmp.b = max(l.a, r.b);

    return tmp;
}


// segment tree is on 1 based indexing
void build(int n){
    for(int i=n-1; i>0; i--){
        nodes[i] = merge(nodes[i*2], nodes[i*2 + 1]);
    }
}

void modify(int n, int p, int val){

    for(nodes[p+=n].a = val; p>1; p/=2) {
        nodes[p/2] = merge(nodes[p], nodes[p^1]);
    }
}

node query(int n, int l, int r) {
    node res;
    res.a = MIN;
    res.b = MIN;
    for (l += n, r += n; l < r; l/=2, r/=2) {
        if (l&1) res = merge(res, nodes[l++]);
        if (r&1) res = merge(res, nodes[--r]);
    }
    return res;
}

int main(){
    int n, q;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>nodes[i+n].a;
        nodes[i+n].b = MIN;
    }
    build(n);
    
    cin>>q;
    while(q--){
        int x, y;
        char c;
        cin>>c>>x>>y;
        if(c=='Q'){
            // ith number in the array correspond to i+n-1 number if the segment tree
            // query is in the range [x-1, y)
            node ans = query(n, x-1, y);
            cout<<ans.a+ans.b<<endl;
        }
        else {
            // ith number in the array correspond to i+n-1 number if the segment tree
            modify(n, x-1, y);
        }
    }
    return 0;
}
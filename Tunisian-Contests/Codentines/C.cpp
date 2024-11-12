#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 200100 ; 
vector<int> a[N] ;
vector<array<int,2>> queries[N] ; 
ordered_set st[N] ;
ll ans[5 * N] ; 
int depth[N]; 

void dfs(int node , int par){
    int mx = -1 , bigchild = -1 ; 
    for(int child : a[node]){
        if(child == par) continue ; 
        depth[child] = depth[node] + 1 ;
        dfs(child , node) ; 
        if((int)st[child].size() > mx) {
            mx = (int)st[child].size() ; 
            bigchild = child ; 
        }
    }
    if(bigchild != -1) {
        st[node].swap(st[bigchild]) ; 
        for(auto pi2 : queries[node])
            ans[pi2[1]] += (int)st[node].size() - st[node].order_of_key({depth[node] + pi2[0] , -(int)2e9}) ; 
    }
    st[node].insert({depth[node] , node}) ; 
    for(auto child : a[node]){
        if(child == par || child == bigchild) continue ; 
        for(auto pi1 : st[child]){
            for(auto pi2 : queries[node])
                ans[pi2[1]] += (int)st[node].size() - 
                                    st[node].order_of_key({- depth[pi1.S] + pi2[0] + 2 * depth[node], -(int)2e9}) ; 
        }
        for(auto pi1 : st[child]){
            st[node].insert(pi1) ; 
        }
    }
}
void solve(){
    int n , q ;
    cin >> n >> q;
    for(int i = 1 ; i < n ; i ++){
        int u , v ; 
        cin >> u >> v ; 
        a[u].push_back(v) ; 
        a[v].push_back(u) ; 
    }
    for(int i = 1 ; i <= q ; i++){
        int u , k ;
        cin >> u >> k ;
        queries[u].push_back({k , i}) ; 
    }
    dfs(1 , 0) ; 
    for(int i = 1 ; i <= q ; i++) cout << ans[i] << endl  ;
    cout << endl ; 
}   

int main(){
    fast 
    
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif

    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  

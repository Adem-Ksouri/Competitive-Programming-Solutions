#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nop cout << -1 << endl;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

const int N = 100100 ; 
vector<int> adj[N] ; 
int vis[N] ;
ll fact[N] ;  
int c , cnt;
bool ok ;

void dfs(int node , int par){
    vis[node] = 1 ;
    cnt++ ; 
    for(int child : adj[node]){
        if(child == par) continue ; 
        if(vis[child] == 1) ok = true; 
        if(!vis[child]) dfs(child , node) ; 
    }
    vis[node] = 2 ;
}
void solve(){
    int n , k ; 
    cin >> n >> k; 
    for(int i = 1 ; i <= k ; i++) {
        int a , b ; 
        cin >> a >> b ; 
        adj[a].push_back(b) ; 
        adj[b].push_back(a) ; 
    }
    for(int i = 1 ; i <= n ; i++) {
        if(adj[i].size() > 2){
            cout << "-1\n" ; 
            return ;
        }
    }
    ok = false ;
    int c = 0 ;
    ll ans = 1 ;
    for(int i = 1 ; i <= n ; i++) {
        if(!vis[i]) {
            c++ ;
            cnt = 0; 
            dfs(i , 0) ; 
            if(cnt >= 2) ans *= 2 , ans %= mod ;
        }
    }
    if(ok) {
        cout << "-1\n" ;
        return ; 
    }
    cout << ans * fact[c] % mod << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fact[0] = 1 ;
    for(int i = 1 ; i < N ; i++) fact[i] = fact[i - 1] * i % mod ;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

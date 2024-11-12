#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define ld double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define double long double
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 200100 ; 
vector<array<ll,2>> a[N] ; 
ll pref[N] ; 
int up[N][20] , depth[N] , parent[N] ; 

void dfs_init(int node , int par){
    up[node][0] = par ; 
    for(int i = 1 ; i < 20 ; i++) up[node][i] = up[up[node][i-1]][i-1] ;

    for(auto [j,w] : a[node]){
        if( j == par) continue ; 
        pref[j] = pref[node] * w % mod ;
        depth[j] = depth[node] + 1 ; 
        parent[j] = node ;
        dfs_init( j , node ) ;
    }
}

int get_lca(int a , int b){
    if(depth[a] != depth[b]){
        int k = abs(depth[a] - depth[b]) ; 
        if(depth[b] < depth[a]) swap(a , b) ; 
        for(int i = 19 ; i>=0 ; i--){
            if((1<<i)&k) b = up[b][i] ; 
        }
    }
    for(int i = 19 ; i >= 0 ; i--){
        if(up[a][i] != up[b][i]) {
            a = up[a][i] ; 
            b = up[b][i] ; 
        }
    }
    if(a == b) return a ; 
    else return parent[a] ; 
}
    
void solve(){
    int n ;
    cin >> n ; 
    for(int i = 1 ; i < n; i++)  {
        int x , y , w ; 
        cin >> x >> y >> w ; 
        a[x].pb({y , w}); 
        a[y].pb({x , w}) ; 
    }
    
    int q ; cin >> q ; 

    pref[1] = pref[0] =  1 ;
    dfs_init(1 , 0) ;
    

    while(q--){
        int l , r ; 
        cin >> l >> r ;
        int g = get_lca(l , r) ;
        ll c1 = pref[r] * inv(pref[g]) % mod ;
        ll c2 = pref[l] * inv(pref[g]) % mod ; 
        cout << c1 * c2 % mod << endl; 
    }
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  

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

const int N = 1000010 ; 
vector<int> a[N] ; 
int c[N] , d[N] , val[N] ;

void dfs(int node, int par){
    int sz = 0 ;
    for(int child : a[node]){
        if(child == par) continue ; 
        int g = gcd(val[node] , val[child]) ; 
        d[g]++ ;
        sz++ ; 
        dfs(child , node) ;  
    }
    c[val[node]] += sz ; 
}
void solve(){
    int n , k  ;
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; i++) 
        cin >> val[i] ;
    for(int i = 1 ; i < n ; i++) {
        int u , v ; 
        cin >> u >> v ; 
        a[u].push_back(v) ; 
        a[v].push_back(u) ; 
    }
    dfs(1 , 0) ; 
    for(int i = 1 ; i <= k ; i++){
        int ans = 1 ;
        for(int j = i ; j < N ; j += i){
            ans += c[j] ; 
            ans -= d[j] ; 
        }
        if(val[1] % i == 0) ans-- ; 
        cout << ans << " " ;
    }
    cout << endl;
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

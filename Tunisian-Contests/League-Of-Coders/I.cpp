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
const ll inf = 1e16+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 22 ;
int a[N] , b[N] , c[N] ;
ll pref[N] ;  
ll dp[(1 << 22)] , sum[(1 << 22)]; 
int n  , m;

ll work(int mask){ 
    int idx = upper_bound(pref , pref + n , sum[mask]) - pref ;
    ll diff = pref[idx] - sum[mask] ;
    if(idx >= n) return 0 ; 
    if(mask == (1 << m) - 1) return -inf ;

    ll &ret = dp[mask] ; 
    if(ret != -1) return ret ; 

    ret = -inf ;
    for(int i = 0 ; i < m ; i++)
        if(((1 << i) & mask) == 0 && b[i] <= diff) ret = max(ret , c[i] + work((mask | (1 << i)))) ;
    return ret ; 
}

void solve(){
    cin >> n >> m ;
    for(int i = 0 ; i < (1 << 22) ; i++) dp[i] = -1 ;

    for(int i = 0 ; i < n ; i++) cin >> a[i] ; 
    for(int i = 0 ; i < m ; i++) cin >> b[i] ; 
    for(int i = 0 ; i < m ; i++) cin >> c[i] ; 
    
    for(int i = 0 ; i < n ; i++) pref[i] = (i > 0 ? pref[i - 1] : 0) + a[i] ; 

    pref[n] = pref[n - 1] ; 

    for(int i = 1 ; i < (1 << m) ; i++){
        for(int j = 0 ; j < m ; j++)
            if((1 << j) & i) sum[i] += b[j] ;
    }
    ll ans = work(0) ;
    if(ans <= 0) cout << 0 << endl;
    else cout << ans << endl;
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

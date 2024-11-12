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

const int N = 410 ; 
array<int,2> a[N] ; 
map<array<ll,4> , set<int>> f ;

void solve(){
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i][0] >> a[i][1] ; 
    for(int i = 1 ; i <= n ; i++)
        for(int j = i + 1 ; j <= n ; j++){
            ll dx = a[i][0] - a[j][0] , dy = a[i][1] - a[j][1] ;
            
            ll g = abs(__gcd(dx , dy)) ;

            dx /= g ;
            dy /= g ; 
            
            if(dx <= 0) dx *= -1 , dy *= -1 ; 
            ll b1 = a[j][1] * dx - dy * a[j][0] , b2 = dx ;
            if(b2 <= 0) b1 *= -1 , b2 *= -1 ; 

            g = abs(__gcd(b1 , b2)) ;            
            b1 /= g , b2 /= g ;

            if(dx == 0) {
                dy = 1 ;
                b1 = 0 , b2 = a[j][0] ; 
            }
            f[{dx , dy , b1 , b2}].insert(i) ; 
            f[{dx , dy , b1 , b2}].insert(j) ;  
        }
    ll ans = 0 ; 
    for(auto x : f){
        ll sz = (ll)x.S.size() ;
        ans += (sz * (sz - 1) * (sz - 2) * (sz - 3)) / 24 ; 
    }
    cout << ans << endl; 
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

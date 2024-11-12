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

const int N = 24 ; 
int a[(1 << N) + 5] , mx[4 * (1 << N) + 5] , gg[(1 << N) + 5];

void build(int id , int l , int r){
    if(l == r) {
        mx[id] = a[l] ; 
        gg[l] = id;
    }
    else {
        int mid = (l + r) / 2 ; 
        build(2 * id , l , mid) ; 
        build(2 * id +1, mid + 1 , r) ;
        mx[id] = max(mx[2 * id ] , mx[2 * id + 1]) ; 
    }
}



void solve(){
    int n ; 
    cin >> n ; 
    int sz = (1 << n) ; 
    for(int i = 0 ; i < sz ; i++) cin >> a[i] ;    

    build(1 , 0 , sz - 1) ; 
    
    for(int i = 0 ; i < sz ; i++) {
        int x = gg[i] ;
        ll ans = 0 ; 
        while(x != 1){
            int p = x / 2;
            int lc = 2 * p  , rc = 2 * p + 1 ;
            if(x == lc) ans += mx[rc] ; 
            else ans += mx[lc] ; 
            x = p ; 
        }
        cout << ans << " " ;
    }
    cout << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

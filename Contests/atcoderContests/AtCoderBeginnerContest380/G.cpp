 //#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
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
const ll mod = 998244353;
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
#define int ll
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll inv(ll N) {
    if (N == 1) return 1;
    return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;
}

 int add(int a, int b) {
    a %= mod ;
    b %= mod ;
     return (a + 0ll + b) % mod;
 }

 int mult(int a, int b) {
    a %= mod ;
    b %= mod ;
     return a * 1ll * b % mod;
 }

 int sub(int a, int b) {
    a %= mod ;
    b %= mod ;
     return (a - 0ll - b + mod) % mod;
 }

 int divide(int a, int b) {
    a %= mod ;
    b %= mod ;
     return a * 1ll * inv(b) % mod;
 }
const int N = 200100 ;
int p[N] ;
ll pref[N] ;
ll res[N] ;
ll f[N];
ordered_set st[2] ;

int get_lower(int x , int i) {
    return st[i].order_of_key({x , -(int)2e9}) ;
}
int get_greater(int x , int i) {
    return st[i].size() - st[i].order_of_key({x , (int)2e9}) ;
}

void solve() {
    int n , k ;
    cin >> n >> k ;
    int g = inv(2) ;
    for(int i = 1 ; i <= n ; i++) cin >> p[i] ;
    for(int i = 1 ; i <= n ; i++) {
        int cur = get_greater(p[i] , 0) ;
        pref[i] = add(pref[i - 1] , cur) ;
        st[0].insert({p[i] , i});
    }
    st[0].clear() ;
    for(int i = 1 ; i <= k ; i++) st[1].insert({p[i] , i}) ;

    ll cur = 0 ;
    for(int i = k + 1 ; i <= n ; i++) {
        cur = sub(cur , get_greater(p[i - k] , 0)) ;
        cur = add(cur , get_greater(p[i] , 0)) ;
        st[1].erase({p[i - k] , i - k}) ;
        st[0].insert({p[i - k] , i - k}) ;
        st[1].insert({p[i] , i}) ;

        cur = add(cur ,get_lower(p[i - k] , 1)) ;
        res[i - k + 1] = cur ;
    }

    ll ans = 0;
    for(int i = 1 ; i <= n - k + 1 ; i++) {

        ll cnt = pref[i - 1] ;
        cnt = add(cnt , res[i]) ;
        cnt = add(cnt , sub(pref[n] , pref[i + k - 1])) ;

        ll cur = mult(k , k - 1) ;
        cur = mult(cur , g) ;
        cur = mult(cur , cur) ;
        cur = mult(cur , f[k - 2]) ;
        cur = add(cur , mult(f[k] , cnt)) ;
        ans = add(ans , cur) ;
    }
    cout << mult(ans , inv(mult(f[k], n - k + 1))) << endl;
}


signed main() {
    FAST
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
    f[0] = 1;
    for(int i = 1 ; i < N ; i++) f[i] = mult(f[i - 1] , i) ;
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}


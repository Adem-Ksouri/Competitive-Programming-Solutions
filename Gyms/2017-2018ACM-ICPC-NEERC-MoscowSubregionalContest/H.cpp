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
const ll mod = 1e9 + 7;
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

const int N = 100100;

ll sum(ll l , ll r) {
    return (r - l + 1) * (l  + r) / 2 ;
}
array<ll,2> work(array<ll,2> pi , array<ll,2> pj) {
    array<ll,2> ans;
    ans[1] = 0 ;
    ans[2] = 0;
    if(pi[1] > pj[1]) swap(pi[1] , pj[1]) ;
    if(pi[1] + pj[0] - pi[0] < pj[1]) return {-1 , -1} ;

    // part 1
    ll l = 0 , r = pi[1] , lo = 0  ;
    while(l <= r) {
        ll mid = (l + r) / 2 ;
        int pos = pi[0] + mid ;
        int lst_pos = pj[0] - (pj[1] - pi[1] + mid) ;
        if(pi[1] - mid + pj[0] - pos < pj[1]) {
            r = mid - 1;
        }else {
            lo = (lst_pos - pos - 1) * (pi[1] - mid) ;
            lo += sum(pi[1] - mid , pj[1]) ;
            lo += sum(pi[1] - mid , pi[1]) ;
            l = mid + 1 ;
        }
    }
    ans[0] = lo ;

    // part 2
    ll ro = 0;
    ll diff = pj[1] - pi[1] ;
    ll pos = pi[0] + diff ;
    ro += sum(pi[1] , pj[1]) ;
    ro += (pj[0] - pos) * pj[1] ;
    ll x = pj[0] - pos + 1;
    x -= 2 ;
    if(x > 0) {
        ll g = (x + 1) / 2;
        if(x & 1) {
            ro += g * (1 + x) / 2;
        }else {
            ro += g * (x + 2) / 2 ;
        }
    }
    ans[1] = ro ;
    ans[0] -= (pi[1] + pj[1]) ;
    ans[1] -= (pi[1] + pj[1]) ;
    return ans ;
}
void solve() {
    ll t , n , m ;
    cin >> t >> n >> m ;
    vector<array<ll,2>> a(m + 1) ;
    for(int i = 1 ; i <= m ; i++) cin >> a[i][0] >> a[i][1] ;
    sort(a.begin() + 1 , a.end()) ;
    ll lo = 0 , ro = 0 ;
    if(a[1][0] > 1) {
        ll l = max(0ll , a[1][1] - a[1][0] + 1) ;
        ll mn = sum(l , a[1][1]) ;
        ll r = a[1][1] + a[1][0] - 1;
        ll mx = sum(a[1][1] , r) ;
        mn -= a[1][1] ;
        mx -= a[1][1] ;
        lo += mn ;
        ro += mx ;
    }
    if(a[m][0] < n) {
        ll l = max(0ll , a[m][1] - (n - a[m][0])) ;
        ll mn = sum(l , a[m][1]) ;
        ll mx = sum(a[m][1] , a[m][1] + (n - a[m][0])) ;
        mn -= a[m][1] ;
        mx -= a[m][1] ;
        lo += mn ;
        ro += mx ;
    }
    for(int i = 1 ; i < m ; i++) {
        array<ll,2> pi = work(a[i] , a[i + 1]) ;
        if(pi[0] == -1) {
            cout << "No" << endl;
            return ;
        }
        lo += pi[0] , ro += pi[1] ;
    }
    for(int i = 1 ; i <= m ;i++) {
        lo += a[i][1] ;
        ro += a[i][1] ;
    }
    if(t >= lo && t <= ro) cout << "Yes" << endl;
    else cout << "No" << endl;

}

signed main() {
    FAST
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
    int tc = 1;
    //cin >> tc;
    while (tc--) solve();
    return 0;
}


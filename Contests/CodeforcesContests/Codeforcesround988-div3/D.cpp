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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll inv(ll N) {
    if (N == 1) return 1;
    return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;
}


void solve() {
    int n  , m , L;
    cin >> n >> m >> L ;
    map<int,vector<int>> f ;
    vector<array<int,2>> a(n) ;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i][0] >> a[i][1] ;
    for(int i = 0 ; i < m ; i++) {
        int x , v ;
        cin >> x >> v ;
        f[x].push_back(v) ;
    }
    ll p = 0 ;
    multiset<int> st ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++) {
        auto [l , r] = a[i] ;
        int pre = 0 ;
        if(i > 0) pre = a[i - 1][1] + 1 ;
        for(auto it = f.lower_bound(pre) ; it != f.end() ; it++) {
            auto [x , vec] = *it ;
            if(x > l) break ;
            for(auto y : vec)
                st.insert(y) ;
        }
        int len = r - l + 1 ;
        while(p < len) {
            if(st.empty()) {
                cout << "-1" << endl;
                return ;
            }
            int g = *st.rbegin() ;
            st.erase(prev(st.end())) ;
            p += g ;
            ans++ ;
        }
    }
    cout << ans << endl;
}

int main() {
    FAST
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}


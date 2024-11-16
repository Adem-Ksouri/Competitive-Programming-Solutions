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
const int N = 500100 ;
int cnt[N] ;
 struct DSU {
     vector<int> sz, parent , color , left , right;

     void init(int n) {
         for (int i = 0; i < n; i++) {
             parent.pb(i);
             sz.pb(1);
             color.pb(i) ;
             left.pb(i) ;
             right.pb(i) ;
         }
     }

     int get(int u) { return (parent[u] == u ? u : parent[u] = get(parent[u])); }

     bool unite(int u, int v) {
         u = get(u);
         v = get(v);
         if (u == v) return false;
         if (sz[u] < sz[v]) swap(u, v);
         parent[v] = u;
         sz[u] += sz[v];
         left[u] = min(left[u] , left[v]) ;
         right[u] = max(right[u] , right[v]) ;
         return true;
     }

     bool same_set(int u, int v) { return get(u) == get(v); }
     int size(int u) { return sz[get(u)]; }
 };
void solve() {
    int n , q ;
    cin >> n >> q ;
    for(int i = 0 ; i <= n ; i++) cnt[i] = 1;
    DSU dsu ;
    dsu.init(n + 5) ;
    while(q--) {
        int type ;
        cin >> type ;
        if(type == 1) {
            int x , c ;
            cin >> x >> c ;

            int p = dsu.get(x) ;
            int len = (dsu.right[p] - dsu.left[p] + 1);
            cnt[dsu.color[p]] -= len ;
            cnt[c] += len ;
            
            int l = dsu.get(dsu.left[p] - 1) ;
            int r = dsu.get(dsu.right[p] + 1) ;
            if(dsu.color[l] == c) dsu.unite(p , l) ;
            if(dsu.color[r] == c) dsu.unite(p , r) ;
            dsu.color[dsu.get(x)] = c ;
        }else {
            int x ;
            cin >> x ;
            cout << cnt[x] << endl;
        }
    }
}

int main() {
    FAST
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}


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

int query(int l , int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush() ;
    int x ;
    cin >> x ;
    return x;
}
void solve() {
    int n ;
    cin >> n ;
    vector<int> vec ;
    vector<int> ans(n + 1) ;
    int beg = -1, lst = 0 ;
    for(int i = 2 ; i <= n ; i++) {
        int x = query(1 , i) ;
        lst = x;
        if(x > 0){
            beg = i ;
            break;
        }
    }
    if(beg == -1) {
        cout << "! IMPOSSIBLE" << endl;
        cout.flush() ;
        return;
    }
    for(int i = 1 ; i <= beg - 1 - lst ; i++) ans[i] = 1;
    ans[beg] = 1;

    for(int i = beg + 1 ; i <= n ; i++) {
        int x = query(1 , i) ;
        if(x > lst) ans[i] = 1;
        else ans[i] = 0;
        lst = x ;
    }
    cout << "! " ;
    for(int i = 1 ; i <= n ; i++) cout << ans[i] ;
    cout << endl;
    cout.flush() ;
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


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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll inv(ll N) {
    if (N == 1) return 1;
    return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;
}

int add(int a, int b) {
    return (a + 0ll + b) % mod;
}

int mult(int a, int b) {
    return a * 1ll * b % mod;
}

int sub(int a, int b) {
    return (a - 0ll - b + mod) % mod;
}

int divide(int a, int b) {
    return a * 1ll * inv(b) % mod;
}

const int N = 1000100;
int spf[N];
int a[N];
int dp[N];
int ans[N] ;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n ; i >= 1; i--) {
        vector<int> d;
        vector<int> vec;
        int x = a[i];
        while (x > 1) {
            int g = spf[x];
            while (x % g == 0)
                x /= g;
            d.push_back(g);
        }
        int sz = d.size();
        int ways = 0;
        for (int mask = 1; mask < (1 << sz); mask++) {
            int prod = 1;
            int c = 0;
            for (int j = 0; j < sz; j++)
                if ((1 << j) & mask)
                    prod *= d[j], c++;
            vec.push_back(prod);
            if (c & 1)
                ways = add(ways, dp[prod]);
            else
                ways = sub(ways, dp[prod]);
        }
        if(i == n) ways = 1 ;
        ans[i] = ways ;
        for(auto prod : vec)
            dp[prod] = add(dp[prod] , ways) ;
    }
    cout << ans[1] << endl;
}

int main() {
    FAST
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
#endif
    for (int i = 1; i < N; i++) spf[i] = i;
    for (int i = 2; i < N; i++) {
        if (spf[i] < i) continue ;
        for (int j = i; j < N; j += i)
            spf[j] = min(spf[j], i);
    }
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}


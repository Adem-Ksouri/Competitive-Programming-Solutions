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

string get(int a){
    string ret = "";
    while (a > 0){
        int r = a % 3;
        ret += (char)(r + '0');
        a /= 3;
    }
    return ret;
}

void solve(){
    int a, c;
    cin >> a >> c;
    string sa = get(a);
    string sc = get(c);
    int sz = max((int)sa.size(), (int)sc.size());
    while ((int)sa.size() < sz) sa += '0';
    while ((int)sc.size() < sz) sc += '0';
    string sb = "";
    for (int i = 0; i < sz; i++){
        int x = sa[i] - '0', y = sc[i] - '0';
        int val = (y - x + 3) % 3;
        sb += (char)(val + '0');
    }
    ll ans = 0, pow = 1;
    for (int i = 0; i < sz; i++){
        ll x = sb[i] - '0';
        ans += x * pow;
        pow *= 3;
    }
    cout << ans << endl;
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

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
const int N_Max = 1e6 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

int spf[N_Max];
int occ[N_Max];
int po[N_Max];

void sieve(){
    for (int i = 1; i < N_Max; i++) spf[i] = i;
    for (int i = 2; i < N_Max; i++){
        if (spf[i] != i) continue;
        for (int j = i; j < N_Max; j += i) spf[j] = min(spf[j], i);
    }
}

vector<int> factorize(int x){
    map<int, int> mp;
    while (x > 1){
        mp[spf[x]]++;
        x /= spf[x];
    }
    vector<int> ret;
    for (auto [p, occ] : mp) ret.pb(p);
    return ret;
}

void solve(){
    int N, Q;
    cin >> N;
    po[0] = 1;
    for (int i = 1; i <= N; i++) po[i] = po[i - 1] * 1LL * 2 % mod;
    for (int i = 1; i <= N; i++){
        int x;
        cin >> x;
        vector<int> vec = factorize(x);
        int sz = (int)vec.size();
        for (int mask = 0; mask < (1 << sz); mask++){
            int prod = 1;
            for (int j = 0; j < sz; j++)
                if (mask & (1 << j)) prod *= vec[j];
            occ[prod]++;
        }
    }
    cin >> Q;
    for (int q = 1; q <= Q; q++){
        int x;
        cin >> x;
        vector<int> vec = factorize(x);
        int sz = (int)vec.size();
        int cnt = 0;
        for (int mask = 1; mask < (1 << sz); mask++){
            int prod = 1, mult = -1;
            for (int j = 0; j < sz; j++){
                if (mask & (1 << j)){
                    mult *= -1;
                    prod *= vec[j];
                }
            }
            cnt += occ[prod] * mult;
        }
        cout << po[N - cnt] << endl;
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    sieve();
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

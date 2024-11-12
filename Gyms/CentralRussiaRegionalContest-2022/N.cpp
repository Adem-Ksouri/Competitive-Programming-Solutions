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

ll B = 9973;

ll binpow(ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
	int N;
	cin >> N;
	vector<int> sz(N + 1);
	vector<ll> hash(N + 1);
	for (int i = 1; i <= N; i++){
		string s;
		cin >> s;
		sz[i] = (int)s.size();
		for (int j = 0; j < sz[i]; j++)
			hash[i] = (hash[i] + (int)s[j] * 1LL * binpow(B, j) % mod) % mod;
	}
	string s;
	cin >> s;
	int len = (int)s.size();
	vector<int> dp(len + 1);
	vector<ll> pref(len + 1);
	vector<ll> inverse(len + 1);
	s = "#" + s;
	for (int i = 1; i <= len; i++)
		pref[i] = (pref[i - 1] + (int)s[i] * 1LL * binpow(B, i) % mod) % mod;
	for (int i = 0; i <= len; i++)
		inverse[i] = inv(binpow(B, i));
	dp[0] = 1;
	for (int i = 1; i <= len; i++){
		for (int j = 1; j <= N; j++){
			if (sz[j] > i) continue;
			int l = i - sz[j] + 1, r = i;
			ll h = (pref[r] - pref[l - 1] + mod) % mod * inverse[l] % mod;
			if (h == hash[j]) dp[i] |= dp[l - 1];
		}
	}
	cout << (dp.back() ? "YES" : "NO") << endl;
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

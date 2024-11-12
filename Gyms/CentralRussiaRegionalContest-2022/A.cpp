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

string a, b, s;
int sz;

int get(char c){
	if (c >= '0' && c <= '9') return c - '0';
	return c - 'A' + 10;
}

char get(int x){
	if (x <= 9) return (char)(x + '0');
	return (char)('A' + x - 10);
}

bool work(int base){
	int r = 0;
	string ret = "";
	for (int i = sz - 1; i >= 0; i--){
		int val = r + get(a[i]) + get(b[i]);
		int x = val % base;
		r = val / base;
		ret += get(x);
	}
	if (r > 0) ret += get(r);
	reverse(ret.begin(), ret.end());
	return ret == s;
}

void solve(){
	cin >> a >> b >> s;
	vector<int> ans;
	sz = max((int)a.size(), (int)b.size());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while ((int)a.size() < sz) a += '0';
	while ((int)b.size() < sz) b += '0';
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int base = 1; base <= 37; base++){
		bool good = true;
		for (char c : a)
			if (get(c) >= base) good = false;
		for (char c : b)
			if (get(c) >= base) good = false;
		for (char c : s)
			if (get(c) >= base) good = false;
		if (good && work(base)) ans.pb(base);
	}
	if ((int)ans.size() == 1) cout << ans.back() << endl;
	else cout << 0 << endl;
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

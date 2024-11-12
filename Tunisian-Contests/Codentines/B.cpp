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

struct Node{
	ll res[6][6];
};

Node st[4 * N_Max], lazy[4 * N_Max];
int pref[6][6][N_Max];
int N, Q;

void merge(int id, int l, int r){
	for (int p = 1; p <= 5; p++)
		for (int k = 0; k < p; k++)
			st[id].res[p][k] = st[l].res[p][k] + st[r].res[p][k];
}

void pushdown(int id, int ns, int ne){
	int lc = 2 * id, rc = 2 * id + 1;
	int mid = ns + (ne - ns) / 2;
	for (int p = 1; p <= 5; p++){
		for (int k = 0; k < p; k++){
			lazy[lc].res[p][k] += lazy[id].res[p][k];
			lazy[rc].res[p][k] += lazy[id].res[p][k];
			st[lc].res[p][k] += lazy[id].res[p][k] * 1LL * (pref[p][k][mid] - pref[p][k][ns - 1]);
			st[rc].res[p][k] += lazy[id].res[p][k] * 1LL * (pref[p][k][ne] - pref[p][k][mid]);
			lazy[id].res[p][k] = 0;
		}
	}
}

void update(int id, int ns, int ne, int l, int r, int p, int k, int x){
	if (ns > r || ne < l) return;
	if (ns >= l && ne <= r){
		int cnt = pref[p][k][ne] - pref[p][k][ns - 1];
		st[id].res[p][k] += cnt * 1LL * x;
		lazy[id].res[p][k] += x;
		return;
	}
	pushdown(id, ns, ne);
	int mid = ns + (ne - ns) / 2;
	int lc = 2 * id;
	int rc = 2 * id + 1;
	update(lc, ns, mid, l, r, p, k, x);
	update(rc, mid + 1, ne, l, r, p, k, x);
	merge(id, lc, rc);
}

ll get(int id, int l, int r){
	ll ret = 0;
	for (int p = 1; p <= 5; p++){
		for (int k = 0; k < p; k++){
			ret += st[id].res[p][k];
		}
	}
	return ret;
}

ll query(int id, int ns, int ne, int l, int r){
	if (ns > r || ne < l) return 0;
	if (ns >= l && ne <= r) return get(id, ns, ne);
	pushdown(id, ns, ne);
	int mid = ns + (ne - ns) / 2;
	int lc = 2 * id;
	int rc = 2 * id + 1;
	return query(lc, ns, mid, l, r) + query(rc, mid + 1, ne, l, r);
}

void solve(){
	cin >> N >> Q;
	for (int i = 1; i <= 4 * N; i++)
		for (int p = 1; p <= 5; p++)
			for (int k = 0; k < p; k++)
				st[i].res[p][k] = lazy[i].res[p][k] = 0;
	for (int p = 1; p <= 5; p++)
		for (int k = 0; k < p; k++)
			for (int i = 1; i <= N; i++)
				pref[p][k][i] = pref[p][k][i - 1] + (i % p == k);
	for (int q = 1; q <= Q; q++){
		int t;
		cin >> t;
		if (t == 1){
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, N, l, r) << endl;
		}
		else{
			int l, r, p, k, x;
			cin >> l >> r >> p >> k >> x;
			update(1, 1, N, l, r, p, k, x);
		}
	}
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

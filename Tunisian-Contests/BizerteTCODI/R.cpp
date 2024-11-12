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
const int LOG = 22;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  max(a, b); }
    void init(ll _n) { n = _n; seg.assign(2*n,ID); }
    void pull(ll p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(ll p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(ll l, ll r) {   // sum on llerval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }return comb(ra,rb);
    }
};

vector<int> divisors[N_Max];
int a[N_Max], b[N_Max];
int st[N_Max][LOG];
int pref[N_Max];
Seg<int> stree;
int lg[N_Max];

int query(int l, int r){
    int i = lg[r - l + 1];
    return __gcd(st[l][i], st[r - (1 << i) + 1][i]);
}

void solve(){
    int N, Q;
    cin >> N >> Q;
    stree.init(N + 5);
    for(int i = 1 ; i <= N; i++) cin >> a[i]; 
    for(int i = 1 ; i <= N; i++) cin >> b[i]; 
    for(int i = 1 ; i <= N; i++){
        pref[i] = pref[i - 1] + (a[i] < b[i]);
        st[i][0] = a[i] - b[i];
        stree.upd(i, b[i]);
    }
    for (int j = 1; j < LOG; j++)
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
            st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    for (int q = 1; q <= Q; q++){
        int l, r;
        cin >> l >> r;
        int cnt = pref[r] - pref[l - 1];
        if (cnt > 0){
            cout << -1 << endl;
            continue;
        }
        int g = query(l, r);
        int mx = stree.query(l, r);
        int i = upper_bound(divisors[g].begin(), divisors[g].end(), mx) - divisors[g].begin();
        if (i >= (int)divisors[g].size()) cout << -1 << endl;
        else cout << divisors[g][i] << endl;
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    for (int i = 2; i < N_Max; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 1; i < N_Max; i++)
        for (int j = i; j < N_Max; j += i)
            divisors[j].pb(i);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}

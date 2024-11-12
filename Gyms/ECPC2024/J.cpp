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
#define int ll
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

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = -1e18;    ll n; vector<T> seg;
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

template<class T> struct Seg1 { // comb(ID,b) = b
    const T ID = 1e18;    ll n; vector<T> seg;
    T comb(T a, T b) { return  min(a, b); }
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

int l[N_Max], r[N_Max];
ll pref[N_Max];
ll a[N_Max];
Seg<ll> st, st2;
Seg1<ll> st1;
int N;

void prep_nxt(){
    vector<int> stack;
    for (int i = 1; i <= N; i++) r[i] = N;
    for (int i = 1; i <= N; i++){
        while (!stack.empty() && a[stack.back()] > a[i]){
            r[stack.back()] = i - 1;
            stack.pop_back();
        }
        stack.pb(i);
    }
}
 
void prep_prev(){
    vector<int> stack;
    for (int i = 1; i <= N; i++) l[i] = 1;
    for (int i = N; i >= 1; i--){
        while (!stack.empty() && a[stack.back()] > a[i]){
            l[stack.back()] = i + 1;
            stack.pop_back();
        }
        stack.pb(i);
    }
}

void solve(){
    cin >> N;
    st.init(N + 5);
    st1.init(N + 5);
    st2.init(N + 5);
    set<array<ll, 3>> s;
    multiset<ll> ms, ms1;
    for (int i = 1; i <= N; i++) cin >> a[i];
    prep_nxt();
    prep_prev();
    for (int i = 1; i <= N; i++) pref[i] = pref[i - 1] + a[i];
    ll mx = -1e15;
    for (int i = 1; i <= N; i++){
        st1.upd(i, a[i]);
        st.upd(i, -pref[i - 1] + mx);
        st2.upd(i, -pref[i - 1]);
        mx = max(mx, a[i]);
    }
    int p = 0;
    ll ans = 0, mn_pref = 0, mx_sum = -1e15;
    for (int i = 1; i <= N; i++){
        ll best1 = st.query(l[i], i) - a[i];
        ll best2 = st2.query(l[i], i) - a[i];
        s.insert({r[i], best1, best2});
        ms.insert(best1);
        ms1.insert(best2);

        while (!s.empty() && (*s.begin())[0] < i){
            auto [ind, x1, x2] = *s.begin();
            s.erase(s.begin());
            ms.erase(ms.find(x1));
            ms1.erase(ms1.find(x2));
        }

        assert(!ms.empty() && !ms1.empty());

        ans = max(ans, mx_sum + a[i]);

        ans = max(ans, pref[i] - mn_pref);

        ans = max(ans, pref[i] + *ms.rbegin());
        
        ll val = pref[i] + *ms1.rbegin();
        mx_sum = max(mx_sum, val);

        if (pref[i] < mn_pref){
            mn_pref = pref[i];
            p = i;
        }

        cout << ans << " ";
    }
    cout << endl;
}

int32_t main(){
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

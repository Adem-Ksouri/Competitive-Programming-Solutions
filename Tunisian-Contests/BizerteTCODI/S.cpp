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
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

const int N = 500100 ; 
int a[N] ; 
vector<int> adj[N] ;
int tin[N] , tout[N];
int euler[N] ;
vector<array<int,4>> query ;
int timer = 0;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  (a + b); }
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
    const T ID = 2e9;    ll n; vector<T> seg;
    T comb(T a, T b) { return  min(a , b); }
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
template<class T> struct Seg2 { // comb(ID,b) = b
    const T ID = 0;    ll n; vector<T> seg;
    T comb(T a, T b) { return  max(a , b); }
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

void dfs_init(int node , int par) {
    tin[node] = ++ timer ;
    euler[timer] = node ;
    for(int child : adj[node])
        dfs_init(child , node) ;
    tout[node] = timer ;
}
void solve(){
    int n , q ; 
    cin >> n >> q ; 

    Seg<int> st_sum;
    st_sum.init(N) ;
    Seg1<int> st_min;
    st_min.init(N) ;
    Seg2<int> st_max;
    st_max.init(N) ;

    for(int i = 2 ; i <= n ; i++){
        int par ; 
        cin >> par ;
        adj[par].push_back(i) ;  
    }
    for(int i = 1 ; i <= n ; i++) 
        cin >> a[i];
    for(int i = 0 ; i < q ; i++){
        int t ; 
        cin >> t ; 
        if(t == 1){
            int p , u , val;
            cin >> p >> u >> val ;
            a[u] = val ;
            adj[p].push_back(u) ;
            query.push_back({1 , p , u , val}) ;
        }else if(t == 2){
            int u ;     
            cin >> u ;
            query.push_back({2 , u , -1 , -1}) ;
        }else if(t == 3){
            int u , val ; 
            cin >> u >> val ; 
            query.push_back({3 , u , val , -1}) ;
        }else {
            int u ;
            cin >> u ;
            query.push_back({4 , u , -1 , -1}) ;
        }
    }
    dfs_init(1 , 0) ;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] < N){
            st_sum.upd(a[i] , 1) ;
            st_max.upd(a[i] , tin[i]) ; 
            st_min.upd(a[i] , tin[i]) ;
        }
    }
    for(int i = 0 ; i < q ; i++){
        auto [type , p, u , val] = query[i] ;
        if(type == 1){
            if(val < N){
                st_sum.upd(val , 1) ; 
                st_max.upd(val , tin[u])  ;
                st_min.upd(val , tin[u]) ;
            }
        }else if(type == 2){
            for(int j = tin[p] ; j <= tout[p] ; j++){
                int node = euler[j] ;
                if(a[node] < N){
                    st_sum.upd(a[node] , 0) ;
                    st_max.upd(a[node] , 0) ;
                    st_min.upd(a[node] , 2e9) ; 
                }
            }
        }else if(type == 3){
            if(a[p] < N){
                st_sum.upd(a[p] , 0) ; 
                st_max.upd(a[p] , 0) ;
                st_min.upd(a[p] , 2e9) ;
            }
            a[p] = u ;
            if(a[p] < N){
                st_sum.upd(a[p] , 1) ; 
                st_max.upd(a[p] , tin[p]) ;
                st_min.upd(a[p] , tin[p]) ;
            }
        }else {
            int l = 1 , r = N - 1 , ans = 0 ;
            while(l <= r){
                int mid = (l + r) / 2 ;
                if(st_sum.query(0 , mid - 1) == mid && 
                            st_min.query(0 , mid - 1) >= tin[p] &&
                                        st_max.query(0 , mid - 1) <= tout[p]) {
                    ans = mid ;
                    l = mid + 1;
                }else 
                    r = mid - 1;
            }
            cout << ans << endl;
        }
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

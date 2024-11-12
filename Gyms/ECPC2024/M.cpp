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

const int N = 100100 ; 
int a[N] ;
array<int,2> queries[N] , diff[N] ; 
ll res[N] ;

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
void solve(){
    int n , q; 
    cin >> n >> q;
    Seg<int> st ;
    st.init(n + 5) ;
    for(int i = 1 ; i <= n ; i++) 
        cin >> a[i] ;
    for(int i = 1 ; i < n ; i++) diff[i] = {a[i] - a[i + 1] , i} ; 
    for(int i = 1 ; i <= q ; i++) {
        int x ; 
        cin >> x ;
        queries[i] = {x , i} ; 
    }
    sort(queries + 1 , queries + q + 1) ; 
    sort(diff + 1 , diff + n) ;  
    ll ans = 0 ;
    int j = 1 ; 
    for(int i = 1 ; i <= q ; i++){
        auto [x , idx] = queries[i] ; 
        while(j < n) {
            auto [curdiff , pos] = diff[j] ;    
            if(curdiff > x) break ;
            int lo = pos + 1 , ro = n , mxr = -1;
            while(lo <= ro) {
                int mid = (lo + ro) / 2 ;
                int g = st.query(pos + 1 , mid) ;
                if(g == mid - pos) {
                    mxr = mid ; 
                    lo = mid + 1 ;
                }else ro = mid - 1;
            }   
            if(mxr != -1) {
                mxr++ ;
                ll len = mxr - pos ;
                ans -= (len * (len + 1) / 2 - len);
            }         
            lo = 1 , ro = pos - 1 ;
            int mxl = -1 ;
            while(lo <= ro){
                int mid = (lo + ro) / 2 ;
                if(st.query(mid , pos - 1) == pos - mid) {
                    mxl = mid ; 
                    ro = mid - 1 ;
                }else lo = mid + 1;
            }
            if(mxl != -1) {
                ll len = pos - mxl + 1 ;
                ans -= (len * (len + 1) / 2 - len);
            }
            if(mxl == -1) mxl = pos ;
            if(mxr == -1) mxr = pos + 1;
            ll len = mxr - mxl + 1;
            ans += (len * (len + 1) / 2 - len) ;
            

            st.upd(pos , 1) ; 
            j++ ; 
        }
        res[idx] = ans ;
    }
    for(int i = 1 ; i <= q ; i++) cout << res[i] << " " ;
    cout << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}

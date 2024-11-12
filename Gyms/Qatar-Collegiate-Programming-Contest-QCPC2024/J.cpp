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
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
const ll sup = 1e18;
const ll inf = -1e18;
const ll mod = 1e9 + 7;
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
#define int ll
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}


void solve(){
    int n , m ;
    cin >> n >> m ;
    vector<int> a(n + m + 1) ;
    vector<int> b(n + m + 1) ;
    for(auto &x : a) cin >> x ;
    for(auto &x : b) cin >> x ;
    ll s1 = 0 , s2 = 0;
    for(int i = 0 ; i < n + m + 1 ; i++){
        s1 += a[i] ;
        s2 += b[i] ;
    }
    if(n == 0 && m == 0){
        cout << 0 << endl;
        return ;
    }
    if(n == 0){
        for(int i = 0 ; i < m + 1 ; i++){
            cout << s2 - b[i] << " " ;
        }
        cout << endl;
        return ;
    }
    if(m == 0){
        for(int i = 0 ; i < n + 1 ; i++)
            cout << s1 - a[i] << " " ;
        cout << endl;
        return ;
    }
    ordered_set st ;
    for(int i = 0 ; i < n + m + 1 ; i++)
        st.insert({a[i] - b[i] , i}) ;
    int c = 0;
    ll sum = 0;
    for(auto [x , y] : st){
        if(c == m) break ;
        sum -= x;
        c++ ;
    }
    auto [g1 , g2] = *st.find_by_order(m) ; 
    for(int i = 0 ; i < n + m + 1 ; i++){
        int idx = st.order_of_key({a[i] - b[i] , i}) ;
        if(idx >= m){
            cout << s1 - a[i] + sum << " " ;
        }else {
            cout << s1 - a[i] + sum - (-a[i] + b[i]) - g1 << " ";
        }
    }
    cout << endl;
}

signed main(){
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

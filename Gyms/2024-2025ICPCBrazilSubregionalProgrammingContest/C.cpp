//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
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
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
#define int ll
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

void count_sort(vector<int> &p , vector<int> &c){
    int n = (int)p.size() ;
    vector<int> cnt(n) ;
    for(auto x : c) cnt[x]++ ;
    
    vector<int> pos(n) ;
    pos[0] = 0;
    for(int i = 1 ; i < n ; i++) pos[i] = pos[i - 1] + cnt[i - 1] ;
    vector<int> new_p(n);
    for(auto x : p){
        int g = c[x] ;
        new_p[pos[g]] = x ;
        pos[g]++ ;
    }
    p = new_p;
}

void buildSuffixArray(vector<int> &s , vector<int> &p , vector<int> &c){
    int n = s.size() ;
    
    // build for length 1
    vector<pair<int,int>> vec(n) ;
    for(int i = 0 ; i < n ; i++) vec[i] = {s[i] , i} ;
    sort(vec.begin() , vec.end()) ;
    for(int i = 0 ; i < n ; i++) p[i] = vec[i].S ;
    c[p[0]] = 0;
    for(int i = 1 ; i < n ; i++)
        c[p[i]] = c[p[i - 1]] + (vec[i].F != vec[i - 1].F) ;
    
    for(int k = 0 ; (1 << k) < n ; k++){
        for(int i = 0 ; i < n ; i++) 
            p[i] = (p[i] - (1 << k) + n) % n;
        count_sort(p , c) ;
        vector<int> new_c(n) ;
        new_c[p[0]] = 0;
        for(int i = 1 ; i < n ; i++) {
            pair<int,int> pre = {c[p[i - 1]] , c[(p[i - 1] + (1 << k)) % n]} ;
            pair<int,int> cur = {c[p[i]] , c[(p[i] + (1 << k)) % n]} ;
            new_c[p[i]] = new_c[p[i - 1]] ;
            if(pre != cur) new_c[p[i]]++ ;
        }
        c.swap(new_c) ;
    }
}

vector<int> build_lcp(vector<int> &s ,vector<int> &p , vector<int> &c){
    int n = (int)p.size() ;
    vector<int> lcp(n) ;
    int k = 0 ;
    for(int i = 0 ; i < n - 1 ; i++){
        int idx = c[i] ;
        int j = p[idx - 1] ;
        while(s[i + k] == s[j + k]) k++ ;
        lcp[idx] = k ;
        k = max(0ll , k - 1) ;
    }
    return lcp ;
}

void solve(){
    int n ;
    cin >> n ;
    vector<int> a(n) ;
    for(int i = 0 ; i < n ;i++) cin >> a[i] ;
    a.push_back(0) ;
    n++ ; 
    vector<int> p(n) , c(n)  ;
    buildSuffixArray(a , p , c) ;
    vector<int> lcp = build_lcp(a , p , c);
    vector<pair<int, int>> vec;
    ll res = 0, ans = 0;
    for(int i = 1 ; i < n ; i++){
        int new_l = 1;
        while (!vec.empty()){
            auto [l, r] = vec.back();
            if (lcp[r] < lcp[i]){
                new_l = r;
                break;
            }
            vec.pop_back();
            ans -= lcp[r] * (r - l);
        }
        ans += lcp[i] * (i - new_l);
        vec.push_back({new_l, i});
        res += 2 * ans;
    }
    for (int i = 1; i < n; i++) res += i;
    ll g = (n - 1) * (n - 1) ; 
    ll gg = gcd(res , g) ;
    res /= gg ; 
    g /= gg ; 
    cout << res << "/" << g << endl; 
}

signed main(){
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

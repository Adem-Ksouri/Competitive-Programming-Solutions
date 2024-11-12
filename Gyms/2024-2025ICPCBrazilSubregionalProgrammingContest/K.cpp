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

const int N = 110 ; 
bool dp[N][N * N] ;
int fs[N * N] ;
bool vis[N] ;
int a[N] ;

void solve(){
    int n ;
    cin >> n ;
    int s = 0;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ; 
        s += a[i] ;
    }
    if(s & 1){
        cout << -1 << endl;
        return ; 
    }
    s /= 2 ;
    dp[0][0] = 1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j <= 100 * n ; j++)
            dp[i][j] |= dp[i - 1][j] ;
        for(int j = 0 ; j <= 100 * n ; j++)
            if(dp[i - 1][j] && j + a[i] <= 100 * n)
                dp[i][j + a[i]] = true ;
        for(int j = 0 ; j <= 100 * n ; j++) {
            if(!dp[i][j] || fs[j]) continue;
            fs[j] = i;
        }
    }
    if(!fs[s]) {
        cout << -1 << endl;
        return; 
    }
    vector<int> idx ;
    while(s > 0){
        int g = fs[s] ;
        idx.push_back(g) ; 
        vis[g] = true ;
        s -= a[g] ; 
    }
    vector<int> p ;
    for(int i = 1 ; i <= n ; i++) 
        if(!vis[i])
            p.push_back(a[i]) ;
    sort(p.rbegin() , p.rend()) ; 
    for(int i = 0 ; i < idx.size() ; i++) idx[i] = a[idx[i]] ; 
    sort(idx.rbegin() , idx.rend()) ;
    
    int s1 = 0 , s2 = 0;
    int i = 0 , j = 0 ;
    vector<int> ans ;
    while(i < p.size() && j < idx.size()){
        if(s1 <= s2) {
            ans.push_back(p[i]) ; 
            s1 += p[i] ;
            i++ ; 
        }else {
            ans.push_back(idx[j]) ;
            s2 += idx[j] ;
            j++ ; 
        }
    }
    while(i < p.size()) 
        ans.push_back(p[i++]) ;
    while(j < idx.size())
        ans.push_back(idx[j++]) ;
    for(auto x : ans) cout << x << " " ;
    cout << endl; 
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

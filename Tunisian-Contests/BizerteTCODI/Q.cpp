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


ll p[19] ;

ll work(ll x){
    if(!x) return 0 ;
    string s = to_string(x) ;
    int sz = s.size() ; 
    ll ans = 0 ;
    for(int i = 0 ; i < (sz+1) / 2 ; i++){
        int g = s[i] - '0'; 
        if(i == 0 && g > 0) g-- ;   
        ans += p[(sz + 1) / 2 - i - 1] * g ;
    }
    string g = "" ; 
    for(int i = 0 ; i < sz/2 ; i++) g += s[i] ; 
    string temp = g ; 
    reverse(temp.begin() , temp.end()) ;
    if(sz & 1) g += s[sz / 2] ;
    g += temp ;
    bool ok = true ; 
    for(int i = 0 ; i < sz ; i++){
        if(g[i] == s[i]) continue; 
        if(g[i] > s[i]) {
            ok = false ;
            break ; 
        }
        if(g[i] < s[i]) {
            break ; 
        }
    } 

    if(ok) ans++ ;
    for(int i = 1 ; i <= sz - 1 ; i++) {
        if(i == 1) ans += 9 ;
        else ans += 9 * p[(i + 1) / 2 - 1] ;
    } 
    return ans ;
}

void solve(){
    ll l , r ; 
    cin >> l >> r ; 
    l-- ; 
    cout << work(r) - work(l) << endl; 
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    p[0] = 1 ;
    for(int i = 1 ; i <= 18 ; i++) p[i] = p[i - 1] * 10 ;
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}

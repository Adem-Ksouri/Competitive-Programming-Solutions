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


long double pow(long double g){
    return g * g ;
}
void solve(){
    long double a , b , c ; 
    cin >> a >> b >> c ; 
    long double n , m ;
    long double delta = pow(576 * b)  ;
    delta -= 4 * 576 * (144 * pow(a) + 144 * pow(b) - 576 * c - 144 * pow(a)) ; 
    if(delta < 0){
        cout << -1 << endl;
        return ;
    } 
    if(delta != 0) delta = sqrtl(delta) ;
    m = (576 * b + delta) / (2 * 576) ;
    long double deltae = pow(12 * a) - 4 * 12 * 
        (12 * pow(m) - 12 * b * m + 3 * pow(a) + 3 * pow(b) - 12 * c) ;
    assert(deltae >= 0) ;
    if(deltae != 0) deltae = sqrtl(deltae) ;  
    n = (12 * a + deltae) / (2 * 12) ;
    cout << n << " " << m << endl;
}

int main(){
    FAST
    cout << fixed << setprecision(9) ;
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}

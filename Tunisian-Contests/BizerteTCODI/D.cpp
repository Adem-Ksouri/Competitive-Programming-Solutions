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


char a[] = {'R' , 'S' , 'P'} ; 
char b[] = {'S' , 'P', 'R'} ;  

void solve(){
    ll n ;
    cin >> n ; 
    string s , t ;
    cin >> s >> t ; 
    int sz1 = s.size() , sz2 = t.size() ; 
    int l = lcm(sz1 , sz2) ; 
    string g1 = "" , g2 = "" ;
    int j = 0 ;  
    for(int i = 0 ; i < l ; i++){
        g1 += s[j++] ;
        j %= sz1 ; 
    }
    j = 0 ; 
    for(int i = 0 ; i < l ; i++){
        g2 += t[j++] ;
        j %= sz2 ; 
    }
    ll gg1 = 0 , gg2 = 0 ;
    for(int i = 0 ; i < l ; i++){
        bool ok1 = false , ok2 = false ; 
        for(int j = 0 ; j < 4 ; j++) {
            if(g1[i] == a[j] && g2[i] == b[j]) ok1 = true ;
            if(g1[i] == b[j] && g2[i] == a[j]) ok2 = true ;
        }
        if(ok1) gg1++ ;
        else if(ok2) gg2++ ; 
    }
    ll p = n / l ; 
    ll ans1 = gg1 * p ; 
    ll ans2 = gg2 * p ; 
    ll r = n % l ;
    for(int i = 0 ; i < r ; i++){
        bool ok1 = false , ok2 = false ; 
        for(int j = 0 ; j < 4 ; j++) {
            if(g1[i] == a[j] && g2[i] == b[j]) ok1 = true ;
            if(g1[i] == b[j] && g2[i] == a[j]) ok2 = true ;
        }
        if(ok1) ans1++ ;
        else if(ok2) ans2++ ;
    }
    cout << ans2 << " " << ans1 << endl;
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

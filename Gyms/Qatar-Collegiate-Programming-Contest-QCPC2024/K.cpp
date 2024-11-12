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
const ll sup = 2e9;
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

const int N = 35000 ; 
int spf[N] ;
ll prod[N] ;
vector<int> divisors[N] ;


void solve(){
    int d ; 
    cin >> d ; 
    if(d == 1){
        cout << 1 << endl;
        return ;
    }
    for(ll i = 1 ; i < N ; i++){
        if(prod[i] == d){
            cout << i << endl;
            return ;
        }
        if(!spf[i]){
            ll g = i ;
            g *= i ;
            g *= i ;
            if(g == d){
                cout << g / i << endl;
                return ;
            }
        }
    }
    bool pr = true ;
    for(ll i = 2 ; i < N ; i++)
        if(d % i == 0)
            pr = false ;
    if(pr){
        cout << d << endl;
        return ;
    }
    cout << -1 << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    for(int i = 1 ; i < N ; i++)
        for(int j = i ; j < N ; j += i)
            divisors[j].push_back(i) ;
    for(int i = 2 ; i < N ; i++) {
        if(spf[i]) continue ;
        for(int j = 2 * i ; j < N ; j += i)
            spf[j] = true ;
    }
    for(int i = 1 ; i < N ; i++){
        prod[i] = 1;
        for(int x : divisors[i]){
            if(prod[i] < sup / x){
                prod[i] *= x;
            }else {
                prod[i] = -1 ;
                break;
            }
        }
    }
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}

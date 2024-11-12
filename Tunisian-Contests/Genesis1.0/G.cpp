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
const ll mod = 998244353;
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
#define int ll

int dp[N_Max][20] ; 
int nb_primes ;
vector<int> primes,v ;
int prep[20];
int n , k ; 

int work  (int pos , int mask){
    if (pos > n && mask == ((1<<nb_primes)-1)) return 0 ;
    if ( pos> n) return 1e12 ;

    int & ret= dp[pos][mask] ;

    if (ret !=-1) return ret;

    ret = 1e18 ;

    for (int nw_mask = 0  ;nw_mask< (1<<nb_primes) ; nw_mask++ ){
        int nb = prep[nw_mask];

        int req = ((v[pos]+nb-1)/nb)*nb - v[pos];
        ret = min (ret, req + work(pos + 1, nw_mask | mask));
    }

    return ret;
}

void factorize_k(int k ){
    for (int i= 2; i*i <= k ; i++){
        if (k%i ) continue;

        primes.pb(i) ;
        k/= i ;
    }
    if (k>1) primes.pb(k);
    nb_primes = primes.size() ;
}

void solve (){
    cin >> n >> k ; 

    v.resize(n+1) ;
    for (int i=1; i<= n; i++)cin >> v[i];



    factorize_k(k) ;

    for (int nw_mask = 0  ;nw_mask< (1<<nb_primes) ; nw_mask++ ){
        prep[nw_mask]= 1 ;
        for (int j= 0; j < nb_primes ; j++){
            if (nw_mask & (1<<j))
                prep[nw_mask]*= primes[j];
        }
    }


    memset (dp,-1,sizeof(dp));

    cout << work(1,0) << endl;

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

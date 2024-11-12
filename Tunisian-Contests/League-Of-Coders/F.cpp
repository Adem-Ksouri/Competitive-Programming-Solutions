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

const int N = 1000010 ; 
const int B = 9973 ; 
map<ll,int> f ; 
vector<string> a(N) ;
int sz[N] ;
vector<ll> prefix[N] , prefix2[N] ; 

ll binpow(ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int bs(int i,int j){
	int sz = min((int)a[j].size(),(int)a[i].size()) ; 
	 
	int l=0 , r = sz-1 ;
	int res = 0 ; 
	while(l<=r){
		int mid = (l + r)/2 ;
		if(prefix[i][mid]==prefix[j][mid]){
			res = mid ;
			l = mid + 1 ;
		}else {
			r = mid - 1 ; 
		}
	} 
	return res ; 
}
void solve(){
	int n , q ; 
	cin >> n >> q ; 
	for(int i=1 ; i<=n ; i++) {
		cin >> a[i] ;
		sz[i] = (int)a[i].length() ;
		a[i] = "#" + a[i] ; 
		prefix[i].resize(sz[i]+1) ;
		prefix2[i].resize(sz[i]+1) ; 
		for(int j=1 ; j<=sz[i] ; j++){
			prefix[i][j] = (prefix[i][j-1] + binpow(B,j) * 1ll * a[i][j]%mod)%mod ; 
		}
		f[prefix[i][sz[i]]]++  ;
	}	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=sz[i] ; j++){
			prefix2[i][j] = (prefix2[i][j-1] + f[prefix[i][j]]) ; 
		}
	}
	while(q--){
		int i , j ; 
		cin >> i >> j ; 
		int res = bs(i,j) ;
		cout << prefix2[i][res] << endl ;  
	}
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

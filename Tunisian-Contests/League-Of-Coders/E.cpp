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

const int N = 1e6+5 ; 

vector <int> divisors[N];
vector<int> stock[N] ;
int vis[N] ;

void solve(){
	int n ; 
	cin >> n;
	vector <int> v(n) ; 
	vector <int> vp ;
	for (int i= 2 ;i<N ; i++){
		for (int j= i ; j<N ; j+=i )
			divisors[j].pb(i) ;
	}
	for (int i= 0 ; i<n ;i++){
		cin >> v[i];
		for (auto d : divisors[v[i]]){
			stock[d].pb(i) ; 
		}
	}
	
	for(int i=N-1 ; i>=2 ; i--){
		vector<int> d ;
		for(int x : stock[i]) {
			if(!vis[x]) d.pb(x) ; 
		}	
		for(int j=0 ; j+1<(int)d.size() ; j+=2){
			int l = d[j] , r = d[j+1] ; 
			vis[l] = vis[r] = true ; 
		}
	}
	vector<int> ans ; 	
	for(int i=0 ; i<n ; i++){
		if(!vis[i]) ans.pb(v[i]) ;
	}
	cout << ans.size() << endl ; 
	for(int x : ans) cout  << x << " " ;
	cout << endl ; 
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

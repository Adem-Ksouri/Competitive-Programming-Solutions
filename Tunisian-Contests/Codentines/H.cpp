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

const int N = 1100 ;
const int M = 1000010 ;  
const ll B1 = 9973 ;
const ll B2 = 1e9 + 3 ; 
string a[N] ; 
ll h1[N] , h2[N] ;
ll b1[M] , b2[M] ;
int occ[N] , gg[N][N] ;  
map<pair<ll,ll>,vector<pair<int,int>>> f ; 


void solve(){
	int n ;
	cin >> n ;
	b1[0] = b2[0] = 1 ;
	for(int i = 1 ; i < M ; i++) {
		b1[i] = b1[i - 1] * B1 % mod ; 
		b2[i] = b2[i - 1] * B2 % mod ;
	} 

	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;

	for(int i = 1 ; i <= n ; i++){
		h1[i] = 0 , h2[i] = 0 ; 
		for(int j = 0 ; j < (int)a[i].size() ; j++) {
			h1[i] = (h1[i] + b1[j] * a[i][j] % mod) % mod ; 
			h2[i] = (h2[i] + b2[j] * a[i][j] % mod) % mod ; 	
		}	
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ;j++){
			if(i == j) continue ; 
			int sz = a[i].size() ;
			ll hash1 = (h1[i] + h1[j] * b1[sz] % mod) % mod ; 
			ll hash2 = (h2[i] + h2[j] * b2[sz] % mod) % mod ;
			f[{hash1 , hash2}].push_back({i , j}) ; 
		}
	}
	for(auto g : f){
		vector<pair<int,int>> v = g.S ; 
		for(auto pi : v){
			occ[pi.F]++ ;
			occ[pi.S]++ ;
			gg[pi.F][pi.S]++ ;
		}
		int sz = (int)v.size() ; 
		int x = -1 , y = -1 ; 
		for(auto pi : v){
			if(sz - occ[pi.F] - occ[pi.S] + gg[pi.F][pi.S] + gg[pi.S][pi.F] > 0){
				x = pi.F , y = pi.S ; 
				break ; 
			}
		}
		if(x != -1){
			for(auto pi : v){
				if(pi.F != x && pi.S!=x && pi.F!=y && pi.S!=y){
					cout << "YES" << endl ;
					cout << x << " " << y << " " << pi.F << " "<< pi.S << endl;
					return ;
				}
 			}
		}
		for(auto pi : v){
			occ[pi.F]-- ;
			occ[pi.S]-- ;
			gg[pi.F][pi.S]-- ;
		}
	}
	cout << "NO" << endl;
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

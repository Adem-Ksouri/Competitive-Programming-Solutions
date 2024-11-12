#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define ld double
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define affichea(a,n) for(ll i=0 ; i<n ; i++) cout << a[i] <<" " ;
#define yes cout << "Yes" << endl;
#define no cout<<"No"<<endl;
#define F first
#define S second
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define double long double
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 100010 ;
const int M = 201 ; 
vector<int> a[N] ; 
vector<vector<ll>> dp[N]; 
ll s[N][M] ; 
int id[N] ; 
int szz[N] ; 
int n , m ;

void dfs1(int node , int par){
    s[node][1] = 1 ;
    szz[node] = 1 ; 
    int cnt = 0 ; 
    for(int j : a[node]){
        if(j!=par) {
            id[j] = cnt++ ; 
            dfs1(j,node) ;
            dp[node][id[j]][2] += szz[j] *1ll* szz[j] ; 
            s[node][2] += dp[node][id[j]][2] ;

            for(int k=3 ; k<=m ; k++){
                dp[node][id[j]][k] += s[j][k-1] ; 
                s[node][k] += dp[node][id[j]][k] ;
            }


            szz[node]+=szz[j] ; 
        }
    }
}

void dfs2(int node,int par){
    if(node!=1){
        s[node][2] += (n - szz[node])*1ll*(n-szz[node]) ;  
        for(int k=3 ; k<=m ; k++){
            s[node][k] += s[par][k-1] - dp[par][id[node]][k-1] ; 
        }
    }
    for(int j : a[node]){
        if(j!=par) dfs2(j,node) ; 
    }
}

void solve(){
    cin >> n >> m  ; 
    for(int i=1 ; i<n ; i++) {
        int x , y ; 
        cin >> x >> y ; 
        a[x].pb(y) ; 
        a[y].pb(x) ; 
    }
    
    if(m==1){
        ll ans = 1 ; 
        ans*= n ; 
        ans*=n ;
        ans*=n ;  
        cout << ans  << endl ; 
        return ; 
    }
    
   for(int i=1 ; i<=n ; i++){
        int sz = (int)a[i].size() ;
        if(i!=1) sz-- ;   
        if(sz>0) dp[i] = vector<vector<ll>> (sz,vector<ll>(m+1,0)) ;    
    }
    
    dfs1(1,0) ; 

    dfs2(1,0) ;

    
    ll ans = 0 ; 
    

    for(int i=1 ; i<=n ; i++){
        ans += s[i][m] ;
    }
    cout << ans << endl ; 
}

int main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  


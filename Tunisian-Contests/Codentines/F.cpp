#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
#define ll long long
#define endl "\n"    
#define fast ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 110 ; 
char a[N][N] ;
int dp[N][N][(1 << 7)] ;
vector<array<int,3>> cost[N] ;
vector<array<int,2>> color[7] ;  
int n , m , c , k ;

int dist(int x , int y , int i , int j){
    return abs(x - i) + abs(y - j) ; 
}
int work(int i , int j , int mask){
    if(mask == (1 << c) - 1) return dist(i , j , n , m) ; 
    int &ret = dp[i][j][mask] ; 
    if(ret != -1) return ret ; 
    ret = 2e9 ;
    for(int col = 0 ; col < c ; col++){
        if((1 << col) & mask) continue ; 
        for(auto g : color[col]) {
            ret = min(ret , dist(i , j , g[0] , g[1]) + 
                                                work(g[0] , g[1] , (mask | (1 << col)))) ; 
        }
        for(auto g : cost[col]) {
            if((1 << g[0]) & mask && (1 << g[1]) & mask) 
                ret = min(ret , g[2] + work(i , j , (mask | (1 << col)))) ; 
        }
    }
    return ret ; 
}
void solve(){
    cin >> n >> m >> c >> k ;
    memset(dp , -1 , sizeof(dp)) ; 

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++){ 
            cin >> a[i][j] ; 
            if(a[i][j] > '0') color[a[i][j] - '0' - 1].push_back({i , j}) ; 
        }
    for(int i = 1 ; i <= k ; i++){
        int c1 , c2 , c3 , t ; 
        cin >> c1 >> c2 >> c3 >> t ;
        --c1 , --c2 , --c3 ;
        cost[c3].push_back({c1 , c2 , t}) ; 
    }   
    int ans = work(1 , 1 , 0) ;
    if(ans < 2e9) cout << ans << endl;
    else cout << -1 << endl;
}

int main(){
    fast 
    
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif

    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  

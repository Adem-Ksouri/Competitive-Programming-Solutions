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

int add(int a , int b){
    a %= mod ; 
    b %= mod ;
    return (a + b) % mod ;
}
int mult(int a , int b){
    a %= mod ; 
    b %= mod ; 
    return a * 1ll * b % mod ;
}
int sub(int a , int b){
    a %= mod ; 
    b %= mod ;
    return (a - b + mod) % mod ; 
}
int divide(int a , int b){
    a %= mod ;
    b %= mod ;
    return (a + mod - b) % mod ;
}
//hash_pair
 
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        if (hash1 != hash2) return hash1 ^ hash2;
        return hash1;
    }
};

const int B = 61 ;
const int N = 210 ; 
int cnt[B][N] ;
int ways[B][N][N] ; 
int dp[B][N][N] ;
int tmp[N][N] ;
int old_dp[N][N] ;
int memo[B][N] ;
ll n ;
int m ;

int work(int i , int rest){
    ll p = n ;
    for(int j = 60 ; j > i ; j--)
        if((1ll << j) & p)
            p ^= (1ll << j) ;
    if(rest > p) return 0;
    if(p < 128) 
        return old_dp[rest][p] ;
    int &ret = memo[i][rest];
    if(ret != -1) return ret ;
    ret = 0;
    if(!((1ll << i) & p)) {
        return 
            ret = work(i - 1 , rest) ;
    }
    for(int x = 1 ; x <= 100 ; x++){
        for(int y = 0 ; y <= 100 ; y++){
            ret = add(ret , mult(mult(dp[i][rest][x] , ways[i][x][y]) , 
                                work(i - 1 , y))) ; 
        }
    }
    return ret;
}

void solve(){
    cin >> n >> m;
    memset(memo , -1 , sizeof(memo)) ;
    vector<pair<int,int>> op ; 
    for(int i = 0 ; i < m ; i++) {
        int a , b ; 
        cin >> a >> b ; 
        op.push_back({b , a}) ;
        cnt[b][a]++ ; 
    }
    for(int b = 1 ; b <= 60 ; b++)
        for(int a = 1 ; a < N ; a++)
            cnt[b][a] += cnt[b - 1][a] ;
    for(int b = 7 ; b <= 60 ; b++){
        ll cur = (1ll << b) ; 
        for(ll x = 1 ; x <= 100 ; x++)
            for(ll y = 0 ; y <= 100 ; y++) {
                ll diff = y + x ;
                if(diff > 100) continue ;
                int new_b = __builtin_ctzll(cur + y) ; 
                ways[b][x][y] = cnt[new_b][diff] ; 
            }
    }
    for(int x = 0 ; x < 128 ; x++){
        old_dp[x][x] = 1 ;
        for(int y = x + 1 ; y < 128 ; y++){
            for(int lst = 1 ; lst < 128 ; lst++){
                int b = __builtin_ctz(y) ; 
                if(y - lst >= x)
                    old_dp[x][y] = add(old_dp[x][y] , mult(old_dp[x][y - lst] , cnt[b][lst])) ; 
            }
        }
    }
    for(int x = 0 ; x < 128 ; x++){
        for(int y = 1 ; y < 128 ; y++){
            dp[7][x][y] = old_dp[x][128 - y] ;
        }
    }

    for(int b = 8 ; b <= 60 ; b++){
        memset(tmp, 0 , sizeof(tmp)) ; 
        for(int x1 = 1 ; x1 <= 100 ; x1++){
            for(int y1 = 0 ; y1 <= 100 ; y1++){
                for(int y = 1 ; y <= 100 ; y++){
                    tmp[x1][y] = add(tmp[x1][y] , mult(ways[b - 1][x1][y1] , dp[b - 1][y1][y])) ; 
                }
            }
        }
        for(int x = 0 ; x <= 100 ; x++){
            for(int x1 = 1 ; x1 <= 100 ; x1++){
                for(int y = 1 ; y <= 100 ; y++){
                    dp[b][x][y] = add(dp[b][x][y] , mult(dp[b - 1][x][x1] , tmp[x1][y])) ; 
                }
            }
        }
    }
    // vector<int> g(n + 4);
    // g[0] = 1 ;
    // for(int i = 1 ; i <= n ; i++) {
    //     for(auto [b , a] : op) {
    //         if(i % (1ll << b) == 0 && i - a >= 0)
    //             g[i] = add(g[i] , g[i - a]) ;
    //     }
    // }
    ll ans = work(60 , 0) ; 
    cout << ans << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

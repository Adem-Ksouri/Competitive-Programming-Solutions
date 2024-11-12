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
    return (a + b) % mod ;
}
int mult(int a , int b){
    return a * 1ll * b % mod ;
}
int sub(int a , int b){
    return (a + mod - b) % mod ;
}
int divide(int a , int b){
    return mult(a , inv(b)) ; 
}


const int N = 110 ; 
int f[N] ;

int C(int n , int k){
    if(k > n) return 0 ;
    return divide(f[n] , mult(f[k] , f[n - k])) ;
}


struct Matrix {
    ll a[N][N];
    Matrix(){
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                a[i][j] = 0;
    }
    Matrix operator * (Matrix other){
        Matrix product ; 
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < N ; j++)
                for(int k = 0 ; k < N ; k++)
                    product.a[i][j] = add(product.a[i][j] , mult(a[i][k] , other.a[k][j])) ; 
        return product ;  
    }
};

Matrix expo_power(Matrix a , ll k){
    Matrix ret ;
    for(int i = 0 ; i < N ; i++) 
        ret.a[i][i] = 1;
    while(k){
        if(k & 1)
            ret = ret * a ;
        a = a * a ;
        k >>= 1 ;
    }
    return ret ;
}
void print(Matrix M){
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 4 ; j++)
            cout << M.a[i][j] << " ";
        cout << endl;
    }
}
void solve(){
    ll m , k ; 
    cin >> m >> k ;
    if(k == 0){
        cout << 0 << endl;
        return ;
    }
    if(k == 1){
        cout << m << endl;
        return ;
    }
    Matrix M ;
    for(int i = 0 ; i <= m ; i++){
        for(int j = 0 ; j <= i ; j++)
            M.a[i][j] = mult(m , C(i , j)) ;  
    }
    for(int i = 0 ; i <= m ; i++)
        M.a[m + 1][i] = mult(m , C(m , i)) ; 
    M.a[m + 1][m + 1] = 1;
    M = expo_power(M , k - 1) ;
    int ans = 0 ;
    for(int i = 0 ; i <= m + 1 ; i++)
        ans = add(ans , mult(M.a[m + 1][i] , m)) ; 
    cout << ans << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    f[0] = 1;
    for(int i = 1 ; i < N ; i++)
        f[i] = mult(f[i - 1] , i) ;

    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

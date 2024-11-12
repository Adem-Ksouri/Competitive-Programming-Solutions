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
ll inv(ll N , int m = mod) {if (N == 1) return 1; return (m - ((m / N) * inv(m % N)) % m) % m;}

int add(int a , int b , int m = mod){
    return ( a + 0ll + b ) % m ; 
}
int mult(int a , int b , int m = mod){
    return a * 1ll * b % m ;
}
int sub(int a , int b , int m = mod){
    return (a - 0ll - b + m ) % m ;
}
int divide(int a , int b , int m = mod){
    return a * 1ll * inv(b , m) % m ; 
}
//matrix_expo
 
const int N_mat=55;
 
struct Matrix {
    int a[N_mat][N_mat] ;
    Matrix(){
        for (int i= 0; i<N_mat; i++)
            for (int j= 0; j<N_mat; j++)
                a[i][j]= 0 ;
    }
    Matrix operator * ( Matrix  other) {
        Matrix product ;
        for (int i= 0 ;i<N_mat ; i++)
            for (int j = 0 ; j<N_mat ; j++)
                for (int k = 0 ; k<N_mat ; k++){
                    product.a[i][j] = add(product.a[i][j] , mult(a[i][k] , 
                                                other.a[k][j], mod - 1) , mod - 1) ;
                }
        return product ;
    }
};
 
void print(Matrix s ){
    for (int i= 0 ;i<N_mat ; i++){
        for (int j = 0 ; j<N_mat ; j++)
            cout << s.a[i][j] << " ";
        cout <<endl;
    }cout <<endl;
}
 
Matrix expo_power(Matrix a, long long k){
    Matrix ret ;
    for (int i=0 ; i<N_mat ; i++) ret.a[i][i] = 1 ; //identity
    while (k){
        if (k % 2)
            ret = ret * a;
        a = a*a ;
        k/=2 ;
    }
    return ret ;
}
long long binpow(long long a, long long b, long long m = mod) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve(){
    int n ; 
    cin >> n ;
    ll  k ; 
    cin >> k ;
    vector<int> f(n) ;
    for(int i = 0 ; i < n ; i++) cin >> f[i] ; 
    if(k <= n){
        --k ; 
        cout << f[k] << endl;
        return ;
    }
    Matrix M ; 
    for(int i = 0 ; i + 1 < n ; i++)
        M.a[i][i + 1] = 1 ;
    for(int i = 0 ; i < n ; i++)
        M.a[n - 1][i] = f[n - 1 - i] ;
    M = expo_power(M , k - n) ;
    int ret = 1 ;
    for(int i = 0 ; i < n ; i++){
        int ans = M.a[n - 1][i] ; 
        ret = mult(ret , binpow(f[i] , ans)) ; 
    } 
    cout << ret << endl;
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

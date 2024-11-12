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
const ll mod = (ll)1e9;
const int N_Max = 3e5 + 7;
const int Nax = 1e6 + 5;
const int LOG = 20;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

int add(int a , int b){
    return ( a + 0ll + b ) % mod ; 
}
int mult(int a , int b){
    return a * 1ll * b % mod ;
}
int sub(int a , int b){
    return (a - 0ll - b + mod ) % mod ;
}

const int N = 400100 ; 
int a[N] ;
ll s[4 * N][2] ;
ll lazy[4 * N] ;
int fib[N] ; 
int f[N] ;
int n , m ;

int shift(int s0 , int s1 , int x){
    if(x == 0) return s0 ;
    if(x == 1) return s1 ;
    return 
        add(mult(s0 , fib[x - 2]) , mult(s1 , fib[x - 1])) ; 
}
void work(int id , int x , int sz){
    s[id][0] = add(s[id][0] , mult(f[sz - 1] , x)) ; 
    s[id][1] = add(s[id][1] , mult(sub(f[sz] , f[0]) , x)) ; 
}
void push(int id , int tl ,int tr){
    int mid = (tl + tr) / 2 ;
    int sz1 = mid - tl + 1;
    int sz2 = tr - mid ;
    work(2 * id , lazy[id] , sz1) ; 
    work(2 * id + 1 , lazy[id] , sz2) ;
    lazy[2 * id] = add(lazy[2 * id] , lazy[id]) ;
    lazy[2 * id + 1] = add(lazy[2 * id + 1] , lazy[id]) ;
    lazy[id] = 0; 
}

void merge(int id , int sz){
    s[id][0] = s[2 * id][0] ;
    s[id][0] = add(s[id][0] , shift(s[2 * id + 1][0] , s[2 * id + 1][1] , sz)) ;
    
    s[id][1] = s[2 * id][1] ;
    s[id][1] = add(s[id][1] , shift(s[2 * id + 1][0] , s[2 * id + 1][1] , sz + 1)) ;
}

void build(int id , int l , int r){
    if(l == r){
        for(int i = 0 ; i < 2 ; i++)
            s[id][i] = mult(fib[i] , a[l]) ;
    }
    else {
        int mid = (l + r) / 2;
        build(2 * id , l , mid) ;
        build(2 * id + 1, mid + 1 ,r) ;
        merge(id , mid - l + 1) ;
    }
}   

void update_pos(int id ,int l , int r , int pos){
    if(l == r){
        for(int i = 0 ; i < 2 ; i++){
            s[id][i] = mult(fib[i] , a[pos]) ;
        }
    }else {
        int mid = (l + r) / 2 ;
        push(id , l , r) ;
        if(mid >= pos){
            update_pos(2 * id , l , mid , pos) ;
        }else{
            update_pos(2 * id + 1 , mid + 1 , r , pos) ;
        }
        merge(id , mid - l + 1) ;
    }
}

void update(int id , int tl , int tr , int l , int r , int x){
    if(tl > r || tr < l) return ;
    if(tl >= l && tr <= r){
        int sz = tr - tl + 1;
        work(id , x , sz) ;
        lazy[id] = add(lazy[id] , x) ;
        return ;
    }
    int mid = (tl + tr) / 2 ;
    push(id , tl , tr);
    update(2 * id , tl , mid , l , r , x) ;
    update(2 * id + 1, mid + 1 , tr , l , r , x) ;
    merge(id , mid - tl + 1) ;
}
int query(int id , int tl , int tr , int l , int r){
    if(tl > r || tr < l) return 0 ;
    if(tl >= l && tr <= r)
        return shift(s[id][0] , s[id][1] , tl - l) ;
    push(id , tl , tr) ; 
    int mid = (tl + tr) / 2 ;
    return add(query(2 * id , tl , mid , l , r) , 
                    query(2 * id + 1, mid + 1 ,tr , l , r));
}

void solve(){
    int n , m ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ; 

    build(1 , 1 , n) ;
    
    while(m--){
        int t ; 
        cin >> t ;
        if(t == 1){
            int x , v ; 
            cin >> x >> v ;
            a[x] = v ;
            update_pos(1 , 1 , n , x) ;
        }else if(t == 2){
            int l , r ; 
            cin >> l >> r;
            cout << query(1 , 1 , n , l , r) << endl;
        }else {
            int l , r , d ; 
            cin >> l >> r >> d ;
            update(1 , 1 , n , l , r , d) ;
        }
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
    fib[0] = fib[1] = 1;
    for(int i = 2 ; i < N ; i++)
        fib[i] = add(fib[i - 1] , fib[i - 2]) ; 
    f[0] = 1 ; 
    for(int i = 1 ; i < N ; i++) f[i] = add(f[i - 1] , fib[i]);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

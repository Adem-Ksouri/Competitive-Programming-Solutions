#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#ifndef ONLINE_JUDGE
#include "dbg.cpp"
#else
#define dbg(...)
#endif
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
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 1010 ; 
const double pi = 3.1415926 ; 
vector<array<int,2>> a(N) ; 

void solve(){
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++) {
        int x , r ; 
        cin >> x >> r ; 
        a[i] = {x,r} ; 
    }
    sort(a.begin() + 1 , a.begin() + n + 1) ;
    long double tot = 0 ;
    for(int i = 1 ; i <= n ; i++)
        tot += pi * a[i][1] * a[i][1] ;  
    long double minus = 0 ;
    for(int i = 1 ; i < n ; i++){
        long double xi1 = a[i][0] , r1 = a[i][1] , xi2 = a[i+1][0] , r2 = a[i+1][1] ; 
        
        if(xi2 - xi1 < r1 + r2 ){
            long double x = (long double)(xi2 * xi2 - xi1 * xi1 + 
                                            r1 * r1 - r2 * r2) / (2 * xi2 - 2 * xi1)   ; 
            long double y = sqrt(r1 * r1 - (x - xi1) * (x - xi1)) ; 
            long double d = sqrt( r1 * r1 - y * y ) ; 
            
            long double area = d * abs(2 * y) / 2 ;
            long double gg = asin(abs(y)/r1) ;
            gg = ( 180 * gg ) / pi ; 
            gg *= 2 ;   
            long double sec = pi * r1 * r1 * (gg / 360) ; 
            minus += sec - area ;  
            
            d = abs(xi2 - xi1) - d ; 
            area = d * abs( 2 * y) / 2;
            gg = asin(abs(y) / r2) ; 
            gg = ( 180 * gg ) / pi ; 
            gg *= 2 ;   
            sec = pi * r2 * r2 * (gg / 360) ; 
            minus += sec - area ; 
        }
    }
 
    cout << tot - minus << endl ; 
}

int main(){
    fast 
    ll t = 1 ; 
    cout << fixed << setprecision(6) ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  

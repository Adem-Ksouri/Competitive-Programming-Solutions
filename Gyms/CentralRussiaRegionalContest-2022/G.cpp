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
#define int ll
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9+7 ;
const ll inf = 1e18+500 ;
 
using namespace std ;
using namespace __gnu_pbds;
 
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;} 

const int N = 100100 ; 
vector<array<int , 2>> a ; 


int h(int x){
    return 3600 * x; 
}
int m (int x){
    return x * 60 ;
}
int s(int x){
    return x ; 
}

void solve(){
    int n ; 
    cin >> n ; 
    ll ans = 0 ; 
    bool ok = false;  

    for(int i = 1 ; i <= n ; i++) {
        char c ;
        int x1 , y1 , z1 , x2 , y2 , z2 ; 
        cin >> x1 >> c >> y1 >> c >> z1 >> x2 >> c >> y2 >> c >> z2 ;
        

        int l = h(x1) + m(y1) + s(z1) ; 
        int r = h(x2) + m(y2) + s(z2) ; 

        if(l > r){
            r = h(23) + m(59) + s(59) ;
            int l1 = 0 ; 
            int r1 = h(x2) + m(y2) + s(z2) ; 
            ok = true ; 
            a.pb({l,r}) ; 
            a.pb({l1,r1}) ; 
        } else{
            a.pb({l,r}) ;
        }
    }

    int sz = (int)a.size() ; 
    
    sort(a.begin() , a.end()) ;


    if(ok) ans++ ; 

    for(int i = 0 ; i < sz ; i++){
        int j = i + 1 ;
        int lst = a[i][1] ; 
        while(j < sz && a[j][0] <= lst){
            lst = max(lst , a[j][1]) ;  
            j++ ; 
        }
        ans += max(0ll , lst - a[i][0]); 
        i = j - 1 ;
    }
    cout << max(0ll , 24 * 3600 - ans)  << endl ; 
}

int32_t main(){
    fast 
    ll t = 1 ; 
    // cin >> t  ; 
    while(t--) solve() ;
    return 0;
}  

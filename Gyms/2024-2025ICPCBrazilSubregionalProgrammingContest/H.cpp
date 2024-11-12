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

const int N = 550 ; 
int p[N] ; 
string s , t ;
vector<string> a , b;
bool check(string &s , string &m){
    int mask1 = 0 , mask2 = 0 ;
    reverse(m.begin() , m.end()) ; 
    for(int i = 0 ; i < m.size() ; i++){
        if(m[i] == '1')
            mask2 |= (1 << i) ; 
    }
    p[0] = 1;
    for(int i = 1 ; i < s.size() ; i++) p[i] = p[i - 1] *1ll* 2 % mask2 ;  
    int i = 0 ;
    int sum = 0 ;
    while(i < s.size()){
        if(s[i] == '1') 
            sum = (sum + p[(int)s.size() - 1 - i]) % mask2 ; 
        i++ ; 
    }
    return sum == 0 ; 
}


void work(string &s , vector<string> &a , int i){
    if(i >= s.size()) {
        a.push_back(s) ;
        return ;
    }
    if(s[i] == '*'){
        s[i] = '0' ;
        work(s , a , i + 1) ;
        s[i] = '1' ; 
        work(s , a , i + 1) ;
        s[i] = '*' ;
    }else {
        work(s , a , i + 1) ; 
    }
}
void rect(vector<string> &a){
    for(int i = 0 ; i < a.size() ; i++){
        reverse(a[i].begin() , a[i].end()) ;
        while(!a[i].empty() && a[i].back() == '0') a[i].pop_back() ;
        reverse(a[i].begin() , a[i].end()) ;
    }
}
void solve(){
    cin >> s >> t ;
    work(s , a , 0) ;
    work(t , b , 0) ;
    rect(b) ;
    for(auto s1 : a){
        for(auto s2 : b){
            if(check(s1 , s2)) {
                cout << s1 << endl;
                return ;
            }
        }
    }
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

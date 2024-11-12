/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int __int128
#define endl '\n'

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

void Solve() {
    ll n , l ,cnt=0;
    cin >> n >> l ;
    set <int> s ;
    vector<int> v;
    for (ll i= 1 , x ; i<=n ;i++){
        cin >> x;
        s.insert(x);
    }
    for (auto x :s) v.pb(x);
    n = v.size() ;
    vector<set<int>> ans(n);
    set<int> ss;
    for (int i= 0; i<n ; i++){
        int prod = 0;
        while(true){
            prod = prod+v[i]+(v[i]*prod);
            assert(prod>=0);
            if (prod>l||prod<0)break;
            ss.insert(prod);
            ans[i].insert(prod);
            for (int k = 0 ; k<i; k++){
                for (auto x: ans[k]){
                    int nw = x + prod + prod*x;
                    assert(nw>=0);
                    if (nw>l||nw<0) break;
                    ss.insert(nw);
                    ans[i].insert(nw);
                }
            }
        }
    }
    cout << ss.size()<<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);ll Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}

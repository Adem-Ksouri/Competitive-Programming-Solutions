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
#define int ll
#define endl '\n'

const int N=1e6,mod=1e9+7,MOD=mod,INF=1e18+10;


double getdistance (double x,double y ,double r){
    return sqrt(x*x+y*y)-r;
}

double getpower (double x){
    return sqrt(N/x);
}

void Solve() {
    int n,k,lst=0;
    cin >> n ;
    vector<array<double,3>> v ;
    vector<array<double,5>> s ;
    vector<pair<int,int>> ans ;

    for (int i= 1 ;i<=n ;i++){
        double x;
        cin >> x;
        v.pb({getpower(x),x,double(i)});
    }

    cin >> k ;


    for (int i= 1 ; i<=k ; i++){
       double x,y,r;
       cin >> x >> y>> r ;
       s.pb({getdistance(x,y,r),x,y,r,double(i)});
    }

    sort (all(v));
    sort (all(s));
    for (int i= 0; i<k ;i++){
        while(lst <n && s[i][0]>v[lst][0])lst++;
        if (lst<n) {
            ans.pb({v[lst][2],s[i][4]});
            lst++;
        }
    }

    sort (all(ans));
    cout << ans.size()<<endl;
    for (auto [l,r]: ans )cout << l << " " << r << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}

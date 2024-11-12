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

const int N=3e5+30,mod=1e9+7,MOD=mod,INF=1e18+10;

void Solve() {
    int n1,n2,m1,m2;
    cin>>n1>>n2>>m1>>m2;

    set<string>s1,s2;
    while(n1--){string x;cin >> x; s1.insert(x);}
    while(n2--){
        string x;cin >> x;
        if (s1.find(x)!=s1.end())
            s2.insert(x);
    }
    while(m1--){
        string x;cin >> x;
        if (s2.find(x)!=s2.end())s2.erase(x);
    }
    while(m2--){
        string x;cin >> x;
        if (s2.find(x)!=s2.end())s2.erase(x);
    }
    for (auto x: s2)cout<<x<<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}

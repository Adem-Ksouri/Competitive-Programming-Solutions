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

int ask (int x){
    cout << "get "<< x << endl;
    cout.flush();
    int curr ;
    cin >> curr;
    return curr;
}

vector<set<int>> mp(3);
vector<int> v;
void swapp (int i, int j){
    cout << "swap " << i+1 << " "<< j+1 <<endl;
    mp[v[i]].erase(i);
    mp[v[j]].erase(j);
    mp[v[i]].insert(j);
    mp[v[j]].insert(i);
    swap(v[i],v[j]);
}

void Solve() {
    int n ;
    cin >> n;
    for (int i= 0;i<n ;i++)v.pb(ask(i+1));


    for (int i= 0;i<n; i++) mp[v[i]].insert(i);

    for (int i=0 ; i<n;i++){
        if (v[i]==0) continue;
        auto it = mp[0].upper_bound(i);
        if (it!=mp[0].end()){swapp(i,*it);continue;}
        if (v[i]==1)continue;
        it = mp[1].upper_bound(i);
        if (it!=mp[1].end()){swapp(i,*it);continue;}
    }

    cout << "Sorted!"<<endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);int Test_case=1;
//    cin >> Test_case;
    while (Test_case--) Solve();
}

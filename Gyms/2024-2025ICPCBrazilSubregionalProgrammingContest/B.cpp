#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include "debug.cpp"
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
const int N_Max = 1e6 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

vector<int> movie[105], actor[N_Max];
int bridge[105][105], nxt[105];
int good[105], can[105];
int N, M, Q;

int work(int i){
    if (good[i]) return can[i] = 1;
    int &ret = can[i];
    if (ret != -1) return ret;
    ret = 0;
    for (int j = 1; j <= N; j++){
        if (bridge[i][j] == -1) continue;
        if (work(j)){
            ret = 1;
            nxt[i] = j;
            break;
        }
    }
    return ret;
}

void solve(){
    cin >> N >> M;
    memset(bridge, -1, sizeof(bridge));
    for (int i = 1; i <= N; i++){
        int x;
        cin >> x;
        for (int j = 0; j < x; j++){
            int v;
            cin >> v;
            movie[i].pb(v);
            actor[v].pb(i);
        }
    }
    for (int i = 1; i <= N; i++)
        for (int u : movie[i])
            for (int v : actor[u])
                bridge[i][v] = u;
    cin >> Q;
    for (int q = 1; q <= Q; q++){
        int u, v;
        cin >> u >> v;
        for (int i = 1; i <= N; i++){
            can[i] = nxt[i] = -1;
            good[i] = 0;
        }
        for (int x : actor[v]) good[x] = 1;
        vector<int> vec;
        int sz = 0;
        for (int x : actor[u]){
            if (work(x)){
                sz++;
                vec.pb(u);
                vec.pb(x);
                break;
            }
        }
        if (vec.empty()){
            cout << -1 << endl;
            continue;
        }
        int curr = vec.back();
        while (!good[curr]){
            assert(can[curr]);
            sz++;
            vec.pb(bridge[curr][nxt[curr]]);
            vec.pb(nxt[curr]);
            curr = nxt[curr];
            assert(curr != -1);
        }
        sz++;
        vec.pb(v);
        cout << sz << endl;
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

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
const int N_Max = 3e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

vector<int> adj[N_Max];
int nxt[60 * N_Max][2];
int sub[60 * N_Max][2];
ll latency[N_Max];
ll power[N_Max];
int cnt = 1;
int N, Q;

void add(ll x){
    int curr = 1;
    for (ll bit = 59; bit >= 0; bit--){
        int c = (x >> bit) & 1LL;
        if (nxt[curr][c] == -1) nxt[curr][c] = ++cnt;
        sub[curr][c]++;
        curr = nxt[curr][c];
    }
}

void rmv(ll x){
    int curr = 1;
    for (ll bit = 59; bit >= 0; bit--){
        int c = (x >> bit) & 1LL;
        if (nxt[curr][c] == -1) nxt[curr][c] = ++cnt;
        sub[curr][c]--;
        curr = nxt[curr][c];
    }
}

ll query(ll x){
    ll ret = 0;
    int curr = 1;
    for (ll bit = 59; bit >= 0; bit--){
        if (curr == -1) break;
        int c = (x >> bit) & 1LL;
        if (!sub[curr][c]){
            ret += (1LL << bit);
            curr = nxt[curr][c ^ 1]; 
        }
        else curr = nxt[curr][c];
    }
    return ret;
}

void dfs(int Node){
    power[Node] = query(latency[Node]);
    add(latency[Node]);
    for (int child : adj[Node]){
        dfs(child);
        power[Node] = min(power[Node], power[child]);
    }
    rmv(latency[Node]);
}

void solve(){
    cin >> N;
    memset(nxt, -1, sizeof(nxt));
    for (int i = 2; i <= N; i++){
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    for (int i = 1; i <= N; i++) cin >> latency[i];
    dfs(1);
    cin >> Q;
    for (int i = 1; i <= Q; i++){
        int u;
        cin >> u;
        cout << power[u] << endl;
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

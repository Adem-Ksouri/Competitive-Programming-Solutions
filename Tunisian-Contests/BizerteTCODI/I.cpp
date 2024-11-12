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
const int N_Max = 3005;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

vector<pair<int, int>> adj[N_Max];
vector<pair<int, int>> edges;
int vis[N_Max], dp[N_Max];
int N, res;

void dfs_init(int Node, int par){
    vis[Node]++;
    for (auto [child, x] : adj[Node])
        if (child != par) dfs_init(child, Node);
}

void dfs1(int Node, int par){
    dp[Node] = 0;
    for (auto [child, x] : adj[Node]){
        if (child == par || !vis[child]) continue;
        dfs1(child, Node);
        dp[Node] += dp[child] + (x == -1);
    }
}

void dfs2(int Node, int par){
    res = min(res, dp[Node]);
    for (auto [child, x] : adj[Node]){
        if (child == par || !vis[child]) continue;
        dp[child] = dp[Node];
        if (x == 1) dp[child]++;
        else dp[child]--;
        dfs2(child, Node);
    }
}

void solve(){
    cin >> N;
    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back({v, 1});
        adj[v].push_back({u, -1});
    }
    if (N == 1){
        cout << 0 << endl;
        return;
    }
    int ans = 2e9;
    for (auto [u, v] : edges){
        for (int i = 1; i <= N; i++) vis[i] = 0;
        dfs_init(u, v);
        int curr = 0;
        for (auto root : {u, v}){
            res = 2e9;
            dfs1(root, 0);
            dfs2(root, 0);
            curr += res;
            for (int i = 1; i <= N; i++) vis[i] ^= 1;
        }
        ans = min(ans, curr);
    }
    cout << ans << endl;
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

#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second

const int N_Max = 2e5 + 5;
const ll mod = 4294967296;
const int LOG = 19;

struct Query{
    int id, l, r, lc;
};

vector<int> adj[N_Max];
ll C[N_Max], H[N_Max];
int up[N_Max][LOG];
Query qry[N_Max];
int depth[N_Max];
ll sum[N_Max][2];
int freq[N_Max];
int tour[N_Max];
int tout[N_Max];
int occ[N_Max];
int tin[N_Max];
ll ans[N_Max];
int timer = 0;
ll curr, tot;
int lo, ro;
ll tot_sq;
int N, Q;
int cnt;

ll add(ll a, ll b){
    return (a + b) % mod;
}

ll sub(ll a, ll b){
    return (a - b + mod) % mod;
}

ll mult(ll a, ll b){
    return a * b % mod;
}

void dfs_init(int Node, int par){
    up[Node][0] = par;
    for (int i = 1; i < LOG; i++)
        up[Node][i] = up[up[Node][i - 1]][i - 1];
    tour[++timer] = Node;
    tin[Node] = timer;
    for (int child : adj[Node]){
        if (child == par) continue;
        depth[child] = 1 + depth[Node];
        dfs_init(child, Node);
    }
    tour[++timer] = Node;
    tout[Node] = timer;
}

int get_lca(int u, int v){
    if (depth[u] > depth[v]) swap(u, v);
    int l = depth[v] - depth[u];
    for (int i = LOG - 1; i >= 0; i--)
        if (l & (1 << i)) v = up[v][i];
    assert(depth[u] == depth[v]);
    for (int i = LOG - 1; i >= 0; i--){
        if (up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return u == v ? u : up[u][0];
}

void work_add(int u){
    curr = add(curr, mult(mult(H[u], H[u]), (cnt - occ[C[u]])));
    curr = add(curr, sub(tot_sq, sum[C[u]][1]));
    curr = sub(curr, mult(2, mult(H[u], sub(tot, sum[C[u]][0]))));
    occ[C[u]]++;
    sum[C[u]][0] = add(sum[C[u]][0], H[u]);
    sum[C[u]][1] = add(sum[C[u]][1], mult(H[u], H[u]));
    cnt++;
    tot = add(tot, H[u]);
    tot_sq = add(tot_sq, mult(H[u], H[u]));
}

void work_rmv(int u){
    cnt--;
    tot = sub(tot, H[u]);
    tot_sq = sub(tot_sq, mult(H[u], H[u]));
    occ[C[u]]--;
    sum[C[u]][0] = sub(sum[C[u]][0], H[u]);
    sum[C[u]][1] = sub(sum[C[u]][1], mult(H[u], H[u]));
    curr = sub(curr, mult(mult(H[u], H[u]), (cnt - occ[C[u]])));
    curr = sub(curr, sub(tot_sq, sum[C[u]][1]));
    curr = add(curr, mult(2, mult(H[u], sub(tot, sum[C[u]][0]))));
}

void add(int ind){
    int u = tour[ind];
    freq[u] ^= 1;
    if (freq[u] & 1) work_add(u);
    else work_rmv(u);
}

void rmv(int ind){
    int u = tour[ind];
    freq[u] ^= 1;
    if (freq[u] & 1) work_add(u);
    else work_rmv(u);
}

void update(int id){
    while (ro < qry[id].r) add(++ro);

    while (lo > qry[id].l) add(--lo);
    
    while (ro > qry[id].r) rmv(ro--);
    
    while (lo < qry[id].l) rmv(lo++);
}

void mo(){
    int B = sqrt(2 * N);
    sort(qry + 1, qry + Q + 1, [B](Query a, Query b){return make_pair(a.l / B, a.r) < make_pair(b.l / B, b.r);});
    lo = 1, ro = 0, tot = 0, tot_sq = 0, curr = 0, cnt = 0;
    for (int i = 1; i <= Q; i++){
        update(i);
        ans[qry[i].id] = curr;
        if (qry[i].lc != -1){
            ans[qry[i].id] = add(ans[qry[i].id], mult(mult(H[qry[i].lc], H[qry[i].lc]), (cnt - occ[C[qry[i].lc]])));
            ans[qry[i].id] = add(ans[qry[i].id], sub(tot_sq, sum[C[qry[i].lc]][1]));
            ans[qry[i].id] = sub(ans[qry[i].id], mult(2, mult(H[qry[i].lc], sub(tot, sum[C[qry[i].lc]][0]))));
        }
    }
}

void solve(){
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> C[i];
    for (int i = 1; i <= N; i++) cin >> H[i];
    for (int i = 1; i < N; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs_init(1, 1);
    for (int q = 1; q <= Q; q++){
        int u, v;
        cin >> u >> v;
        if (tin[u] > tin[v]) swap(u, v);
        int lc = get_lca(u, v);
        if (lc != u) qry[q] = {q, tout[u], tin[v], lc};
        else qry[q] = {q, tin[u], tin[v], -1};
    }
    mo();
    for (int q = 1; q <= Q; q++)
        cout << ans[q] << endl;
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

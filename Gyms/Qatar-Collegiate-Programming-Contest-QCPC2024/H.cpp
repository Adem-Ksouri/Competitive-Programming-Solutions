#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second

const int N_Max = 150;

vector<array<int, 3>> edges;
double dist[N_Max][N_Max];
vector<int> adj[N_Max];
int x[N_Max];
int y[N_Max];
int N, K, M;

double get_dist(int i, int j){
    return sqrt(abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j])); 
}

void dijkstra(int s){
    for (int i = 1; i <= N; i++) dist[s][i] = 2e9;
    set<pair<double, int>> st;
    st.insert({0, s});
    dist[s][s] = 0;
    while (!st.empty()){
        auto [d, Node] = *st.begin();
        st.erase(st.begin());
        if (dist[s][Node] < d) continue;
        for (int child : {Node % N + 1, (Node - 2 + N) % N + 1}){
            double cost = d + get_dist(Node, child);
            if (cost < dist[s][child]){
                dist[s][child] = cost;
                st.insert({cost, child});
            }
        }
        for (int child : adj[Node]){
            double cost = d + get_dist(Node, child);
            if (cost < dist[s][child]){
                dist[s][child] = cost;
                st.insert({cost, child});
            }
        }
    }
}

bool work(){
    for (int i = 1; i <= N; i++)
        dijkstra(i);
    double mx = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            mx = max(mx, dist[i][j]);
    return mx <= M;
}

void solve(){
    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < K; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
    ll ans = 1e18;
    for (int mask = 0; mask < (1 << K); mask++){
        for (int i = 1; i <= N; i++) adj[i].clear();
        ll curr = 0;
        for (int i = 0; i < K; i++){
            if (mask & (1 << i)){
                auto [u, v, c] = edges[i];
                adj[u].pb(v);
                adj[v].pb(u);
                curr += c;
            }
        }
        if (work()) ans = min(ans, curr);
    }
    cout << (ans < 1e18 ? ans : -1) << endl;
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

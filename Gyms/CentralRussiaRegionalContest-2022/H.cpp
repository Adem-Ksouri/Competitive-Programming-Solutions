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
const int N_Max = 1e3 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dp[N_Max][N_Max][4];
char a[N_Max][N_Max];
int cost[4][4];
int N, M, l, r, f, t;

bool in_bound(int r, int c){
	return r >= 1 && r <= N && c >= 1 && c <= M;
}

void dijkstra(int i, int j){
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			for (int d = 0; d < 4; d++)
				dp[i][j][d] = 2e9;
	set<array<int, 4>> s;
	s.insert({0, i, j, 2});
	dp[i][j][2] = 0;
	while (!s.empty()){
		auto [dist, r, c, d] = *s.begin();
		s.erase(s.begin());
		if (dp[r][c][d] < dist) continue;
		for (int x = 0; x < 4; x++){
			if (dist + cost[d][x] < dp[r][c][x]){
				dp[r][c][x] = dist + cost[d][x];
				s.insert({dp[r][c][x], r, c, x});
			}
			int new_r = r + dx[x], new_c = c + dy[x];
			if (!in_bound(new_r, new_c) || a[new_r][new_c] == '#') continue;
			int val = cost[d][x] + f;
			if (dist + val < dp[new_r][new_c][x]){
				dp[new_r][new_c][x] = dist + val;
				s.insert({dp[new_r][new_c][x], new_r, new_c, x});
			}
		}
	}
}

int get(int d){
	if (d == 0) return 2;
	if (d == 1) return 3;
	if (d == 3) return 1;
	return 0;
}

void solve(){
	cin >> N >> M >> l >> r >> f >> t;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) cin >> a[i][j];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (i == j) continue;
			int diff = abs(i - j);
			if (i < j) cost[i][j] = min(r * diff, (4 - diff) * l);
			else cost[i][j] = min(l * diff, (4 - diff) * r);
		}
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (a[i][j] == 'V') dijkstra(i, j);
	int ans = 2e9;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (a[i][j] != '*') continue;
			for (int d = 0; d < 4; d++){
				int r = i + dx[d], c = j + dy[d];
				if (in_bound(r, c) && a[r][c] != '#')
					ans = min(ans, dp[r][c][get(d)]);
			}
		}
	}
	cout << (ans <= t ? "YES" : "NO") << endl;
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

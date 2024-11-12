/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int ll
#define endl '\n'

const int N = 505;

int r[N][N], c[N][N], cost[N][N];

map<vector<pair<int,int>>,int> vis, mn;

void Solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> r[i][j] >> c[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        if (i) cost[i][0] = cost[i - 1][0] - r[i][0];

        for (int j = 1; j < m; j++) {
            cost[i][j] = cost[i][j - 1] + c[i][j];
        }

        if (cost[i][m - 1] - cost[i][0] != -c[i][0]) return void(cout << "No\n");
    }

    for (int j = 0; j < m; j++) {
        if (cost[0][j] - cost[n - 1][j] != -r[0][j]) return void(cout << "No\n");
    }

    cout << "Yes\n";


}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    ll Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}


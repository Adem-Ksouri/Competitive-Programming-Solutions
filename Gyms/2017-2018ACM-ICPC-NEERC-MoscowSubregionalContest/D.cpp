/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int __int128
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

void Solve() {
    ll n;
    cin >> n;
    int curr = 0, base = 1;
    vector<ll> v(n);


    for (auto& x : v) cin >> x;
    for (auto x : v) {
        if (x < 128) {
            curr += base * x;


            if (curr % 2) curr = -(curr + 1) / 2;
            else curr = curr / 2;

            cout << (ll)(curr) << endl;
            curr = 0;
            base = 1;
        } else {
            curr += base * (x - 128);
            base *= (1 << 7);
        }


    }

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


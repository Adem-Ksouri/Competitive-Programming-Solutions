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

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int mex(vector<int> p) {
    sort(all(p));
    for (int i = 1; i <= p.size() + 2; i++) if (i != p[i]) return i;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> p1(n), p2(n);
    vector<int> pref(n + 4), suff(n + 4);
    for (int i = 1; i < n; i++) cin >> p1[i];
    for (int i = 1; i < n; i++) cin >> p2[i];

    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + abs(p1[i] - p2[i]);
    for (int i = n - 1; i >= 1; i--) suff[i] = suff[i + 1] + abs(p1[i] - p2[i]);
    int rem1 = mex(p1), rem2 = mex(p2);


    array<int, 3> ans1{-1, -1, -1}, ans2{-1, -1, -1};


    pair<int,int> mx{-1, -1};
    for (int i = 1; i < n; i++) {
        if (i - 1 >= 1) mx.F += abs(p1[i] - p2[i - 1]);
        int curr = abs(rem1 - p2[i]) + suff[i + 1] + mx.F;


        if (curr >= ans1[0]) {
            ans1[0] = curr;
            ans1[1] = i;
            ans1[2] = mx.S;
        }

        int pot = abs(rem2 - p1[i]) + pref[i - 1];
        if (pot >= mx.F) {
            mx.F = pot;
            mx.S = i;
        }
    }

    swap(p1, p2);
    swap(rem1, rem2);

    mx = {-1, -1};
    for (int i = 1; i < n; i++) {
        if (i - 1 >= 1) mx.F += abs(p1[i] - p2[i - 1]);
        int curr = abs(rem1 - p2[i]) + suff[i + 1] + mx.F;


        if (curr >= ans2[0]) {
            ans2[0] = curr;
            ans2[2] = i;
            ans2[1] = mx.S;
        }

        int pot = abs(rem2 - p1[i]) + pref[i - 1];
        if (pot >= mx.F) {
            mx.F = pot;
            mx.S = i;
        }
    }

    swap(p1, p2);
    swap(rem1, rem2);


    if (abs(rem1 - rem2) + pref[n - 1] >= ans1[0]) {
        ans1[0] = abs(rem1 - rem2) + pref[n - 1];
        ans1[1] = ans1[2] = n;
    }
    if (abs(rem1 - rem2) + pref[n - 1] >= ans2[0]) {
        ans2[0] = abs(rem1 - rem2) + pref[n - 1];
        ans2[1] = ans2[2] = n;
    }

    if (ans1[0] >= ans2[0]) {
        cout << ans1[0] << endl;
        for (int i = 1; i < n; i++) {
            cout << p1[i] << " ";
            if (ans1[1] == i) cout << rem1 << " ";
        }

        if (ans1[1] == n) cout << rem1 << " ";
        cout << endl;

        for (int i = 1; i < n; i++) {
            if (ans1[2] == i) cout << rem2 << " ";
            cout << p2[i] << " ";
        }
        if (ans1[2] == n) cout << rem2 << " ";
        cout << endl;

    } else {
        cout << ans2[0] << endl;
        for (int i = 1; i < n; i++) {
            if (ans2[1] == i) cout << rem1 << " ";
            cout << p1[i] << " ";
        }

        if (ans2[1] == n) cout << rem1 << " ";
        cout << endl;

        for (int i = 1; i < n; i++) {
            cout << p2[i] << " ";
            if (ans2[2] == i) cout << rem2 << " ";
        }
        if (ans2[2] == n) cout << rem2 << " ";
        cout << endl;

    }

}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    // cin >> Test_case;
    while (Test_case--) Solve();
}


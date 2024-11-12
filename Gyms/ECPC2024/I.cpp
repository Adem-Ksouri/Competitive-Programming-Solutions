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
#pragma gcc optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

int binpow(int a, int k, int res = 1,int Mod = mod) {
    while (k) {
        if (k % 2) res = (res * a) % Mod;
        a = (a * a) % Mod;
        k /= 2;
    }
    return res;
}

int modinv(int a,int Mod = mod) { return binpow(a, Mod - 2); }
int mult(int a, int b,int Mod = mod) {
    b %= Mod;
    return a % Mod * b % Mod;
}

int add(int a, int b,int Mod = mod) { return ((a % Mod + b % Mod) % Mod + Mod) % Mod; }
int divide(int a, int b,int Mod = mod) {
    a %= Mod;
    b = modinv(b) % Mod;
    return (a * b) % Mod;
}


const int B1 = 9947, B2 = 1e9 + 3;
int pref[2][N], suff[2][N], n;

void Hash(string& s) {
    n = s.size();
    for (int i = 1; i <= n; i++) {
        pref[0][i] = add(pref[0][i - 1], mult(s[i], binpow(B1, i)));
        pref[1][i] = add(pref[1][i - 1], mult(s[i], binpow(B2, i)));
    }
    suff[0][n + 1] = suff[1][n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suff[0][i] = add(suff[0][i + 1], mult(s[i], binpow(B1, n - i)));
        suff[1][i] = add(suff[1][i + 1], mult(s[i], binpow(B2, n - i)));
    }
}

int base[2][N];

pair<int, int> getHashpref(int l, int r) {
    pair<int, int> ret;
    ret.F = add(pref[0][r], -pref[0][l - 1]);
    ret.F = mult(ret.F, base[0][l]);

    ret.S = add(pref[1][r], -pref[1][l - 1]);
    ret.S = mult(ret.S, base[1][l]);
    return ret;
}

pair<int, int> getHashsuff(int l, int r) {
    pair<int, int> ret;

    int puiss = n - r + 1;
    ret.F = add(suff[0][l], -suff[0][r + 1]);
    ret.F = mult(ret.F, base[0][puiss - 1]);

    ret.S = add(suff[1][l], -suff[1][r + 1]);
    ret.S = mult(ret.S, base[1][puiss - 1]);
    return ret;
}

bool is_palindrome(int l, int r) {
    pair<int, int> pr = getHashpref(l, r);
    pair<int, int> suf = getHashsuff(l, r);
    return pr == suf;
}

template <class T> struct Seg { /*CHANGE THE ID YA KARIM !!*/
    const T ID = 0;
    int n;
    vector<T> seg;
    T merge(T a, T b) { return a | b; }
    Seg(int _n) { n = _n, seg.assign(2 * n, ID); }
    void pull(int p) { seg[p] = merge(seg[2 * p], seg[2 * p + 1]); }
    void print(int i = -1) { while (++i < n) cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " "); }

    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }

    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ra = merge(ra, seg[l++]);
            if (r & 1) rb = merge(seg[--r], rb);
        }
        return merge(ra, rb);
    }
};


void Solve() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    s = "#" + s;

    Seg<int> sg(n + 1);
    Hash(s);
    vector<int> v(n + 1), pos(31, INF), pref(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];


    for (int i = 1; i <= n; i++) {
        sg.upd(i, v[i]);
        pref[i] += pref[i - 1] + v[i];

        for (int j = 0; j < 30; j++) {
            if ((1 << j) & v[i]) pos[j] = i;

            if (pos[j] <= i && is_palindrome(pos[j], i) && pref[i] - pref[pos[j] - 1] == sg.query(pos[j], i)) ans = max(ans, i - pos[j] + 1);

        }

    }
    cout << ans << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    for (int i = 0; i < N; i++) {
        base[0][i] = divide(1, binpow(B1, i));
        base[1][i] = divide(1, binpow(B2, i));
    }
    while (Test_case--) Solve();
}


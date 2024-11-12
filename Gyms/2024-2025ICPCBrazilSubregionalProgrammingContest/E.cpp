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
const int N_Max = 2e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}


void solve(){
    int N;
    cin >> N;
    vector<vector<int>> a(N + 1, vector<int>(N + 1));
    vector<vector<int>> b(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) cin >> a[i][j];
    for (int rep = 0; rep < 4; rep++){
        bool good = true;
        for (int i = 1; i <= N; i++){
            bool good_row = true;
            for (int j = 2; j <= N; j++){
                if (a[i][j] <= a[i][j - 1]) good = false;
                if (a[j][i] <= a[j - 1][i]) good = false;
            }
        }
        if (good){
            cout << rep << endl;
            return;
        }
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                b[N - j + 1][i] = a[i][j];
        a.swap(b);
    }
    assert(false);
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

#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second

ll get_power(ll x, ll y){
    ll ret = 1;
    for (int i = 0; i < y; i++) ret *= x;
    return ret;
}

void solve(){
    int N;
    cin >> N;
    vector<pair<int, int>> a(N), vec;
    for (int i = 0; i < N; i++) cin >> a[i].F >> a[i].S;
    for (auto [p, c] : a){
        pair<int, int> best = {0, c};
        for (int x = 1; x <= 20; x++){
            for (int y = 1; y <= x; y++){
                if (__gcd(x, y) != c) continue;
                if (x < best.S) best = {y, x};
                else if (x == best.S && y < best.F) best = {y, x};
            }
        }
        vec.push_back(best);
    }
    ll ans = 1e18;
    for (int mask = 0; mask < (1 << N); mask++){
        ll x = 1, y = 1;
        for (int i = 0; i < N; i++){
            auto [c1, c2] = vec[i];
            if (mask & (1 << i)) x *= get_power(a[i].F, c1), y *= get_power(a[i].F, c2);
            else y *= get_power(a[i].F, c1), x *= get_power(a[i].F, c2);
        }
        ans = min(ans, max(x, y));
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

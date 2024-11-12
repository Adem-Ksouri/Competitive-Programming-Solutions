#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second

const int N_Max = 2e5 + 5;
const double eps = 1e-6;

int x[N_Max], y[N_Max];
int N;

double get_dist(double x1, double y1, double x2, double y2){
    return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}

double work(double c){
    double ret = 0;
    for (int i = 1; i <= N; i++)
        ret = max(ret, get_dist(c, c, x[i], y[i]));
    return ret;
}

void solve(){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
    double l = -1e7, r = 1e7;
    while (r - l > eps){
        double c1 = l + (r - l) / 3;
        double c2 = r - (r - l) / 3;
        if (work(c1) < work(c2)) r = c2;
        else l = c1;
    }
    cout << work(l) << endl;
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cout << fixed << setprecision(6);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

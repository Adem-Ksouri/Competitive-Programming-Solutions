#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    long long r, s, x;
    cin >> r >> s >> x;

    long long ans = (s * s * x + r * r - 1) / (r * r);

    // (a / b)[rounded up] = (a + b - 1) / b

    while(ans % 10 != 0) ans++;

    cout << ans << endl;
}

int main()
{
    FAST
    int t = 1;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}


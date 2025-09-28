#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << min({a, b, c}) << endl;
}

int main()
{
    FAST
    int t = 1;
    // cin >> t;

    while(t--)
        solve();
    
    return 0;
}


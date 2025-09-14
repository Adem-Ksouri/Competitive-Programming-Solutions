#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    if(a + b + c > n) {
        cout << "-1" << endl;
        return;
    }

    set<pair<int, char>> st;
    st.insert({a, 'R'});
    st.insert({b, 'G'});
    st.insert({c, 'B'});
    int s = a + b + c;
    while(s < n){
        auto [mn, c] = *st.begin();
        st.erase(st.begin());
        mn++;
        st.insert({mn, c});
        s++;
    }

    vector<pair<int, char>> vec = vector<pair<int, char>>(st.rbegin(), st.rend());
    
    if(vec[1].first + vec[2].first < vec[0].first - 1) {
        cout << "-1" << endl;
        return;
    }

    vector<string> blocks(vec[0].first);
    int idx = 0;
    for(auto [cnt, c] : vec) {
        while(cnt > 0) {
            blocks[idx++] += c;
            if(idx == vec[0].first)
                idx = 0;
            cnt--; 
        }
    }
    for(string s : blocks)
        cout << s;
    cout << endl;
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

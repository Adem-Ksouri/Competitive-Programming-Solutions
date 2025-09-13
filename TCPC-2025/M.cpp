#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mod = 1e9 + 7;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 
const int N = 505;
const int B = 25;
int dp[N][N][B][2];
int n, m;
string t;

int add(int u, int v) {
    u += v;
    if(u >= mod) u -= mod;
    return u;
}

int mult(int u, int v) {
    return u * 1ll * v % mod;
}

int sub(int u, int v) {
    u -= v;
    if(u < 0) u += mod;
    return u;
}

void solve() {
    cin >> n >> m >> t;
    t = "#" + t;

    set<char> vowels = {'a', 'e', 'i', 'o','u'};
    set<char> cons;
    for(char c = 'a'; c <= 'z'; c++)
        if(vowels.find(c) == vowels.end()) cons.insert(c);
    
    dp[0][0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int v = 0; v + 1 < B; v++){
            for(int flag = 0; flag < 2; flag++){
                if(!flag) 
                    dp[i][m][v + 1][1] = add(dp[i][m][v + 1][1], mult(5, dp[i - 1][m][v][flag]));
                dp[i][m][v][0] = add(dp[i][m][v][0], mult(21, dp[i - 1][m][v][flag]));
            }
        }
        for(int len = 0; len < m; len++){
            for(int v = 0; v + 1 < B; v++){
                for(int flag = 0; flag < 2; flag++){
                    if(vowels.find(t[len + 1]) != vowels.end()) {
                        if(!flag){
                            dp[i][len + 1][v + 1][1] = add(dp[i][len + 1][v + 1][1], dp[i - 1][len][v][flag]);
                            dp[i][len][v + 1][1] = add(dp[i][len][v + 1][1], mult(4, dp[i - 1][len][v][flag]));
                        }
                        dp[i][len][v][0] = add(dp[i][len][v][0], mult(21, dp[i - 1][len][v][flag]));
                    }else {
                        dp[i][len + 1][v][0] = add(dp[i][len + 1][v][0], dp[i - 1][len][v][flag]);
                        dp[i][len][v][0] = add(dp[i][len][v][0], mult(20, dp[i - 1][len][v][flag]));
                        if(!flag) 
                            dp[i][len][v + 1][1] = add(dp[i][len][v + 1][1], mult(5, dp[i - 1][len][v][flag]));
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int v = 0; v < B; v++){
        int c = n - v;
        if(v * v <= c) {
            for(int flag = 0; flag < 2; flag++)
                ans = add(ans, dp[n][m][v][flag]);
        }
    }

    cout << ans << endl;
}

int main()
{
    FAST
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}


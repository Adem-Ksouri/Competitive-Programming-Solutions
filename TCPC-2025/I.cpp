#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
const int mod = 1e9 + 7;
const long double EPS = 1e-10;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}
 

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve() {
    int n, k;
    cin >> n >> k; 
    
    vector<int> a(n);
    vector<int> id(n);

    for (auto &x : a) cin >> x;    

    int lst = 0;
    for(int i = 0; i < n; i++)
        if(a[i] % (k + 1))
            a[i] = 1, id[i] = lst++;
        else 
            a[i] = 0;
    
    vector<ll> Pl(n + 5), Pr(n + 5);

    int cnt_z = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) cnt_z++;
        else {
            Pl[-id[i] + n] = cnt_z + 1;
            cnt_z = 0;
        }
    }
    
    cnt_z = 0;
    for(int i = n - 1; i >= 0; i--)
        if(a[i] == 0) cnt_z++;
        else {
            Pr[id[i] + 1] = cnt_z + 1;
            cnt_z = 0;
        }

    vector<ll> ret = multiply(Pl, Pr);

    for(int i = n + 1; i <= 2 * n; i++)
        cout << ret[i] << " ";
    cout << endl;
}

int main(){
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

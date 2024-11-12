#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second

const int N_Max = 1e6 + 5;

template<class T> struct Seg{
    const T ID = 0; ll n; vector<T> seg;
    T comb(T a, T b){return (a ^ b);}
    void init(ll _n){n = _n; seg.assign(2 * n, ID);}
    void pull(ll p){seg[p] = comb(seg[2 * p], seg[2 * p + 1]);}
    void upd(ll p, T val){seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p);}
    T query(ll l, ll r){
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

template<class T> struct Seg1{
    const T ID = 0; ll n; vector<T> seg;
    T comb(T a, T b){return max(a, b);}
    void init(ll _n){n = _n; seg.assign(2 * n, ID);}
    void pull(ll p){seg[p] = comb(seg[2 * p], seg[2 * p + 1]);}
    void upd(ll p, T val){seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p);}
    T query(ll l, ll r){
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

Seg<int> st_xor;
Seg1<int> st_mx;
int a[N_Max];
int N, Q;

int work(int l, int r){
    int x = st_xor.query(l, r);
    int mx = st_mx.query(l, r);
    if (mx <= 1) return x == 0;
    return x != 0;
}

void solve(){
    cin >> N;
    st_mx.init(N + 5);
    st_xor.init(N + 5);
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        st_xor.upd(i, a[i]);
        st_mx.upd(i, a[i]);
    }
    cin >> Q;
    for (int q = 1; q <= Q; q++){
        int l, r, A, B;
        cin >> l >> r >> A >> B;
        if (A > B){
            cout << "Wageeh" << endl;
            continue;
        }
        if (B > A){
            cout << "Mousa" << endl;
            continue;
        }
        int state = work(l, r);
        if (state) cout << "Wageeh" << endl;
        else cout << "Mousa" << endl;
    }
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

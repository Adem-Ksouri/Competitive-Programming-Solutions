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
const int N_Max = 1e5 + 7;
const int Nax = 15;
const int LOG = 18;
const int BITS = 30;
const int ALPHA = 26;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
ll inv(ll N) {if (N == 1) return 1; return (mod - ((mod / N) * inv(mod % N)) % mod) % mod;}

const int B = 19;

struct Node{
    int base[B];
};

Node st[4 * N_Max];
set<int> s[B];
int a[N_Max];
int N, Q;

void ins(int x, Node& u){
    if (x == -1) return;
    for (int i = B - 1; i >= 0; i--){
        int c = (x >> i) & 1;
        if (!c) continue;
        if (u.base[i] == -1){
            u.base[i] = x;
            break;
        }
        else x ^= u.base[i];
    }
}

Node merge(Node l, Node r){
    Node ret;
    memset(ret.base, -1, sizeof(ret.base));
    for (int i = 0; i < B; i++)
        ins(l.base[i], ret);
    for (int i = 0; i < B; i++)
        ins(r.base[i], ret);
    return ret;
}

void build(int id, int ns, int ne){
    if (ns == ne){
        memset(st[id].base, -1, sizeof(st[id].base));
        ins(a[ns], st[id]);
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    build(lc, ns, mid);
    build(rc, mid + 1, ne);
    st[id] = merge(st[lc], st[rc]);
}

void update(int id, int ns, int ne, int ind){
    if (ind < ns || ind > ne) return;
    if (ns == ne){
        memset(st[id].base, -1, sizeof(st[id].base));
        ins(a[ns], st[id]);
        return;
    }
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    update(lc, ns, mid, ind);
    update(rc, mid + 1, ne, ind);
    st[id] = merge(st[lc], st[rc]);
}

Node query(int id, int ns, int ne, int l, int r){
    if (ns >= l && ne <= r) return st[id];
    int mid = ns + (ne - ns) / 2;
    int lc = 2 * id;
    int rc = 2 * id + 1;
    if (r <= mid) return query(lc, ns, mid, l, r);
    if (l > mid) return query(rc, mid + 1, ne, l, r);
    return merge(query(lc, ns, mid, l, r), query(rc, mid + 1, ne, l, r));
}

void add(int ind){
    for (int i = 0; i < B; i++)
        if (a[ind] & (1 << i))
            s[i].insert(ind);
}

void rmv(int ind){
    for (int i = 0; i < B; i++)
        if (a[ind] & (1 << i))
            s[i].erase(ind);
}

void solve(){
    cin >> N >> Q;
    for (int i = 0; i < B; i++) s[i].clear();
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) add(i);
    build(1, 1, N);
    for (int q = 1; q <= Q; q++){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            set<int> upd;
            for (int i = 0; i < B; i++){
                if (x & (1 << i)) continue;
                for (auto it = s[i].lower_bound(l); it != s[i].end(); it++){
                    if (*it > r) break;
                    upd.insert(*it);
                }
            }
            for (auto ind : upd){
                rmv(ind);
                a[ind] &= x;
                add(ind);
                update(1, 1, N, ind);
            }
        }
        else if (t == 2){
            int ind, x;
            cin >> ind >> x;
            rmv(ind);
            a[ind] = x;
            add(ind);
            update(1, 1, N, ind);
        }
        else{
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, N, l, r);
            int ans = 0;
            for (int i = B - 1; i >= 0; i--){
                if (res.base[i] == -1) continue;
                if (ans & (1 << i)) continue;
                ans ^= res.base[i];
            }
            cout << ans << endl;
        }
    }
}

int main(){
    FAST
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}

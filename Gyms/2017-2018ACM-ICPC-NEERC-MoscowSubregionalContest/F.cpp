#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define pb(n) push_back(n)
#define F first
#define S second

const int N_Max = 1005;
const int Nax = 30;

int lst_submission[N_Max][Nax];
int submissions[N_Max][Nax];
char verdict[N_Max][Nax];
string name[N_Max];
int vis[N_Max];
int id[N_Max];
int N, M, K;

bool cmp(int i, int j){
    int lst1 = -1, lst2 = -1;
    int solved1 = 0, solved2 = 0;
    int penalty1 = 0, penalty2 = 0;
    for (int p = 1; p <= N; p++){
        if (verdict[i][p] == '+'){
            solved1++;
            lst1 = max(lst1, lst_submission[i][p]);
            penalty1 += lst_submission[i][p] + (submissions[i][p] - 1) * 20;
        }

        if (verdict[j][p] == '+'){
            solved2++;
            lst2 = max(lst2, lst_submission[j][p]);
            penalty2 += lst_submission[j][p] + (submissions[j][p] - 1) * 20;
        }
    }
    if (solved1 != solved2) return solved1 > solved2;
    if (penalty1 != penalty2) return penalty1 < penalty2;
    if (lst1 != lst2) return lst1 < lst2;
    return name[i] < name[j];
}

void solve(){
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++){
        cin >> name[i];
        for (int j = 1; j <= N; j++)
            cin >> verdict[i][j] >> submissions[i][j] >> lst_submission[i][j];
    }
    for (int i = 1; i <= K; i++){
        string s;
        cin >> s;
        int ind = 0;
        for (int j = 1; j <= M; j++){
            if (name[j] == s){
                ind = j;
                break;
            }
        }
        vis[ind]++;
        assert(ind > 0);
        for (int j = 1; j <= N; j++)
            cin >> verdict[ind][j] >> submissions[ind][j] >> lst_submission[ind][j];
    }
    for (int i = 1; i <= M; i++) id[i] = i;
    sort(id + 1, id + M + 1, cmp);
    int l = -1, r = -1;
    for (int i = 1; i <= M; i++){
        if (!vis[id[i]]) continue;
        if (l == -1) l = i;
        r = i;
    }
    bool good = false;
    for (int i = 1; i <= N; i++)
        if (verdict[id[l]][i] != '+') good = true;
    if (good){
        cout << "Leaked" << endl;
        return;
    }
    int penalty1 = 0, lst1 = -1;
    for (int i = 1; i <= N; i++){
        lst1 = max(lst1, lst_submission[id[l]][i]);
        penalty1 += lst_submission[id[l]][i] + (submissions[id[l]][i] - 1) * 20;
    }
    for (int i = l; i <= r; i++){
        if (vis[id[i]]) continue;
        int penalty2 = 0, lst2 = -1;
        for (int p = 1; p <= N; p++){
            if (verdict[id[i]][p] != '+'){
                submissions[id[i]][p]++;
                lst_submission[id[i]][p] = 240;
            }
            lst2 = max(lst2, lst_submission[id[i]][p]);
            penalty2 += lst_submission[id[i]][p] + (submissions[id[i]][p] - 1) * 20;
        }
        if (penalty2 < penalty1) continue;
        if (penalty2 > penalty1){
            cout << "Fake" << endl;
            return;
        }
        if (lst2 < lst1) continue;
        if (lst2 > lst1){
            cout << "Fake" << endl;
            return;
        }
        if (name[id[l]] < name[id[i]]){
            cout << "Fake" << endl;
            return;
        }
    }
    cout << "Leaked" << endl;
}

int main(){
    FAST
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}

#include "bits/stdc++.h"
#define int long long
#define pii pair <int, int>
#define fi first
#define se second

using namespace std;

int RAND() {
    return (rand() % 1000000000 + 12) * 1235LL % 123152 * 3242344543241;
}

vector <int> id;
vector <vector <int>> save;
int pos[500];
int choose[500];
int truepos[500], have[500];
bool used[500];
int test, ans;
string s[500];
void gen_case(int i) {
    if (i == 4) {
        save.push_back(id);
        return;
    }
    for (int choose = 1 ; choose <= 6 ; choose++)
        if (used[choose] == 0) {
            used[choose] = 1;
            id[i] = choose;
            gen_case(i+1);
            used[choose] = 0;
        }
}

pii OUT(int ans, int t) {

    for (int i = 1 ; i <= 6 ; i++)
        pos[i] = 0;

    for (int i = 0 ; i < 4 ; i++)
        pos[save[ans][i]] = i+1;

    int have = 0, truepos = 0;
    for (int i = 0 ; i < 4 ; i++) {
        have += (pos[save[t][i]] != 0);
        truepos += (pos[save[t][i]] == i+1);
    }
    return pii(truepos, have-truepos);
}


void IN(int x) {

    if (x == -1) {
        for (int i = 0 ; i < 4 ; i++)
            cout << 0 << " ";
            return;
    }
    for (int i = 0 ; i < 4 ; i++)
        cout << save[x][i] << " ";
    cout << " ";

}
void INTABLE() {

    system("cls");
    for (int test = 6 ; test >= 1 ; test--) {
        IN(choose[test]);
        if (s[test].size()) cout << "   " << s[test];
        cout << "\n"; 
    }
}
signed main() {

    srand(time(NULL));
    id.resize(4);
    gen_case(0);


    for (int test = 1 ; test <= 6 ; test++) choose[test] = -1;

    for (test = 1 ; test <= 6 ; test++) {

        vector <int> pos;
        for (ans = 0 ; ans < 360 ; ans++) {
            bool ok = 1;
            for (int t = 1 ; t < test ; t++)
                if (OUT(ans, choose[t]) != pii(truepos[t], have[t])) ok = 0;

            if (ok) {
                pos.push_back(ans);
            }
        }

        choose[test] = pos[0];
        INTABLE();
        getline(cin, s[test]);
        
        for (char c : s[test]) {
            truepos[test] += (c == 'x');
            have[test] += (c == 'o');
        }
        if (truepos[test] == 4) {
            INTABLE();
            cout << "WINNNNN";
            return 0;
        }

    }
    cout << -1;
    return 0;
}
